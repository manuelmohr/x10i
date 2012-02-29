#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_EQUALS(_ZN3x104lang5Short6equalsEs, x10_short)
X10_MAKE_HASHCODE(_ZN3x104lang5Short8hashCodeEv, x10_short)
X10_MAKE_TOSTRING(_ZN3x104lang5Short8toStringEi, x10_short)
X10_MAKE_PARSE(_ZN3x104lang5Short5parseEPN3x104lang6StringEi, x10_short)

MAKE_INT_BINOPS2(_ZN3x104lang5Short, s, x10_short)
MAKE_CMPOPS(_ZN3x104lang5Short, s, x10_short)
MAKE_INT_UNOPS(_ZN3x104lang5Short, v, x10_short)
x10_short _ZN3x104lang5Shortv3rbsEi(x10_short a, x10_int b)
{
	return (x10_short) ((x10_uint) a >> (0xF & (b)));
}
MAKE_CONFS(_ZN3x104lang5Short, x10_short)
