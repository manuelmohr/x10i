#include "x10_throw.h"

#include <assert.h>

X10_EXTERN void x10_throw_stub(void)
{
	exit(EXIT_SUCCESS);
//	assert(false && "throw is not implemented yet.");
}
