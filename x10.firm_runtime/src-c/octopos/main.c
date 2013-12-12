#include <octopos.h>
#include "ilocal_data.h"
#include "main.h"
#include "places.h"
#include "agent.h"
#include "places_octopos.h"
#include "serialization.h"
#include "xmalloc.h"

typedef struct distribute_places_context {
	dispatch_claim_t *places;
	int n_places;
	simple_signal *signal;
} distribute_places_context;

dispatch_claim_t *places;

static simple_signal initialization_signal;

static void ilet_notify(void *arg)
{
	simple_signal_signal((simple_signal*)arg);
}

/** initialization code that is run once on each tile before it is used. */
static void init_tile()
{
	gc_init();
	x10_static_initializer();
	x10_serialization_init();
}

static void ilet_dma_local_finish(void *context)
{
	distribute_places_context *dpc  = context;
	simple_signal_signal(dpc->signal);
}

static void ilet_init_tile(void *init_signal, void *pid)
{
	place_id = (unsigned) pid;
	init_tile();
	simple_ilet notification_ilet;
	simple_ilet_init(&notification_ilet, ilet_notify, init_signal);
	dispatch_claim_send_reply(&notification_ilet);
}

/** shutdown code that is run on each tile before exiting. */
static void shutdown_tile()
{
	mem_free(places);
	guest_shutdown();
}

static void ilet_transfer_places(void *remote_places, void *context)
{
	distribute_places_context *dpc  = context;
	dispatch_claim_t remote_claim   = get_parent_dispatch_claim();
	buf_size_t       size           = (dpc->n_places) * sizeof(*places);

	simple_ilet ilet;
	simple_ilet_init(&ilet, ilet_dma_local_finish, context);
	dispatch_claim_push_dma(remote_claim, dpc->places, remote_places, size, &ilet, NULL);
}

static void ilet_allocate_places(void *arg_n_places, void *context)
{
	if (places != NULL) mem_free(places);
	n_places = (unsigned)arg_n_places;
	places   = mem_allocate(MEM_TLM_LOCAL, n_places * sizeof(*places));
	simple_ilet ilet;
	dual_ilet_init(&ilet, ilet_transfer_places, get_global_address(places), context);
	dispatch_claim_send_reply(&ilet);
}

/* Start value when trying to acquire more PEs. */
#define START_NUM_PES 4

/* Copy local places array to all places */
static void distribute_places(dispatch_claim_t *new_places, unsigned new_n_places)
{
	simple_signal finish_signal;
	simple_signal_init(&finish_signal, new_n_places);

	for (unsigned pid = 0; pid < new_n_places; ++pid) {
		distribute_places_context *dpc = mem_allocate(MEM_TLM_LOCAL, sizeof(distribute_places_context));
		dpc->places = new_places;
		dpc->n_places = new_n_places;
		dpc->signal = &finish_signal;
		simple_ilet ilet;
		dispatch_claim_t dc = new_places[pid];
		dual_ilet_init(&ilet, ilet_allocate_places, (void*)new_n_places, (void*)dpc);
		dispatch_claim_infect(dc, &ilet, 1);
	}

	/* Wait until all places are initialized. */
	simple_signal_wait(&finish_signal);
}

/* initalize X10 an all places */
static void init_all_places(void)
{
	simple_signal_init(&initialization_signal, n_places);

	for (unsigned pid = 0; pid < n_places; ++pid) {
		dispatch_claim_t dispatch_claim  = places[pid];
		simple_ilet init_ilet;
		dual_ilet_init(&init_ilet, ilet_init_tile, &initialization_signal, (void*)pid);
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

	dispatch_claim_t *new_places = mem_allocate(MEM_TLM_LOCAL, new_n_places * sizeof(*new_places));
	memset(new_places, 0, new_n_places * sizeof(*new_places));
	proxy_claim_t *proxies = mem_allocate(MEM_TLM_LOCAL, new_n_places * sizeof(*proxies));
	memset(proxies, 0, new_n_places * sizeof(*proxies));

	/* Get as many CPUs as possible on local tile.
	 * Remove this once invading is exposed as an API call to the user. */
	place_id = 0; /* Set root place's id. */
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
#endif
}

static void shutdown_everything(void) {
	/* Shutdown root tile. Ignore the rest. */
	shutdown_tile();
}

void main_ilet(claim_t root_claim)
{
	/* We want to use uart redirection through grmon -u */
	leon_set_uart_debug_mode(1);

	/* Waste some memory so that we never get the null pointer
	 * as a valid address. */
	(void)mem_map(MEM_SHM, 1024 * 1024);

	/* initialize static fields etc */
	init_places(root_claim);

	/* initialize agent system which invades everything */
#ifdef USE_AGENTSYSTEM
	agentclaim_t initialClaim = agent_claim_get_initial(root_claim);
	agentclaim_set_current(initialClaim);
#endif

	finish_state_t fs;
	fs.claim = root_claim;

	/* initialize main i-let's finish state and atomic depth. */
	finish_state_set_current(&fs);
	activity_set_atomic_depth(0);

	/* begin main i-let's finish block */
	_ZN3x104lang7Runtime16finishBlockBeginEv();

	x10_object *args = _ZN3x105array5Array15makeStringArrayEPvi(NULL, 0);
	x10_main(args);

	/* end main i-let's finish block */
	_ZN3x104lang7Runtime14finishBlockEndEv();
	finish_state_destroy(&fs);

	shutdown_everything();
}
