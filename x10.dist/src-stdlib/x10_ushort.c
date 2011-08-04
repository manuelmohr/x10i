#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_TYPENAME(_ZN3x104lang6UShort8typeNameEv, x10_ushort, "x10.lang.UShort")

X10_MAKE_COMPARETO(_ZN3x104lang6UShort9compareToEt, x10_ushort)
X10_MAKE_EQUALS(_ZN3x104lang6UShort6equalsEt, x10_ushort)
X10_MAKE_HASHCODE(_ZN3x104lang6UShort8hashCodeEv, x10_ushort)
X10_MAKE_TOSTRING(_ZN3x104lang6UShort8toStringEv, x10_ushort, "%hu")
X10_MAKE_EQUALS_ANY(_ZN3x104lang6UShort6equalsEPN3x104lang3AnyE, x10_ushort)


MAKE_INT_BINOPS(_ZN3x104lang6UShort, t, x10_ushort)
MAKE_CMPOPS(_ZN3x104lang6UShort, t, x10_ushort)
MAKE_INT_UNOPS(_ZN3x104lang6UShort, v, x10_ushort)
x10_ushort _ZN3x104lang6UShortv3rbsEs(x10_ushort a, x10_ushort b)
{
	return a >> b;
}
MAKE_CONFS(_ZN3x104lang6UShort, x10_ushort)

x10_short _ZN3x104lang6UShort11parseUShortEPN3x104lang6StringEi(x10_string *s, x10_int radix)
{
    x10_null_check(s); 
    const x10_char *start = x10_string_buf(s);
    x10_char *end;
    errno = 0;
    x10_uint ans = wcstoul(start, &end, radix);
    if (errno == ERANGE || (errno != 0 && ans == 0) || (ans != (x10_ushort)ans) || ((end-start) != x10_string_len(s))) {
        x10_throw_exception(X10_NUMBER_FORMAT_EXCEPTION, x10_string_buf(s)); 
    }
    return (x10_ushort)ans;
}

x10_ushort _ZN3x104lang6UShort11parseUShortEPN3x104lang6StringE(x10_string *s)
{
    return _ZN3x104lang6UShort11parseUShortEPN3x104lang6StringEi(s, 10); 
}
