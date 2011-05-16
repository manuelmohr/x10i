#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang5ULong9compareToEy, x10_ulong)
X10_MAKE_EQUALS(_ZN3x104lang5ULong6equalsEy, x10_ulong)
X10_MAKE_HASHCODE(_ZN3x104lang5ULong8hashCodeEv, x10_ulong)
X10_MAKE_TOSTRING(_ZN3x104lang5ULong8toStringEv, x10_ulong, "%lu")
X10_MAKE_TYPENAME(_ZN3x104lang5ULong8typeNameEv, x10_ulong, "x10.lang.ULong")
X10_MAKE_EQUALS_ANY(_ZN3x104lang5ULong6equalsEPN3x104lang3AnyE, x10_ulong)

MAKE_INT_BINOPS(_ZN3x104lang5ULong, y, x10_ulong)
MAKE_CMPOPS(_ZN3x104lang5ULong, y, x10_ulong)
MAKE_INT_UNOPS(_ZN3x104lang5ULong, v, x10_ulong)
MAKE_CONFS(_ZN3x104lang5ULong, x10_ulong)
