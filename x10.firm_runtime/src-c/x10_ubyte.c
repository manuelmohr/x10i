#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_EQUALS(_ZN3x104lang5UByte6equalsEh, x10_ubyte)
X10_MAKE_HASHCODE(_ZN3x104lang5UByte8hashCodeEv, x10_ubyte)
X10_MAKE_TOSTRING_UNSIGNED(_ZN3x104lang5UByte8toStringEi, x10_ubyte)
X10_MAKE_PARSE(_ZN3x104lang5UByte5parseEPN3x104lang6StringEi, x10_ubyte)

// compareTo from Comparable
X10_MAKE_COMPARETO(_ZN3x104lang5UByte9compareToEh, x10_ubyte)

MAKE_UNSIGNED_BINOPS(_ZN3x104lang5UByte, h, a, x10_ubyte)
MAKE_CMPOPS(_ZN3x104lang5UByte, h, x10_ubyte)
MAKE_INT_UNOPS(_ZN3x104lang5UByte, v, x10_ubyte)
x10_ubyte _ZN3x104lang5UBytev3rbsEi(x10_byte a, x10_byte b)
{
	return (x10_ubyte)((a) >> (0x7 & (b)));
}
MAKE_CONFS(_ZN3x104lang5UByte, x10_ubyte)

x10_int _ZN3x104lang5UByte6signumEv(x10_ubyte self)
{
	return self == 0 ? 0 : 1;
}

x10_ubyte _ZN3x104lang5UByte7reverseEv(x10_ubyte self)
{
	extern x10_int _ZN3x104lang3Int7reverseEv(x10_int);
	return (x10_ubyte)(_ZN3x104lang3Int7reverseEv((x10_ubyte)self) >> 24);
}
