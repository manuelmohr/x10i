#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang6UShort9compareToEt, x10_ushort)
X10_MAKE_EQUALS(_ZN3x104lang6UShort6equalsEt, x10_ushort)
X10_MAKE_HASHCODE(_ZN3x104lang6UShort8hashCodeEv, x10_ushort)
X10_MAKE_TOSTRING(_ZN3x104lang6UShort8toStringEv, x10_ushort, "%hu")

MAKE_UNSIGNED_BINOPS(_ZN3x104lang6UShort, t, s, x10_ushort)
MAKE_CMPOPS(_ZN3x104lang6UShort, t, x10_ushort)
MAKE_INT_UNOPS(_ZN3x104lang6UShort, v, x10_ushort)
x10_ushort _ZN3x104lang6UShortv3rbsEi(x10_ushort a, x10_int b)
{
	return ((x10_ushort) ((a) >> (0xf & (b))));
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

x10_string *_ZN3x104lang6UShort8toStringEi(x10_ushort self, x10_int radix)
{
	extern x10_string *_ZN3x104lang3Int8toStringEi(x10_int, x10_int);
	return _ZN3x104lang3Int8toStringEi(self, radix);
}

x10_string *_ZN3x104lang6UShort13toOctalStringEv(x10_ushort self)
{
	extern x10_string *_ZN3x104lang3Int13toOctalStringEv(x10_int);
	return _ZN3x104lang3Int13toOctalStringEv(self);
}

x10_string *_ZN3x104lang6UShort14toBinaryStringEv(x10_ushort self)
{
	extern x10_string *_ZN3x104lang3Int14toBinaryStringEv(x10_int);
	return _ZN3x104lang3Int14toBinaryStringEv(self);
}

x10_string *_ZN3x104lang6UShort11toHexStringEv(x10_ushort self)
{
	extern x10_string *_ZN3x104lang3Int11toHexStringEv(x10_int);
	return _ZN3x104lang3Int11toHexStringEv(self);
}

x10_int _ZN3x104lang6UShort6signumEv(x10_ushort self)
{
	return self == 0 ? 0 : 1;
}

x10_ushort _ZN3x104lang6UShort12reverseBytesEv(x10_ushort self)
{
	extern x10_int _ZN3x104lang3Int12reverseBytesEv(x10_int);
	return (x10_ushort)_ZN3x104lang3Int12reverseBytesEv((x10_short)self);
}

x10_ushort _ZN3x104lang6UShort7reverseEv(x10_ushort self)
{
	extern x10_int _ZN3x104lang3Int7reverseEv(x10_int);
	return (x10_ushort)(_ZN3x104lang3Int7reverseEv((x10_short)self) >> 16);
}


