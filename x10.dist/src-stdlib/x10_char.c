#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang4Char9compareToEDi, x10_char)
X10_MAKE_HASHCODE(_ZN3x104lang4Char8hashCodeEv, x10_char)
X10_MAKE_EQUALS(_ZN3x104lang4Char6equalsEDi, x10_char)
X10_MAKE_TOSTRING(_ZN3x104lang4Char8toStringEv, x10_char, "%lc")
X10_MAKE_TYPENAME(_ZN3x104lang4Char8typeNameEv, x10_char, "x10.lang.Char")
X10_MAKE_EQUALS_ANY(_ZN3x104lang4Char6equalsEPN3x104lang3AnyE, x10_char)

MAKE_INT_BINOPS(_ZN3x104lang4Char, Di, x10_char)
MAKE_CMPOPS(_ZN3x104lang4Char, Di, x10_char)
MAKE_INT_UNOPS(_ZN3x104lang4Char, v, x10_char)
x10_char _ZN3x104lang4Charv3rbsEDi(x10_char a, x10_char b)
{
	return (x10_char) ((x10_char) a >> (x10_char) b);
}
MAKE_CONFS(_ZN3x104lang4Char, x10_char)
