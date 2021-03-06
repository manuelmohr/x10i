#include <time.h>
#include "types.h"
#ifndef NO_GARBAGE_COLLECTION
#include "octo_memory.h"
#endif

x10_boolean _ZN3x104lang6System5sleepEx(x10_long millis)
{
	clock_t begin = clock();
	clock_t end   = begin + millis * (CLOCKS_PER_SEC / 1000);
	/* currently you can only do this by busy waiting in octopos */
	while (clock() < end) {
	}
	return true;
}

// x10.lang.System.setExitCode(code: Int): void
void _ZN3x104lang6System11setExitCodeEi(x10_int code)
{
	(void)code;
}

// x10.lang.System.gc(): void
void _ZN3x104lang6System2gcEv(void)
{
#ifndef NO_GARBAGE_COLLECTION
	octo_gc_collect();
#endif
}
