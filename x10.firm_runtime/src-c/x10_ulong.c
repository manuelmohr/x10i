#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang5ULong9compareToEy, x10_ulong)
X10_MAKE_EQUALS(_ZN3x104lang5ULong6equalsEy, x10_ulong)
X10_MAKE_HASHCODE(_ZN3x104lang5ULong8hashCodeEv, x10_ulong)
X10_MAKE_TOSTRING_UNSIGNED(_ZN3x104lang5ULong8toStringEi, x10_ulong)
X10_MAKE_PARSE(_ZN3x104lang5ULong5parseEPN3x104lang6StringEi, x10_ulong)

MAKE_UNSIGNED_BINOPS(_ZN3x104lang5ULong, y, x, x10_ulong)
MAKE_CMPOPS(_ZN3x104lang5ULong, y, x10_ulong)
MAKE_INT_UNOPS(_ZN3x104lang5ULong, v, x10_ulong)
x10_ulong _ZN3x104lang5ULongv3rbsEi(x10_ulong a, x10_int b)
{
	return ((x10_ulong) ((a) >> (0x3f & (b))));
}
MAKE_CONFS(_ZN3x104lang5ULong, x10_ulong)

x10_ulong _ZN3x104lang5ULong12reverseBytesEv(x10_ulong self)
{
	extern x10_long _ZN3x104lang4Long12reverseBytesEv(x10_long);
	return (x10_ulong)_ZN3x104lang4Long12reverseBytesEv((x10_long)self);
}

x10_int _ZN3x104lang5ULong8bitCountEv(x10_ulong self)
{
	extern x10_int _ZN3x104lang4Long8bitCountEv(x10_long);
	return _ZN3x104lang4Long8bitCountEv((x10_long)self);
}

x10_int _ZN3x104lang5ULong21numberOfTrailingZerosEv(x10_ulong self)
{
	extern x10_int _ZN3x104lang4Long21numberOfTrailingZerosEv(x10_long);
	return _ZN3x104lang4Long21numberOfTrailingZerosEv((x10_long)self);
}

x10_int _ZN3x104lang5ULong20numberOfLeadingZerosEv(x10_ulong self)
{
	extern x10_int _ZN3x104lang4Long20numberOfLeadingZerosEv(x10_long);
	return _ZN3x104lang5ULong20numberOfLeadingZerosEv((x10_long)self);
}

x10_ulong _ZN3x104lang5ULong12lowestOneBitEv(x10_ulong self)
{
	extern x10_long _ZN3x104lang4Long12lowestOneBitEv(x10_long);
	return (x10_ulong)_ZN3x104lang4Long12lowestOneBitEv((x10_long)self);
}

x10_ulong _ZN3x104lang5ULong13highestOneBitEv(x10_ulong self)
{
	extern x10_long _ZN3x104lang4Long13highestOneBitEv(x10_long);
	return (x10_ulong)_ZN3x104lang4Long13highestOneBitEv((x10_long)self);
}
