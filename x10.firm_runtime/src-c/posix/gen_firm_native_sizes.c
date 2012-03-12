#include "posix_types.h"
#include "x10_thread.h"
#include <stdio.h>

int main(void)
{
	printf("x10.lang Thread %zu\n", sizeof(x10_thread));
	printf("x10.util.concurrent Lock %zu\n", sizeof(x10_lock));
	printf("x10.lang String %zu\n", sizeof(x10_string));
	return 0;
}
