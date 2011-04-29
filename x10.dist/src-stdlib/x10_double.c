#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang6Double9compareToEd, x10_double)
X10_MAKE_EQUALS(_ZN3x104lang6Double6equalsEd, x10_double)
X10_MAKE_TOSTRING(_ZN3x104lang6Double8toStringEv, x10_double, "%f")
X10_MAKE_TYPENAME(_ZN3x104lang6Double8typeNameEv, x10_double, "x10.lang.Double")
X10_MAKE_EQUALS_ANY(_ZN3x104lang6Double6equalsEPN3x104lang3AnyE, x10_int)

MAKE_BINOPS(_ZN3x104lang6Double, d, x10_double)
MAKE_CMPOPS(_ZN3x104lang6Double, d, x10_double)
MAKE_UNOPS(_ZN3x104lang6Double, v, x10_double)
x10_double _ZN3x104lang6DoublermEd(x10_double a, x10_double b)
{
	return fmod(a, b);
}
MAKE_CONFS(_ZN3x104lang6Double, x10_double)
