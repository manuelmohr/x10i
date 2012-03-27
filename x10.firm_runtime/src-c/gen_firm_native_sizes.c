#include <stdio.h>
#include "x10.h"
#include "x10_string.h"

extern void gen_platform_native_sizes(void);

int main(void)
{
	gen_platform_native_sizes();
	printf("x10.lang.String %zu\n", sizeof(x10_string));
	return 0;
}
