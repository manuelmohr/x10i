#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

// compareTo from Comparable
X10_MAKE_COMPARETO(_ZN3x104lang4Byte9compareToEa, x10_byte)
X10_MAKE_HASHCODE(_ZN3x104lang4Byte8hashCodeEv, x10_byte)
X10_MAKE_EQUALS(_ZN3x104lang4Byte6equalsEa, x10_byte)
X10_MAKE_TOSTRING(_ZN3x104lang4Byte8toStringEi, x10_byte)
X10_MAKE_PARSE(_ZN3x104lang4Byte5parseEPN3x104lang6StringEi, x10_byte)

MAKE_INT_BINOPS2(_ZN3x104lang4Byte, a, x10_byte)

MAKE_CMPOPS(_ZN3x104lang4Byte, a, x10_byte)
MAKE_INT_UNOPS(_ZN3x104lang4Byte, v, x10_byte)

x10_byte _ZN3x104lang4Bytev3rbsEi(x10_byte a, x10_int b)
{
	return ((x10_byte)((x10_uint) (a) >> (0x7 & (b))));
}
MAKE_CONFS(_ZN3x104lang4Byte, x10_byte)
