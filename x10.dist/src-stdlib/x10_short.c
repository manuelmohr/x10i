#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang5Short9compareToEs, x10_short)
X10_MAKE_EQUALS(_ZN3x104lang5Short6equalsEs, x10_short)
X10_MAKE_TOSTRING(_ZN3x104lang5Short8toStringEv, x10_short, "%hd")
X10_MAKE_TYPENAME(_ZN3x104lang5Short8typeNameEv, x10_short, "x10.lang.Short")
X10_MAKE_EQUALS_ANY(_ZN3x104lang5Short6equalsEPN3x104lang3AnyE, x10_short)

MAKE_INT_BINOPS(_ZN3x104lang5Short, s, x10_short)
MAKE_CMPOPS(_ZN3x104lang5Short, s, x10_short)
MAKE_INT_UNOPS(_ZN3x104lang5Short, v, x10_short)
x10_short _ZN3x104lang5Shortv3rbsEs(x10_short a, x10_short b)
{
	return (x10_short) ((x10_ushort) a >> (x10_ushort) b);
}
MAKE_CONFS(_ZN3x104lang5Short, x10_short)
