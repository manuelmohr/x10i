#ifndef X10_UINT_H_
#define X10_UINT_H_

#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang4UInt9compareToEi, x10_uint)
X10_MAKE_EQUALS(_ZN3x104lang4UInt6equalsEi, x10_uint)

// typename
x10_string *_ZN3x104lang4UInt8typeNameEv(x10_uint self) { 
	UNUSED(self); 
	return x10_string_from_wide_chars(T_("x10.lang.UInt")); 
}

MAKE_INT_BINOPS(_ZN3x104lang4UInt, j, x10_uint)
MAKE_CMPOPS(_ZN3x104lang4UInt, j, x10_uint)
MAKE_INT_UNOPS(_ZN3x104lang4UInt, v, x10_uint)
x10_int _ZN3x104lang4UIntv3rbsEi(x10_uint a, x10_uint b)
{
	return (x10_int) ((x10_uint) a >> (x10_uint) b);
}
MAKE_CONFS(_ZN3x104lang4UInt, x10_uint)



#endif // X10_UINT_H_
