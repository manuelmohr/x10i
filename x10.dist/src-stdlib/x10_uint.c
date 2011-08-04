#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_TYPENAME(_ZN3x104lang4UInt8typeNameEv, x10_uint, "x10.lang.UInt")

X10_MAKE_COMPARETO(_ZN3x104lang4UInt9compareToEj, x10_uint)
X10_MAKE_EQUALS(_ZN3x104lang4UInt6equalsEj, x10_uint)
X10_MAKE_HASHCODE(_ZN3x104lang4UInt8hashCodeEv, x10_uint)
X10_MAKE_TOSTRING(_ZN3x104lang4UInt8toStringEv, x10_uint, "%u")
X10_MAKE_EQUALS_ANY(_ZN3x104lang4UInt6equalsEPN3x104lang3AnyE, x10_uint)

MAKE_INT_BINOPS(_ZN3x104lang4UInt, j, x10_uint)
MAKE_CMPOPS(_ZN3x104lang4UInt, j, x10_uint)
MAKE_INT_UNOPS(_ZN3x104lang4UInt, v, x10_uint)
x10_int _ZN3x104lang4UIntv3rbsEi(x10_uint a, x10_uint b)
{
	return (x10_int) ((x10_uint) a >> (x10_uint) b);
}
MAKE_CONFS(_ZN3x104lang4UInt, x10_uint)

x10_uint _ZN3x104lang4UInt9parseUIntEPN3x104lang6StringEi(x10_string *s, x10_int radix)
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

x10_uint _ZN3x104lang4UInt9parseUIntEPN3x104lang6StringE(x10_string *s)
{
    return _ZN3x104lang4UInt9parseUIntEPN3x104lang6StringEi(s, 10); 
}
