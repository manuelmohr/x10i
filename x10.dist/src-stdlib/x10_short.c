#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_TYPENAME(_ZN3x104lang5Short8typeNameEv, x10_short, "x10.lang.Short")

X10_MAKE_COMPARETO(_ZN3x104lang5Short9compareToEs, x10_short)
X10_MAKE_EQUALS(_ZN3x104lang5Short6equalsEs, x10_short)
X10_MAKE_HASHCODE(_ZN3x104lang5Short8hashCodeEv, x10_short)
X10_MAKE_TOSTRING(_ZN3x104lang5Short8toStringEv, x10_short, "%hd")
X10_MAKE_EQUALS_ANY(_ZN3x104lang5Short6equalsEPN3x104lang3AnyE, x10_short)

MAKE_INT_BINOPS2(_ZN3x104lang5Short, s, x10_short)
MAKE_CMPOPS(_ZN3x104lang5Short, s, x10_short)
MAKE_INT_UNOPS(_ZN3x104lang5Short, v, x10_short)
x10_short _ZN3x104lang5Shortv3rbsEi(x10_short a, x10_int b)
{
	return (x10_short) ((x10_uint) a >> (0xF & (b)));
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

x10_short _ZN3x104lang5Short12reverseBytesEv(x10_short self) 
{
    x10_ushort ux = (x10_ushort)self;
    x10_ushort b0 = ux & 0x0F;
    x10_ushort b1 = (ux & 0xF0) >> 8;
    ux = (b0 << 8) | b1;
    return (x10_short)ux;
}

x10_int _ZN3x104lang5Short6signumEv(x10_short self)
{
	extern x10_int _ZN3x104lang3Int6signumEv(x10_int);
	return _ZN3x104lang3Int6signumEv(self);
}

static x10_string *x10_short_to_string(x10_short value, x10_int radix) 
{
    if (0 == value) return x10_string_from_wide_chars(T_("0"));
    assert(radix>=2);
    assert(radix<=16);
    static x10_char numerals[] = { '0', '1', '2', '3', '4', '5', '6', '7',  
                               	  '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    // worst case is binary of Short.MIN_VALUE -- - plus 16 digits and a '\0'
    x10_char buf[18] = T_(""); //zeroes entire buffer (S6.7.8.21)
    x10_int value2;
    if (value < 0) {
        value2 = 0x8000 - (value & 0x7FFF);
    } else {
        value2 = value;
    }
    x10_char *b;
    // start on the '\0', will predecrement so will not clobber it
    for (b=&buf[17] ; value2>0 ; value2/=radix) {
        *(--b) = numerals[value2 % radix];
    }
    if (value < 0) {
        *(--b) = '-';
    }
    return x10_string_from_wide_chars(b);
}

x10_string *_ZN3x104lang5Short8toStringEi(x10_short self, x10_int radix) 
{
	return x10_short_to_string(self, radix);
}

x10_string *_ZN3x104lang5Short11toHexStringEv(x10_short self)
{
	return x10_short_to_string(self, 16);
}

x10_string *_ZN3x104lang5Short13toOctalStringEv(x10_short self)
{
	return x10_short_to_string(self, 8);
}

x10_string *_ZN3x104lang5Short14toBinaryStringEv(x10_short self)
{
	return x10_short_to_string(self, 2);
}

