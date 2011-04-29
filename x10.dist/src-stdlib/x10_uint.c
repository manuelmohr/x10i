#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang4UInt9compareToEi, x10_uint)
X10_MAKE_EQUALS(_ZN3x104lang4UInt6equalsEi, x10_uint)
X10_MAKE_TOSTRING(_ZN3x104lang4UInt8toStringEv, x10_uint, "%u")
X10_MAKE_TYPENAME(_ZN3x104lang4UInt8typeNameEv, x10_uint, "x10.lang.UInt")
X10_MAKE_EQUALS_ANY(_ZN3x104lang4UInt6equalsEPN3x104lang3AnyE, x10_uint)

MAKE_INT_BINOPS(_ZN3x104lang4UInt, j, x10_uint)
MAKE_CMPOPS(_ZN3x104lang4UInt, j, x10_uint)
MAKE_INT_UNOPS(_ZN3x104lang4UInt, v, x10_uint)
x10_int _ZN3x104lang4UIntv3rbsEi(x10_uint a, x10_uint b)
{
	return (x10_int) ((x10_uint) a >> (x10_uint) b);
}
MAKE_CONFS(_ZN3x104lang4UInt, x10_uint)
