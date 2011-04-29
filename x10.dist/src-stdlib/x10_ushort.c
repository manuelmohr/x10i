#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang6UShort9compareToEs, x10_ushort)
X10_MAKE_EQUALS(_ZN3x104lang6UShort6equalsEs, x10_ushort)
X10_MAKE_TOSTRING(_ZN3x104lang6UShort8toStringEv, x10_ushort, "%hu")
X10_MAKE_TYPENAME(_ZN3x104lang6UShort8typeNameEv, x10_ushort, "x10.lang.UShort")
X10_MAKE_EQUALS_ANY(_ZN3x104lang6UShort6equalsEPN3x104lang3AnyE, x10_ushort)

MAKE_INT_BINOPS(_ZN3x104lang6UShort, s, x10_ushort)
MAKE_CMPOPS(_ZN3x104lang6UShort, s, x10_ushort)
MAKE_INT_UNOPS(_ZN3x104lang6UShort, v, x10_ushort)
x10_ushort _ZN3x104lang6UShortv3rbsEs(x10_ushort a, x10_ushort b)
{
	return a >> b;
}
MAKE_CONFS(_ZN3x104lang6UShort, x10_ushort)
