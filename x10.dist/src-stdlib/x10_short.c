#ifndef X10_SHORT_H_
#define X10_SHORT_H_

#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang5Short9compareToEs, x10_short)
X10_MAKE_EQUALS(_ZN3x104lang5Short6equalsEs, x10_short)

// typename
x10_string *_ZN3x104lang5Short8typeNameEv(x10_short self) { 
	UNUSED(self); 
	return x10_string_from_wide_chars(T_("x10.lang.Short")); 
}

MAKE_INT_BINOPS(_ZN3x104lang5Short, s, x10_short)
MAKE_CMPOPS(_ZN3x104lang5Short, s, x10_short)
MAKE_INT_UNOPS(_ZN3x104lang5Short, v, x10_short)
x10_short _ZN3x104lang5Shortv3rbsEs(x10_short a, x10_short b)
{
	return (x10_short) ((x10_ushort) a >> (x10_ushort) b);
}
MAKE_CONFS(_ZN3x104lang5Short, x10_short)


#endif // X10_SHORT_H_
