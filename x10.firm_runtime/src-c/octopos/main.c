#include <octopos.h>
#include "ilocal_data.h"
#include "main.h"
#include "places.h"
#include "places_octopos.h"
#include "serialization.h"

#if __GNUC__ > 4 || (__GNUC__==4 && __GNUC_MINOR__>=7)
#error Error: gcc-4.7 and above are not supported by octopos (yet?)
#endif

unsigned       n_places;
proxy_claim_t *places;

struct initialization_data {
	unsigned       n_places;
	proxy_claim_t *places;
};
typedef struct initialization_data initialization_data_t;

static void notify_initialization(void *signal)
{
	simple_signal_signal((simple_signal *)signal);
}

/** initialization code that is run once on each tile before it is used. */
static void init_tile(void *signal, void *initialization_data)
{
	initialization_data_t *data = (initialization_data_t *)initialization_data;
	n_places = data->n_places;
	places   = data->places;

	x10_static_initializer();
	x10_serialization_init();

	simple_ilet notification_ilet;
	simple_ilet_init(&notification_ilet, notify_initialization, signal);
	dispatch_claim_send_reply(&notification_ilet);
}

void main_ilet(claim_t claim)
{
	/* We want to use uart redirection through grmon -u */
	leon_set_uart_debug_mode(1);

	n_places = get_tile_count();
	places   = mem_allocate(MEM_TLM_GLOBAL, n_places * sizeof(*places));

	unsigned n_invaded_places = 0;

	/*
	 * Get as many CPUs as possible.
	 * Remove this once invading is exposed as an API call to the user.
	 */
	for (unsigned tile_id = 0; tile_id < n_places; tile_id++) {
		uint32_t        num = 4;
		invade_future_t fut;

		/* Skip I/O tile. */
		if (tile_id == get_io_tile_id())
			continue;

		proxy_claim_t claim;
		while (num > 0 && (proxy_invade(tile_id, &fut, num) != 0 || (claim = invade_future_force(&fut)) == 0))
			--num;

		assert(num > 0 && "Could not invade tile");

		places[n_invaded_places++] = claim;
	}

	initialization_data_t *initialization_data = mem_allocate(MEM_TLM_GLOBAL, sizeof(*initialization_data));
	initialization_data->n_places = n_invaded_places;
	initialization_data->places   = places;

	simple_signal initialization_signal;
	simple_signal_init(&initialization_signal, n_invaded_places);

	/* Initialize tiles. */
	for (unsigned tile_id = 0; tile_id < n_invaded_places; tile_id++) {
		simple_ilet   initialization_ilet;
		proxy_claim_t proxy_claim         = places[tile_id];
		dual_ilet_init(&initialization_ilet, init_tile, &initialization_signal,
		               initialization_data);
		proxy_infect(proxy_claim, &initialization_ilet, 1);
	}

	/* Wait until all tile are initialized. */
	simple_signal_wait(&initialization_signal);
	mem_free(initialization_data);

	finish_state_t fs;
	fs.claim = claim;

	/* initialize main i-let's finish state */
	finish_state_set_current(&fs);

	/* begin main i-let's finish block */
	_ZN3x104lang7Runtime16finishBlockBeginEv();

	x10_object *args = _ZN3x105array5Array15makeStringArrayEPvi(NULL, 0);
	x10_main(args);

	/* end main i-let's finish block */
	_ZN3x104lang7Runtime14finishBlockEndEv();
	finish_state_destroy(&fs);

	guest_shutdown();
#ifdef __sparc__
	/* stop grmon. (older octoposses did not do this in guest_shotdown()) */
	__asm__("mov 1, %g1; ta 0;\n");
#endif
}
