#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang5Float9compareToEf, x10_float)
X10_MAKE_HASHCODE(_ZN3x104lang5Float8hashCodeEv, x10_float)
X10_MAKE_EQUALS(_ZN3x104lang5Float6equalsEf, x10_float)
X10_MAKE_TYPENAME(_ZN3x104lang5Float8typeNameEv, x10_float, "x10.lang.Float")
X10_MAKE_EQUALS_ANY(_ZN3x104lang5Float6equalsEPN3x104lang3AnyE, x10_float)

/* Just call the toString() function for double */
X10_EXTERN x10_string *_ZN3x104lang6Double8toStringEv(x10_double);
x10_string *_ZN3x104lang5Float8toStringEv(x10_float v)
{
	return _ZN3x104lang6Double8toStringEv((x10_double) v);
}

MAKE_BINOPS(_ZN3x104lang5Float, f, x10_float)
MAKE_CMPOPS(_ZN3x104lang5Float, f, x10_float)
MAKE_UNOPS(_ZN3x104lang5Float, v, x10_float)
x10_float _ZN3x104lang5FloatrmEf(x10_float a, x10_float b)
{
	return fmodf(a, b);
}
MAKE_CONFS(_ZN3x104lang5Float, x10_float)

/* Use to move bits between x10_float/x10_int without confusing the compiler */
typedef union TypePunner {
    x10_int i;
    x10_float f;
} TypePunner;

x10_int _ZN3x104lang5Float12toRawIntBitsEv(x10_float self) 
{
    TypePunner tmp;
    tmp.f = self;
    return tmp.i;
}

x10_float _ZN3x104lang5Float11fromIntBitsEi(x10_int digits)
{
	TypePunner tmp;
	tmp.i = digits;
	return tmp.f;
}


