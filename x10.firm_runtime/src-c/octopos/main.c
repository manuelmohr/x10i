#include <octopos.h>
#include "ilocal_data.h"
#include "main.h"
#include "places.h"
#include "agent.h"
#include "places_octopos.h"
#include "serialization.h"
#include "xmalloc.h"
#ifndef NO_GARBAGE_COLLECTION
#include <gc.h>
#endif

/* The SHM heap address space on the CHIPit begins at address 0x0, which
 * means a lot of regular integer values look like valid pointers.  This
 * is extremely bad for conservative garbage collection.  To improve the
 * situation at least a little, we reserve and throw away the smallest
 * addresses. */
#define MEMORY_WASTE_BYTES (1024 * 1024)

typedef struct distribute_places_context {
	dispatch_claim_t *places;
	int n_places;
	simple_signal *signal;
	unsigned place_id;
} distribute_places_context;

typedef struct place_local_data {
	dispatch_claim_t *places;
	unsigned n_places;
	unsigned place_id;
} place_local_data;

static simple_signal initialization_signal;

static void ilet_notify(void *arg)
{
	simple_signal_signal((simple_signal*)arg);
}

/** initialization code that is run once on each tile before it is used. */
static void init_tile()
{
	/* Reserve dedicated NoC channel to I/O tile.  This prevents packets from
	 * overtaking each other and reponses from arriving in an order that
	 * violates program order. */
	if (reserve_vc(get_io_tile_id(), 1) == -1) {
		panic("Reservation of dedicated NoC channel to I/O tile failed");
	}
	gc_init();
#ifndef NO_GARBAGE_COLLECTION
	/* immediately expand boehm heap usage to three quarters of the heap as we
	 * currently don't have any other applications competing for it. */
	const size_t total_mem_per_tile = mem_get_total_page_count(MEM_SHM) * mem_get_page_size();
	const size_t start_size         = (total_mem_per_tile / 4) * 3;
	if (GC_expand_hp(start_size) == 0) {
		panic("Could not reserve initial memory amount for GC");
	}
#endif
	x10_static_initializer();
	x10_serialization_init();
}

static void ilet_dma_local_finish(void *context)
{
	distribute_places_context *dpc  = context;
	simple_signal_signal(dpc->signal);
	mem_free_tlm(dpc);
}

static void ilet_dma_remote_finish(void *pid)
{
	claim_t cl = get_claim();
	assert (cl != 0 && "stack overflow maybe?");
	place_local_data *pld = claim_get_local_data(cl);
	pld->place_id = (unsigned)pid;
}

static void ilet_init_tile(void *init_signal)
{
	init_tile();
	simple_ilet notification_ilet;
	simple_ilet_init(&notification_ilet, ilet_notify, init_signal);
	dispatch_claim_send_reply(&notification_ilet);
}

/** shutdown code that is run on each tile before exiting. */
static void shutdown_tile()
{
	guest_shutdown();
}

static void ilet_transfer_places(void *remote_places, void *context)
{
	distribute_places_context *dpc  = context;
	dispatch_claim_t remote_claim   = get_parent_dispatch_claim();
	buf_size_t       size           = (dpc->n_places) * sizeof(dispatch_claim_t);

	simple_ilet ilet_local;
	simple_ilet_init(&ilet_local, ilet_dma_local_finish, context);
	simple_ilet ilet_remote;
	simple_ilet_init(&ilet_remote, ilet_dma_remote_finish, (void*)dpc->place_id);
	dispatch_claim_push_dma(remote_claim, dpc->places, remote_places, size, &ilet_local, &ilet_remote);
}

static void ilet_allocate_places(void *arg_n_places, void *context)
{
	unsigned n_places = (unsigned)arg_n_places;
	claim_t cl = get_claim();
	assert (cl != 0 && "stack overflow maybe?");
	place_local_data *pld = claim_get_local_data(cl);
	if (NULL == pld) {
		pld = mem_allocate_tlm(sizeof(place_local_data));
		claim_set_local_data(cl, pld);
	}
	pld->n_places = n_places;
	pld->places   = mem_allocate_tlm(n_places * sizeof(*pld->places));
	/* is freed implicitly upon retreat or shutdown */
	simple_ilet ilet;
	dual_ilet_init(&ilet, ilet_transfer_places, get_global_address(pld->places), context);
	dispatch_claim_send_reply(&ilet);
}

/* Start value when trying to acquire more PEs. */
#define START_NUM_PES 4

/** Copy places array to all places
 * Frees new_places at the end. */
void distribute_places(dispatch_claim_t *new_places, unsigned new_n_places)
{
	assert(new_places != NULL && "NULL places array");
	assert(new_n_places >= 1 && "empty places array");
	simple_signal finish_signal;
	simple_signal_init(&finish_signal, new_n_places);

	for (unsigned pid = 0; pid < new_n_places; ++pid) {
		distribute_places_context *dpc = mem_allocate_tlm(sizeof(distribute_places_context));
		dpc->places = new_places;
		dpc->n_places = new_n_places;
		dpc->signal = &finish_signal;
		dpc->place_id = pid;
		simple_ilet ilet;
		dispatch_claim_t dc = new_places[pid];
		dual_ilet_init(&ilet, ilet_allocate_places, (void*)new_n_places, (void*)dpc);
		dispatch_claim_infect(dc, &ilet, 1);
	}

	/* Wait until all places are initialized. */
	simple_signal_wait(&finish_signal);

	mem_free_tlm(new_places);
}

