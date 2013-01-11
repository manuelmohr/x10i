#include "types.h"
#include "x10_string.h"

/* x10.lang.Float.operator%(Float): Float */
x10_float _ZN3x104lang5FloatrmEf(x10_float a, x10_float b)
{
	return fmodf(a, b);
}

/* x10.lang.Float.toHexString(): String */
x10_string *_ZN3x104lang5Float11toHexStringEv(x10_float self)
{
	X10_UNUSED(self);
	X10_UNIMPLEMENTED();
	return NULL;
}

/* x10.lang.Float.toString(): String */
x10_string *_ZN3x104lang5Float8toStringEv(x10_float v)
{
	return _ZN3x104lang6Double8toStringEv((x10_double) v);
}

/* x10.lang.Float.parse(String): Float */
x10_float _ZN3x104lang5Float5parseEPN3x104lang6StringE(x10_string *string)
{
	X10_UNUSED(string);
	X10_UNIMPLEMENTED();
	return NAN;
}

/* x10.lang.Float.isNaN(): Boolean */
x10_boolean _ZN3x104lang5Float5isNaNEv(x10_float self)
{
	return isnan(self);
}

/* x10.lang.Double.isInfinite(): Boolean */
x10_boolean _ZN3x104lang5Float10isInfiniteEv(x10_float self)
{
	return isinf(self);
}

/* x10.lang.Float.toRawIntBits(): Int */
x10_int _ZN3x104lang5Float12toRawIntBitsEv(x10_float self)
{
	assert(sizeof(x10_int) == sizeof(x10_float));
	char buf[sizeof(x10_float)];
	x10_float *as_float = (x10_float*)buf;
	x10_int   *as_int   = (x10_int*)buf;
	*as_float = self;
	return *as_int;
}

/* x10.lang.Float.fromIntBIts(Int): Float */
x10_float _ZN3x104lang5Float11fromIntBitsEi(x10_int digits)
{
	assert(sizeof(x10_int) == sizeof(x10_float));
	char buf[sizeof(x10_float)];
	x10_float *as_float = (x10_float*)buf;
	x10_int   *as_int   = (x10_int*)buf;
	*as_int = digits;
	return *as_float;
}
