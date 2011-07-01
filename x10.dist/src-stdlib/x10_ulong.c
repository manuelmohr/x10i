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

x10_ulong _ZN3x104lang5ULong10parseULongEPN3x104lang6StringEi(x10_string *s, x10_int radix)
{
    x10_null_check(s); 
    const x10_char *start = x10_string_buf(s);
    x10_char *end;
    errno = 0;
    x10_uint ans = wcstoul(start, &end, radix);
    if (errno == ERANGE || (errno != 0 && ans == 0) || ((end-start) != x10_string_len(s))) {
       x10_throw_exception(X10_NUMBER_FORMAT_EXCEPTION, x10_string_buf(s)); 
    }
    return ans;
}

x10_ulong _ZN3x104lang5ULong10parseULongEPN3x104lang6StringE(x10_string *s)
{
    return _ZN3x104lang5ULong10parseULongEPN3x104lang6StringEi(s, 10); 
}
