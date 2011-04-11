#ifndef X10_INT_H_
#define X10_INT_H_

#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang3Int9compareToEi, x10_int)
X10_MAKE_EQUALS(_ZN3x104lang3Int6equalsEi, x10_int)

// typename
x10_string *_ZN3x104lang3Int8typeNameEv(x10_int self) { 
	UNUSED(self); 
	return x10_string_from_wide_chars(T_("x10.lang.Int")); 
}

MAKE_INT_BINOPS(_ZN3x104lang3Int, i, x10_int)
MAKE_CMPOPS(_ZN3x104lang3Int, i, x10_int)
MAKE_INT_UNOPS(_ZN3x104lang3Int, v, x10_int)
x10_int _ZN3x104lang3Intv3rbsEi(x10_int a, x10_int b)
{
	return (x10_int) ((x10_uint) a >> (x10_uint) b);
}
MAKE_CONFS(_ZN3x104lang3Int, x10_int)

#endif // X10_INT_H_
