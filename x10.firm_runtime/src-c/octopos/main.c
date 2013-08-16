#include <octopos.h>
#include "ilocal_data.h"
#include "main.h"
#include "places.h"
#include "places_octopos.h"
#include "serialization.h"

unsigned          n_places;
dispatch_claim_t *places;

static simple_signal initialization_signal;

static void ilet_notify(void *arg)
{
	simple_signal_signal((simple_signal*)arg);
}

/** initialization code that is run once on each tile before it is used. */
static void init_tile()
{
	x10_static_initializer();
	x10_serialization_init();
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
	mem_free(places);
	guest_shutdown();
}

static void ilet_shutdown_tile(void *arg)
{
	(void)arg;
	shutdown_tile();
}

static void ilet_transfer_places(void *arg_remote_place_id, void *remote_places)
{
	const unsigned   remote_place_id = (unsigned)arg_remote_place_id;
	dispatch_claim_t remote_claim   = places[remote_place_id];
	buf_size_t       size           = n_places * sizeof(*places);

	simple_ilet init_ilet;
	simple_ilet_init(&init_ilet, ilet_init_tile, &initialization_signal);
	dispatch_claim_push_dma(remote_claim, places, remote_places, size, NULL, &init_ilet);
}

static void ilet_allocate_places(void *arg_place_id, void *arg_n_places)
{
	n_places = (unsigned)arg_n_places;
	places   = mem_allocate(MEM_TLM_LOCAL, n_places * sizeof(*places));

	simple_ilet transfer_ilet;
	dual_ilet_init(&transfer_ilet, ilet_transfer_places, arg_place_id, get_global_address(places));
	dispatch_claim_send_reply(&transfer_ilet);
}

/* Start value when trying to acquire more PEs. */
#define START_NUM_PES 4

void main_ilet(claim_t root_claim)
{
	/* We want to use uart redirection through grmon -u */
	leon_set_uart_debug_mode(1);

	const unsigned n_tiles      = get_tile_count();
	const unsigned root_tile_id = (unsigned)get_tile_id();
	const unsigned io_tile_id   = get_io_tile_id();

	/* Workaround, SPARC OctoPOS currently returns 0 for get_io_tile_id(). */
	if (root_tile_id == io_tile_id || io_tile_id >= n_tiles) {
		n_places = n_tiles;
	} else {
		n_places = n_tiles - 1;
	}
	const unsigned n_other_places = n_places - 1;

	places = mem_allocate(MEM_TLM_LOCAL, n_places * sizeof(*places));
	memset(places, 0, n_places * sizeof(*places));

	/* Get as many CPUs as possible on local tile.
	 * Remove this once invading is exposed as an API call to the user. */
	unsigned place_id = 0;
	{
		uint32_t num = START_NUM_PES;
		while (num > 0 && invade_simple(root_claim, num) == -1)
			--num;
		assert(num > 0 && "Could not get additional PEs on root tile");
		places[place_id++] = get_own_dispatch_claim();
	}

	/* Get as many CPUs as possible on all other tiles. */
	for (unsigned tile_id = 0; tile_id < n_tiles; ++tile_id) {
		/* Skip root and I/O tiles. */
		if (tile_id == root_tile_id || tile_id == io_tile_id)
			continue;

		uint32_t        num = START_NUM_PES;
		proxy_claim_t   claim = NULL;
		invade_future_t fut;
		while (num > 0 && (proxy_invade(tile_id, &fut, num) != 0 || (claim = invade_future_force(&fut)) == 0))
			--num;
		assert(claim != NULL && "Could not invade tile");

		places[place_id++] = proxy_get_dispatch_info(claim);
	}
	assert(place_id == n_places);

	/* Distribute places array and initialize all non-initial places. */
	simple_signal_init(&initialization_signal, n_other_places);
	for (place_id = 1; place_id < n_places; ++place_id) {
		dispatch_claim_t dispatch_claim  = places[place_id];
		simple_ilet      start_init_ilet;
		dual_ilet_init(&start_init_ilet, ilet_allocate_places, (void*)place_id, (void*)n_places);
		dispatch_claim_infect(dispatch_claim, &start_init_ilet, 1);
	}

	/* Initialize initial place. */
	init_tile();

	/* Wait until all places are initialized. */
	simple_signal_wait(&initialization_signal);

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

	/* Shutdown all other tiles. */
	for (place_id = 1; place_id < n_places; ++place_id) {
		dispatch_claim_t dispatch_claim = places[place_id];
		simple_ilet      shutdown_ilet;
		simple_ilet_init(&shutdown_ilet, ilet_shutdown_tile, NULL);
		dispatch_claim_infect(dispatch_claim, &shutdown_ilet, 1);
	}

	/* Shutdown root tile. */
	shutdown_tile();
}
