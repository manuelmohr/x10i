#include <stdio.h>
#include "x10_inputstreamreader.h"

void gen_platform_native_sizes(void)
{
	printf("x10.io.InputStreamReader %zu\n", sizeof(x10_inputstreamreader));
}
