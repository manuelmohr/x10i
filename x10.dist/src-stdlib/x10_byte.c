#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

// compareTo from Comparable
X10_MAKE_COMPARETO(_ZN3x104lang4Byte9compareToEa, x10_byte)
X10_MAKE_EQUALS(_ZN3x104lang4Byte6equalsEa, x10_byte)
X10_MAKE_TOSTRING(_ZN3x104lang4Byte8toStringEv, x10_byte, "%d")
X10_MAKE_TYPENAME(_ZN3x104lang4Byte8typeNameEv, x10_byte, "x10.lang.Byte")
X10_MAKE_EQUALS_ANY(_ZN3x104lang4Byte6equalsEPN3x104lang3AnyE, x10_byte)

MAKE_INT_BINOPS(_ZN3x104lang4Byte, a, x10_byte)
MAKE_CMPOPS(_ZN3x104lang4Byte, a, x10_byte)
MAKE_INT_UNOPS(_ZN3x104lang4Byte, v, x10_byte)
x10_byte _ZN3x104lang4Bytev3rbsEa(x10_byte a, x10_byte b)
{
	return (x10_byte) ((x10_ubyte) a >> (x10_ubyte) b);
}
MAKE_CONFS(_ZN3x104lang4Byte, x10_byte)
