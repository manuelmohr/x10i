#include <stdio.h>

#include "x10.h"
#include "x10_thread.h"
#include "x10_lock.h"

int main(void)
{
	printf("x10.lang Thread %zu\n", sizeof(x10_thread));
	printf("x10.util.concurrent Lock %zu\n", sizeof(x10_lock));
	return 0; 
}

