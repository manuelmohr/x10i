#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang5Short9compareToEs, x10_short)
X10_MAKE_EQUALS(_ZN3x104lang5Short6equalsEs, x10_short)
X10_MAKE_HASHCODE(_ZN3x104lang5Short8hashCodeEv, x10_short)
X10_MAKE_TOSTRING(_ZN3x104lang5Short8toStringEv, x10_short, "%hd")
X10_MAKE_TYPENAME(_ZN3x104lang5Short8typeNameEv, x10_short, "x10.lang.Short")
X10_MAKE_EQUALS_ANY(_ZN3x104lang5Short6equalsEPN3x104lang3AnyE, x10_short)

MAKE_INT_BINOPS(_ZN3x104lang5Short, s, x10_short)
MAKE_CMPOPS(_ZN3x104lang5Short, s, x10_short)
MAKE_INT_UNOPS(_ZN3x104lang5Short, v, x10_short)
x10_short _ZN3x104lang5Shortv3rbsEs(x10_short a, x10_short b)
{
	return (x10_short) ((x10_ushort) a >> (x10_ushort) b);
}
MAKE_CONFS(_ZN3x104lang5Short, x10_short)

x10_short _ZN3x104lang5Short7reverseEv(x10_short self)
{
    x10_ushort ux = (x10_ushort)self;
    x10_ushort b0 = ux & 0x0F;
    x10_ushort b1 = (ux & 0xF0) >> 8;
    ux = (b0 << 8) | b1;
    return (x10_short)ux;
}

x10_short _ZN3x104lang5Short10parseShortEPN3x104lang6StringEi(x10_string *s, x10_int radix)
{
    x10_null_check(s); 
    const x10_char *start = x10_string_buf(s); 
    x10_char *end;
    errno = 0;
    x10_int ans = wcstol(start, &end, radix);
    if (errno == ERANGE || (errno != 0 && ans == 0) || (ans != (x10_short)ans) || ((end-start) != x10_string_len(s))) {
        x10_throw_exception(X10_NUMBER_FORMAT_EXCEPTION, x10_string_buf(s));
    }
    return (x10_short)ans;
}

x10_short _ZN3x104lang5Short10parseShortEPN3x104lang6StringE(x10_string *s)
{
	return _ZN3x104lang5Short10parseShortEPN3x104lang6StringEi(s, 10); 
}


