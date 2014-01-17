#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include "types.h"
#include "x10_string.h"

/* x10.lang.Double.operator%(Double):Double */
x10_double _ZN3x104lang6DoublermEd(x10_double a, x10_double b)
{
#ifdef DOUBLE_IS_32BIT
	return fmodf(a, b);
#else
	return fmod(a, b);
#endif
}

/* x10.lang.Double.toHexString():String */
x10_string *_ZN3x104lang6Double11toHexStringEv(x10_double self)
{
	X10_UNUSED(self);
	X10_UNIMPLEMENTED();
	return NULL;
}

#ifdef DOUBLE_IS_32BIT
/* In this case, the actual implementation is provided by a small lib that
 * we compile using GCC. */
x10_string *_ZN3x104lang6Double8toStringEv(x10_double v);
#else
#include "doublereg/to_string.c"
#endif

/* static x10.lang.Double.parse(String): Double */
x10_double _ZN3x104lang6Double5parseEPN3x104lang6StringE(x10_string *string)
{
	X10_UNUSED(string);
	X10_UNIMPLEMENTED();
	return NAN;
}

/* x10.lang.Double.isNaN(): Boolean */
x10_boolean _ZN3x104lang6Double5isNaNEv(x10_double self)
{
	return isnan(self);
}

/* x10.lang.Double.isInfinite(): Boolean */
x10_boolean _ZN3x104lang6Double10isInfiniteEv(x10_double self)
{
	return isinf(self);
}

/* x10.lang.Double.toLongBits(): Long */
x10_long _ZN3x104lang6Double13toRawLongBitsEv(x10_double self)
{
	assert(sizeof(x10_long) == sizeof(x10_double));
	char buf[sizeof(x10_double)];
	x10_double *as_double = (x10_double*)buf;
	x10_long   *as_long   = (x10_long*)buf;
	*as_double = self;
	return *as_long;
}

/* static x10.lang.Double.fromLongBits(Long): Double */
x10_double _ZN3x104lang6Double12fromLongBitsEx(x10_long x)
{
	assert(sizeof(x10_long) == sizeof(x10_double));
	char buf[sizeof(x10_double)];
	x10_double *as_double = (x10_double*)buf;
	x10_long   *as_long   = (x10_long*)buf;
	*as_long = x;
	return *as_double;
}
