#include <octopos.h>
#include "ilocal_data.h"
#include "main.h"
#include "init.h"
#include "places.h"
#include "places_octopos.h"

#if __GNUC__ > 4 || (__GNUC__==4 && __GNUC_MINOR__>=7)
#error Error: gcc-4.7 and above are not supported by octopos (yet?)
#endif

unsigned       n_places;
proxy_claim_t *places;

static void notify_initialization(void *signal)
{
	simple_signal_signal((simple_signal *)signal);
}

static void x10_static_initializer_wrapper(void *signal, void *number_of_places)
{
	n_places = (unsigned)number_of_places;

	x10_static_initializer();

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

	simple_signal initialization_signal;
	simple_signal_init(&initialization_signal, n_invaded_places);

	/* Initialize tiles. */
	for (unsigned tile_id = 0; tile_id < n_invaded_places; tile_id++) {
		simple_ilet   initialization_ilet;
		proxy_claim_t proxy_claim         = places[tile_id];
		dual_ilet_init(&initialization_ilet, x10_static_initializer_wrapper, &initialization_signal, (void *)n_invaded_places);
		proxy_infect(proxy_claim, &initialization_ilet, 1);
	}

	/* Wait until all tile are initialized. */
	simple_signal_wait(&initialization_signal);

	finish_state_t fs;
	fs.claim = claim;

	/* initialize main i-let's finish state */
	finish_state_set_current(&fs);

	/* begin main i-let's finish block */
	_ZN3x104lang7Runtime16finishBlockBeginEv();

	x10_rt_init();

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
