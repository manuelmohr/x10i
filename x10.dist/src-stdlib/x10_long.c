#ifndef X10_LONG_H_
#define X10_LONG_H_

#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang4Long9compareToEx, x10_long)
X10_MAKE_EQUALS(_ZN3x104lang4Long6equalsEx, x10_long)

// typename
x10_string *_ZN3x104lang4Long8typeNameEv(x10_long self) { 
	UNUSED(self); 
	return x10_string_from_wide_chars(T_("x10.lang.Long")); 
}

MAKE_INT_BINOPS(_ZN3x104lang4Long, x, x10_long)
MAKE_CMPOPS(_ZN3x104lang4Long, x, x10_long)
MAKE_INT_UNOPS(_ZN3x104lang4Long, v, x10_long)
x10_long _ZN3x104lang4Longv3rbsEx(x10_long a, x10_long b)
{
	return (x10_long) ((x10_ulong) a >> (x10_ulong) b);
}
MAKE_CONFS(_ZN3x104lang4Long, x10_long)


#endif // X10_LONG_H_
