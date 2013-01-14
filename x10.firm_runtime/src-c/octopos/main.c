#include <octopos.h>
#include "ilocal_data.h"
#include "main.h"
#include "init.h"

void main_ilet(claim_t claim)
{
	/* We want to use uart redirection through grmon -u */
	leon_set_uart_debug_mode(1);

	/*
	 * Get as many cpus as possible.
	 * Remove this once invading is exposed as an API call to the user.
	 */
	uint32_t num = 64;
	while (num > 0 && invade_simple(claim, num) != 0)
		--num;

	x10_static_initializer();

	finish_state fs;
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

	guest_shutdown();
}
