#include "x10_throw.h"

#include <assert.h>

void _ZN3x104lang7Runtime14printExceptionEPN3x104lang16CheckedThrowableE(x10_object *object);

void __attribute__((noreturn)) x10_exception_unwind(x10_object *object)
{
	/* unwinding not implemented yet, so just display the exception and abort */
	if (object != NULL)
		_ZN3x104lang7Runtime14printExceptionEPN3x104lang16CheckedThrowableE(object);
	abort();
}