/* initalize X10 an all places */
static void init_all_places(void)
{
	claim_t cl = get_claim();
	assert (cl != 0 && "stack overflow maybe?");
	place_local_data *pld = claim_get_local_data(cl);
	unsigned n_places = pld->n_places;
	simple_signal_init(&initialization_signal, n_places);

	for (unsigned pid = 0; pid < n_places; ++pid) {
		dispatch_claim_t dispatch_claim  = pld->places[pid];
		simple_ilet init_ilet;
		simple_ilet_init(&init_ilet, ilet_init_tile, &initialization_signal);
		dispatch_claim_infect(dispatch_claim, &init_ilet, 1);
	}

	simple_signal_wait(&initialization_signal);
}

static void init_places(claim_t root_claim)
{
	const unsigned n_tiles      = get_tile_count();
	const unsigned root_tile_id = get_tile_id();
	const unsigned io_tile_id   = get_io_tile_id();
	unsigned new_n_places;

	/* Workaround, SPARC OctoPOS currently returns 0 for get_io_tile_id(). */
	if (root_tile_id == io_tile_id || io_tile_id >= n_tiles) {
		new_n_places = n_tiles;
	} else {
		new_n_places = n_tiles - 1;
	}

	dispatch_claim_t *new_places = mem_allocate_tlm(new_n_places * sizeof(*new_places));
	memset(new_places, 0, new_n_places * sizeof(*new_places));
	proxy_claim_t *proxies = mem_allocate_tlm(new_n_places * sizeof(*proxies));
	memset(proxies, 0, new_n_places * sizeof(*proxies));

	/* Get as many CPUs as possible on local tile.
	 * Remove this once invading is exposed as an API call to the user. */
	uint32_t num = START_NUM_PES;
#ifndef USE_AGENTSYSTEM
	while (num > 0 && invade_simple(root_claim, num) == -1)
		--num;
	assert(num > 0 && "Could not get additional PEs on root tile");
#else
	(void) root_claim; /* remove warning */
#endif
	new_places[0] = get_own_dispatch_claim();

	/* Get as many CPUs as possible on all other tiles. */
	unsigned pid = 1;
	for (unsigned tile_id = 0; tile_id < n_tiles; ++tile_id) {
		/* Skip root and I/O tiles. */
		if (tile_id == root_tile_id || tile_id == io_tile_id)
			continue;

		proxy_claim_t   claim = NULL;
		invade_future_t fut;
		num = START_NUM_PES;
		while (num > 0 && (proxy_invade(tile_id, &fut, num) != 0 || (claim = invade_future_force(&fut)) == 0))
			--num;
		assert(claim != NULL && "Could not invade tile");

		proxies[pid] = claim;
		new_places[pid] = proxy_get_dispatch_info(claim);
		pid++;
	}
	assert(pid == new_n_places);

	distribute_places(new_places, new_n_places);
	init_all_places();

	/* If we use an agent system, we must free everything again,
	 * so the agent can invade everything. */
#ifdef USE_AGENTSYSTEM
	for (pid = 1; pid < new_n_places; ++pid) {
		proxy_claim_t pclaim = proxies[pid];
		retreat_future_t fut;
		proxy_retreat(pclaim, &fut);
		retreat_future_force(&fut);
	}
	claim_t cl = get_claim();
	assert (cl != 0 && "stack overflow maybe?");
	place_local_data *pld = claim_get_local_data(cl);
	pld->n_places = 1;
#endif
}

static void shutdown_everything(void) {
	/* Shutdown root tile. Ignore the rest. */
	shutdown_tile();
}

void main_ilet(claim_t root_claim)
{
#ifdef __sparc__
	/* If we're on the CHIPit hardware, we currently have to waste core 0
	 * on each tile because it has to be free to handle NoC interrupts,
	 * otherwise the hardware deadlocks.  We do this by putting core 0 into
	 * a separate claim and then throw away all references to this claim. */
	if (root_claim != NULL) {
		invade_future_t fut;
		assert(proxy_invade(0, &fut, 1) == 0);
		proxy_claim_t claim = invade_future_force(&fut);
		assert(claim != NULL);
		simple_ilet ilet;
		simple_ilet_init(&ilet, &main_ilet, NULL);
		proxy_infect(claim, &ilet, 1);
		return;
	} else {
		root_claim = get_claim();
		for (unsigned tile_id = 0; tile_id < get_tile_count(); ++tile_id) {
			if (tile_id == get_tile_id() || tile_id == get_io_tile_id())
				continue;
			invade_future_t fut;
			assert(proxy_invade(tile_id, &fut, 1) == 0);
			proxy_claim_t claim = invade_future_force(&fut);
			assert(claim != NULL);
			/* Throw away claim. */
		}
	}
#endif

	/* We want to use uart redirection through grmon -u */
	leon_set_uart_debug_mode(1);

	/* Waste some memory so that we never get the null pointer
	 * as a valid address. */
	(void)mem_map(MEM_SHM, MEMORY_WASTE_BYTES);

	/* initialize main i-let's finish state. */
	finish_state_t fs;
	finish_state_init_root(&fs);
	init_x10_activity(&fs);

	/* initialize static fields etc */
	init_places(root_claim);

	/* initialize agent system which invades everything */
#ifdef USE_AGENTSYSTEM
	agentclaim_t initialClaim = agent_claim_get_initial(root_claim);
	agentclaim_set_current(initialClaim);
#endif

	x10_object *args = _ZN3x105array5Array15makeStringArrayEPvi(NULL, 0);
	x10_main(args);

	finish_state_wait(&fs);
	finish_state_destroy(&fs);

	shutdown_everything();
}
