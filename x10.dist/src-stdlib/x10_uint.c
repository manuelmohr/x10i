#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang4UInt9compareToEj, x10_uint)
X10_MAKE_EQUALS(_ZN3x104lang4UInt6equalsEj, x10_uint)
X10_MAKE_HASHCODE(_ZN3x104lang4UInt8hashCodeEv, x10_uint)
X10_MAKE_TOSTRING(_ZN3x104lang4UInt8toStringEv, x10_uint, "%u")

MAKE_UNSIGNED_BINOPS(_ZN3x104lang4UInt, j, i, x10_uint)
MAKE_CMPOPS(_ZN3x104lang4UInt, j, x10_uint)
MAKE_INT_UNOPS(_ZN3x104lang4UInt, v, x10_uint)
x10_int _ZN3x104lang4UIntv3rbsEi(x10_uint a, x10_int b)
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
   return (x10_uint)_ZN3x104lang4UInt9parseUIntEPN3x104lang6StringEi(s, 10);
}

x10_uint _ZN3x104lang4UInt12reverseBytesEv(x10_uint self)
{
   extern x10_int _ZN3x104lang3Int12reverseBytesEv(x10_int);
	return (x10_uint)_ZN3x104lang3Int12reverseBytesEv((x10_int)self);
}

x10_int _ZN3x104lang4UInt6signumEv(x10_uint self)
{
	extern x10_int _ZN3x104lang3Int6signumEv(x10_int);
	return _ZN3x104lang3Int6signumEv((x10_int)self);
}

x10_uint _ZN3x104lang4UInt7reverseEv(x10_uint self)
{
	extern x10_int _ZN3x104lang3Int7reverseEv(x10_int);
	return (x10_uint)_ZN3x104lang3Int7reverseEv((x10_int)self);
}

x10_uint _ZN3x104lang4UInt11rotateRightEi(x10_uint self, x10_int distance)
{
	extern x10_int _ZN3x104lang3Int11rotateRightEi(x10_int, x10_int);
	return (x10_uint)_ZN3x104lang3Int11rotateRightEi((x10_int)self, distance);
}

x10_uint _ZN3x104lang4UInt10rotateLeftEi(x10_uint self, x10_int distance)
{
	extern x10_int _ZN3x104lang3Int10rotateLeftEi(x10_int, x10_int);
	return (x10_uint)_ZN3x104lang3Int10rotateLeftEi((x10_int)self, distance);
}

x10_int _ZN3x104lang4UInt8bitCountEv(x10_uint self)
{
	extern x10_int _ZN3x104lang3Int8bitCountEv(x10_int);
	return _ZN3x104lang3Int8bitCountEv((x10_int)self);
}

x10_int _ZN3x104lang4UInt21numberOfTrailingZerosEv(x10_uint self)
{
	extern x10_int _ZN3x104lang3Int21numberOfTrailingZerosEv(x10_int);
	return _ZN3x104lang3Int21numberOfTrailingZerosEv((x10_int)self);
}

x10_int _ZN3x104lang4UInt20numberOfLeadingZerosEv(x10_uint self)
{
	extern x10_int _ZN3x104lang3Int20numberOfLeadingZerosEv(x10_int);
	return _ZN3x104lang3Int20numberOfLeadingZerosEv((x10_int)self);
}

x10_uint _ZN3x104lang4UInt13highestOneBitEv(x10_uint self)
{
	extern x10_int _ZN3x104lang3Int13highestOneBitEv(x10_int);
	return (x10_uint)_ZN3x104lang3Int13highestOneBitEv((x10_int)self);
}

x10_uint _ZN3x104lang4UInt12lowestOneBitEv(x10_uint self)
{
	extern x10_int _ZN3x104lang3Int12lowestOneBitEv(x10_int);
	return (x10_uint)_ZN3x104lang3Int12lowestOneBitEv((x10_int)self);
}

x10_string *_ZN3x104lang4UInt8toStringEi(x10_uint self, x10_int radix)
{
	extern x10_string *_ZN3x104lang3Int8toStringEi(x10_int, x10_int);
	return _ZN3x104lang3Int8toStringEi((x10_int)self, radix);
}

x10_string *_ZN3x104lang4UInt14toBinaryStringEv(x10_uint self)
{
	extern x10_string *_ZN3x104lang3Int14toBinaryStringEv(x10_int);
	return _ZN3x104lang3Int14toBinaryStringEv((x10_int)self);
}

x10_string *_ZN3x104lang4UInt13toOctalStringEv(x10_uint self)
{
	extern x10_string *_ZN3x104lang3Int13toOctalStringEv(x10_int);
	return _ZN3x104lang3Int13toOctalStringEv((x10_int)self);
}

x10_string *_ZN3x104lang4UInt11toHexStringEv(x10_uint self)
{
	extern x10_string *_ZN3x104lang3Int11toHexStringEv(x10_int);
	return _ZN3x104lang3Int11toHexStringEv((x10_int)self);
}




