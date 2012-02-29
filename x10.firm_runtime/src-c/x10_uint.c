#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang4UInt9compareToEj, x10_uint)
X10_MAKE_EQUALS(_ZN3x104lang4UInt6equalsEj, x10_uint)
X10_MAKE_HASHCODE(_ZN3x104lang4UInt8hashCodeEv, x10_uint)
X10_MAKE_TOSTRING_UNSIGNED(_ZN3x104lang4UInt8toStringEi, x10_uint)
X10_MAKE_PARSE(_ZN3x104lang4UInt5parseEPN3x104lang6StringEi, x10_uint)

MAKE_UNSIGNED_BINOPS(_ZN3x104lang4UInt, j, i, x10_uint)
MAKE_CMPOPS(_ZN3x104lang4UInt, j, x10_uint)
MAKE_INT_UNOPS(_ZN3x104lang4UInt, v, x10_uint)
x10_int _ZN3x104lang4UIntv3rbsEi(x10_uint a, x10_int b)
{
	return (x10_int) ((x10_uint) a >> (x10_uint) b);
}
MAKE_CONFS(_ZN3x104lang4UInt, x10_uint)

x10_int _ZN3x104lang4UInt8bitCountEv(x10_uint self)
{
	extern x10_int _ZN3x104lang3Int8bitCountEv(x10_int);
	return _ZN3x104lang3Int8bitCountEv((x10_int)self);
}

x10_int _ZN3x104lang4UInt21numberOfTrailingZerosEv(x10_uint self)
{
	extern x10_int _ZN3x104lang3Int21numberOfTrailingZerosEv(x10_int);
	return _ZN3x104lang3Int21numberOfTrailingZerosEv((x10_int)self);
}

x10_int _ZN3x104lang4UInt20numberOfLeadingZerosEv(x10_uint self)
{
	extern x10_int _ZN3x104lang3Int20numberOfLeadingZerosEv(x10_int);
	return _ZN3x104lang3Int20numberOfLeadingZerosEv((x10_int)self);
}

x10_uint _ZN3x104lang4UInt13highestOneBitEv(x10_uint self)
{
	extern x10_int _ZN3x104lang3Int13highestOneBitEv(x10_int);
	return (x10_uint)_ZN3x104lang3Int13highestOneBitEv((x10_int)self);
}

x10_uint _ZN3x104lang4UInt12lowestOneBitEv(x10_uint self)
{
	extern x10_int _ZN3x104lang3Int12lowestOneBitEv(x10_int);
	return (x10_uint)_ZN3x104lang3Int12lowestOneBitEv((x10_int)self);
}
