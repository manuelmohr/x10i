#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_EQUALS(_ZN3x104lang5UByte6equalsEa, x10_ubyte)
X10_MAKE_HASHCODE(_ZN3x104lang5UByte8hashCodeEv, x10_ubyte)
X10_MAKE_TOSTRING(_ZN3x104lang5UByte8toStringEv, x10_ubyte, "%u")
X10_MAKE_TYPENAME(_ZN3x104lang5UByte8typeNameEv, x10_ubyte, "x10.lang.UByte")
X10_MAKE_EQUALS_ANY(_ZN3x104lang5UByte6equalsEPN3x104lang3AnyE, x10_ubyte)

// compareTo from Comparable
X10_MAKE_COMPARETO(_ZN3x104lang5UByte9compareToEa, x10_ubyte)

MAKE_INT_BINOPS(_ZN3x104lang5UByte, h, x10_ubyte)
MAKE_CMPOPS(_ZN3x104lang5UByte, h, x10_ubyte)
MAKE_INT_UNOPS(_ZN3x104lang5UByte, v, x10_ubyte)
x10_ubyte _ZN3x104lang5UBytev3rbsEa(x10_byte a, x10_byte b)
{
	return a >> b;
}
MAKE_CONFS(_ZN3x104lang5UByte, x10_ubyte)
