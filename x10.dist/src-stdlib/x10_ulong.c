#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang5ULong9compareToEy, x10_ulong)
X10_MAKE_EQUALS(_ZN3x104lang5ULong6equalsEy, x10_ulong)
X10_MAKE_HASHCODE(_ZN3x104lang5ULong8hashCodeEv, x10_ulong)
X10_MAKE_TOSTRING(_ZN3x104lang5ULong8toStringEv, x10_ulong, "%lu")

MAKE_UNSIGNED_BINOPS(_ZN3x104lang5ULong, y, x, x10_ulong)
MAKE_CMPOPS(_ZN3x104lang5ULong, y, x10_ulong)
MAKE_INT_UNOPS(_ZN3x104lang5ULong, v, x10_ulong)
x10_ulong _ZN3x104lang5ULongv3rbsEi(x10_ulong a, x10_int b)
{
	return ((x10_ulong) ((a) >> (0x3f & (b))));
}
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

x10_ulong _ZN3x104lang5ULong12reverseBytesEv(x10_ulong self)
{
	extern x10_long _ZN3x104lang4Long12reverseBytesEv(x10_long);
	return (x10_ulong)_ZN3x104lang4Long12reverseBytesEv((x10_long)self);
}

x10_ulong _ZN3x104lang5ULong7reverseEv(x10_ulong self)
{
	extern x10_long _ZN3x104lang4Long7reverseEv(x10_long);
	return (x10_ulong)_ZN3x104lang4Long7reverseEv((x10_long)self);
}

x10_int _ZN3x104lang5ULong6signumEv(x10_ulong self)
{
	return self == 0 ? 0 : 1;
}

x10_ulong _ZN3x104lang5ULong11rotateRightEi(x10_ulong self, x10_int distance)
{
	extern x10_long _ZN3x104lang4Long11rotateRightEi(x10_long, x10_int);
	return (x10_ulong)_ZN3x104lang4Long11rotateRightEi((x10_long)self, distance);
}

x10_ulong _ZN3x104lang5ULong10rotateLeftEi(x10_ulong self, x10_int distance)
{
	extern x10_long _ZN3x104lang4Long10rotateLeftEi(x10_long, x10_int);
	return (x10_ulong)_ZN3x104lang4Long10rotateLeftEi((x10_long)self, distance);
}

x10_int _ZN3x104lang5ULong8bitCountEv(x10_ulong self)
{
	extern x10_int _ZN3x104lang4Long8bitCountEv(x10_long);
	return _ZN3x104lang4Long8bitCountEv((x10_long)self);
}

x10_int _ZN3x104lang5ULong21numberOfTrailingZerosEv(x10_ulong self)
{
	extern x10_int _ZN3x104lang4Long21numberOfTrailingZerosEv(x10_long);
	return _ZN3x104lang4Long21numberOfTrailingZerosEv((x10_long)self);
}

x10_int _ZN3x104lang5ULong20numberOfLeadingZerosEv(x10_ulong self)
{
	extern x10_int _ZN3x104lang4Long20numberOfLeadingZerosEv(x10_long);
	return _ZN3x104lang5ULong20numberOfLeadingZerosEv((x10_long)self);
}

x10_ulong _ZN3x104lang5ULong12lowestOneBitEv(x10_ulong self)
{
	extern x10_long _ZN3x104lang4Long12lowestOneBitEv(x10_long);
	return (x10_ulong)_ZN3x104lang4Long12lowestOneBitEv((x10_long)self);
}

x10_ulong _ZN3x104lang5ULong13highestOneBitEv(x10_ulong self)
{
	extern x10_long _ZN3x104lang4Long13highestOneBitEv(x10_long);
	return (x10_ulong)_ZN3x104lang4Long13highestOneBitEv((x10_long)self);
}

x10_string *_ZN3x104lang5ULong14toBinaryStringEv(x10_ulong self)
{
	extern x10_string *_ZN3x104lang4Long14toBinaryStringEv(x10_long);
	return _ZN3x104lang4Long14toBinaryStringEv((x10_long)self);
}

x10_string *_ZN3x104lang5ULong13toOctalStringEv(x10_ulong self)
{
	extern x10_string *_ZN3x104lang4Long13toOctalStringEv(x10_long);
	return _ZN3x104lang4Long13toOctalStringEv((x10_long)self);
}

x10_string *_ZN3x104lang5ULong11toHexStringEv(x10_ulong self)
{
	extern x10_string *_ZN3x104lang4Long11toHexStringEv(x10_long);
	return _ZN3x104lang4Long11toHexStringEv((x10_long)self);
}

x10_string *_ZN3x104lang5ULong8toStringEi(x10_ulong self, x10_int radix)
{
	extern x10_string *_ZN3x104lang4Long8toStringEi(x10_long, x10_int);
	return _ZN3x104lang4Long8toStringEi((x10_ulong)self, radix);
}

