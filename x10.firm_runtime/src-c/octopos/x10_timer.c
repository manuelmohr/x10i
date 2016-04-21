#include "types.h"

#include <time.h>

#if CLOCKS_PER_SEC != 1000000
#error "CLOCKS_PER_SEC is not 1000000"
#endif

x10_long _ZN3x104util5Timer8nanoTimeEv()
{
	return ((x10_long)clock()) * 1000;
}

x10_long _ZN3x104util5Timer9milliTimeEv()
{
	return (x10_long) (clock() / 1000);
}
