#include <stdio.h>
#include "x10_inputstreamreader.h"
#include "x10_lock_octopos.h"

void gen_platform_native_sizes(void)
{
	printf("x10.io.InputStreamReader %zu\n", sizeof(x10_inputstreamreader));
	printf("x10.util.concurrent.Lock %zu\n", sizeof(x10_lock));
}
