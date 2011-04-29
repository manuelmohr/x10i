#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang4Long9compareToEx, x10_long)
X10_MAKE_EQUALS(_ZN3x104lang4Long6equalsEx, x10_long)
X10_MAKE_TOSTRING(_ZN3x104lang4Long8toStringEv, x10_long, "%ld")
X10_MAKE_TYPENAME(_ZN3x104lang4Long8typeNameEv, x10_long, "x10.lang.Long")
X10_MAKE_EQUALS_ANY(_ZN3x104lang4Long6equalsEPN3x104lang3AnyE, x10_long)

MAKE_INT_BINOPS(_ZN3x104lang4Long, x, x10_long)
MAKE_CMPOPS(_ZN3x104lang4Long, x, x10_long)
MAKE_INT_UNOPS(_ZN3x104lang4Long, v, x10_long)
x10_long _ZN3x104lang4Longv3rbsEx(x10_long a, x10_long b)
{
	return (x10_long) ((x10_ulong) a >> (x10_ulong) b);
}
MAKE_CONFS(_ZN3x104lang4Long, x10_long)
