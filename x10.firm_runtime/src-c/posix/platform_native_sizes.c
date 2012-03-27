#include <stdio.h>
#include "posix_types.h"
#include "x10_thread.h"

void gen_platform_native_sizes(void)
{
	printf("x10.lang.Thread %zu\n", sizeof(x10_thread));
	printf("x10.util.concurrent.Lock %zu\n", sizeof(x10_lock));
}
