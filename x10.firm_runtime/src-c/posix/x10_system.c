#include <time.h>
#include "types.h"
#include <gc.h>

int exit_code;

// x10.lang.System.sleep(millis : Long): boolean
x10_boolean _ZN3x104lang6System5sleepEx(x10_long millis)
{
	struct timespec duration = { millis / 1000, (millis % 1000) * 1000000 };
	return nanosleep(&duration, NULL) == 0;
}

// x10.lang.System.setExitCode(code: Int): void
void _ZN3x104lang6System11setExitCodeEi(x10_int code)
{
	exit_code = code;
}

// x10.lang.System.gc(): void
void _ZN3x104lang6System2gcEv(void)
{
	GC_gcollect();
}
