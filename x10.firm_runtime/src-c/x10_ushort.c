#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang6UShort9compareToEt, x10_ushort)
X10_MAKE_EQUALS(_ZN3x104lang6UShort6equalsEt, x10_ushort)
X10_MAKE_HASHCODE(_ZN3x104lang6UShort8hashCodeEv, x10_ushort)
X10_MAKE_TOSTRING_UNSIGNED(_ZN3x104lang6UShort8toStringEi, x10_ushort)
X10_MAKE_PARSE(_ZN3x104lang6UShort5parseEPN3x104lang6StringEi, x10_ushort)

MAKE_UNSIGNED_BINOPS(_ZN3x104lang6UShort, t, s, x10_ushort)
MAKE_CMPOPS(_ZN3x104lang6UShort, t, x10_ushort)
MAKE_INT_UNOPS(_ZN3x104lang6UShort, v, x10_ushort)
x10_ushort _ZN3x104lang6UShortv3rbsEi(x10_ushort a, x10_int b)
{
	return ((x10_ushort) ((a) >> (0xf & (b))));
}
MAKE_CONFS(_ZN3x104lang6UShort, x10_ushort)

x10_ushort _ZN3x104lang6UShort12reverseBytesEv(x10_ushort self)
{
	extern x10_int _ZN3x104lang3Int12reverseBytesEv(x10_int);
	return (x10_ushort)_ZN3x104lang3Int12reverseBytesEv((x10_short)self);
}
