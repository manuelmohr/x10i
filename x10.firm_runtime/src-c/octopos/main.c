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

#ifndef USE_AGENTSYSTEM
uintptr_t os_agent_agentsystem_no_init = 1;
#endif

typedef struct distribute_places_context {
	dispatch_claim_t *places;
	int n_places;
	simple_signal *signal;
	unsigned place_id;
} distribute_places_context;

static simple_signal initialization_signal;

static void ilet_notify(void *arg)
{
	simple_signal_signal_and_exit((simple_signal*)arg);
}

void *_ZN3x108compiler14InitDispatcher17get_staticMonitorEv(void);

/** initialization code that is run once on each tile before it is used. */
static void init_tile()
{
	x10_static_initializer();
	/* Make sure that InitDispatcher's static monitor is initialized. */
	(void)_ZN3x108compiler14InitDispatcher17get_staticMonitorEv();
	x10_serialization_init();
}

static void ilet_dma_local_finish(void *context)
{
	distribute_places_context *dpc = context;
	simple_signal             *sig = dpc->signal;
	mem_free_tlm(dpc);
	simple_signal_signal_and_exit(sig);
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
	dispatch_claim_push_dma(remote_claim, dpc->places, remote_places, size, &ilet_local, NULL);
}

static void ilet_allocate_places(void *arg_mix, void *context)
{
	unsigned mix = (unsigned)(uintptr_t)arg_mix;
	unsigned n_places = mix & 0xffff;
	unsigned pid = mix >> 16;
	place_local_data *pld = claim_get_local_data();
	if (NULL == pld) {
		pld = mem_allocate_tlm(sizeof(place_local_data));
		pld->places = NULL;
		claim_set_local_data(pld);
	}
	if (pld->places != NULL) {
		/* avoid memory leak via redistribute_places */
		mem_free_tlm(pld->places);
	}
	pld->n_places = n_places;
	pld->place_id = pid;
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
	assert(new_n_places <= 0xffff && "too many places");
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
		unsigned mix = new_n_places | (pid << 16);
		dual_ilet_init(&ilet, ilet_allocate_places, (void*)(uintptr_t)mix, (void*)dpc);
		dispatch_claim_infect(dc, &ilet, 1);
	}

	/* Wait until all places are initialized. */
	simple_signal_wait(&finish_signal);

	mem_free_tlm(new_places);
}

/* initalize X10 an all places */
static void init_all_places(void)
{
	place_local_data *pld = claim_get_local_data();
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
	const unsigned n_compute_tiles = get_compute_tile_count();
	const unsigned root_tile_id    = get_tile_id();

	/* get compute tile IDs */
	unsigned *compute_tile_ids = mem_allocate_tlm(n_compute_tiles * sizeof(*compute_tile_ids));
	const unsigned check = get_compute_tile_ids(compute_tile_ids, n_compute_tiles);
	assert(check == n_compute_tiles && "Number of compute tiles mismatch");

	dispatch_claim_t *new_places = mem_allocate_tlm(n_compute_tiles * sizeof(*new_places));
	memset(new_places, 0, n_compute_tiles * sizeof(*new_places));
	proxy_claim_t *proxies = mem_allocate_tlm(n_compute_tiles * sizeof(*proxies));
	memset(proxies, 0, n_compute_tiles * sizeof(*proxies));

	/* Get as many CPUs as possible on local tile.
	 * Remove this once invading is exposed as an API call to the user. */
	uint32_t num = START_NUM_PES;
#ifndef USE_AGENTSYSTEM
	while (num > 0 && invade_simple(root_claim, num) == -1)
		--num;
#else
	(void) root_claim; /* remove warning */
#endif
	new_places[compute_tile_ids[root_tile_id]] = get_own_dispatch_claim();

	/* Get as many CPUs as possible on all other tiles. */
	for (unsigned pid = 0; pid < n_compute_tiles; ++pid) {
		unsigned tile_id = compute_tile_ids[pid];
		if (tile_id == root_tile_id)
			continue;

		proxy_claim_t   claim = NULL;
		invade_future_t fut;
		num = START_NUM_PES;
		while (num > 0 && (proxy_invade(tile_id, &fut, num) != 0 || (claim = invade_future_force(&fut)) == 0))
			--num;
		assert(claim != NULL && "Could not invade tile");

		proxies[pid] = claim;
		new_places[pid] = proxy_get_dispatch_info(claim);
	}

	distribute_places(new_places, n_compute_tiles);
	init_all_places();

	/* If we use an agent system, we must free everything again,
	 * so the agent can invade everything. */
#ifdef USE_AGENTSYSTEM
	for (unsigned pid = 0; pid < n_compute_tiles; ++pid) {
		if (compute_tile_ids[pid] == root_tile_id)
			continue;
		proxy_claim_t pclaim = proxies[pid];
		retreat_future_t fut;
		proxy_retreat(pclaim, &fut);
		retreat_future_force(&fut);
	}
	place_local_data *pld = claim_get_local_data();
	pld->n_places = 1;
#endif
}

static void shutdown_everything(void)
{
	/* Shutdown root tile. Ignore the rest. */
	shutdown_tile();
}

void main_ilet(claim_t root_claim)
{
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
