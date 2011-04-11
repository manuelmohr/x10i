#ifndef X10_ULONG_H_
#define X10_ULONG_H_

#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang5ULong9compareToEy, x10_ulong)
X10_MAKE_EQUALS(_ZN3x104lang5ULong6equalsEy, x10_ulong)

// typename
x10_string *_ZN3x104lang5ULong8typeNameEv(x10_char self) { 
	UNUSED(self); 
	return x10_string_from_wide_chars(T_("x10.lang.ULong")); 
}

MAKE_INT_BINOPS(_ZN3x104lang5ULong, y, x10_ulong)
MAKE_CMPOPS(_ZN3x104lang5ULong, y, x10_ulong)
MAKE_INT_UNOPS(_ZN3x104lang5ULong, v, x10_ulong)
MAKE_CONFS(_ZN3x104lang5ULong, x10_ulong)


#endif // X10_ULONG_H_
