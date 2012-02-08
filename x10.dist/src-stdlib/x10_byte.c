#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

// compareTo from Comparable
X10_MAKE_COMPARETO(_ZN3x104lang4Byte9compareToEa, x10_byte)
X10_MAKE_HASHCODE(_ZN3x104lang4Byte8hashCodeEv, x10_byte)
X10_MAKE_EQUALS(_ZN3x104lang4Byte6equalsEa, x10_byte)
X10_MAKE_TOSTRING(_ZN3x104lang4Byte8toStringEv, x10_byte, "%d")

MAKE_INT_BINOPS2(_ZN3x104lang4Byte, a, x10_byte)

MAKE_CMPOPS(_ZN3x104lang4Byte, a, x10_byte)
MAKE_INT_UNOPS(_ZN3x104lang4Byte, v, x10_byte)

x10_byte _ZN3x104lang4Bytev3rbsEi(x10_byte a, x10_int b)
{
	return ((x10_byte)((x10_uint) (a) >> (0x7 & (b))));
}
MAKE_CONFS(_ZN3x104lang4Byte, x10_byte)

static x10_string *x10_byte_to_string(x10_byte value, x10_int radix)
{
    if (0 == value) return x10_string_from_wide_chars(T_("0"));
    assert(radix>=2);
    assert(radix<=16);
    static x10_char numerals[] = { '0', '1', '2', '3', '4', '5', '6', '7',
                                   '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    // worst case is binary -128: needs -, 8 digits, and a '\0'
    x10_char buf[10] = T_(""); //zeroes entire buffer (S6.7.8.21)
    x10_int value2;
    if (value < 0) {
        value2 = 0x80 - (value & 0x7F);
    } else {
        value2 = value;
    }
    x10_char *b;
    // start on the '\0', will predecrement so will not clobber it
    for (b=&buf[9] ; value2>0 ; value2/=radix) {
        *(--b) = numerals[value2 % radix];
    }
    if (value < 0) {
        *(--b) = '-';
    }
    return x10_string_from_wide_chars(b);
}

x10_string *_ZN3x104lang4Byte8toStringEi(x10_byte self, x10_int radix)
{
	return x10_byte_to_string(self, radix);
}

x10_string *_ZN3x104lang4Byte11toHexStringEv(x10_byte self)
{
	return x10_byte_to_string(self, 16);
}

x10_string *_ZN3x104lang4Byte13toOctalStringEv(x10_byte self)
{
	return x10_byte_to_string(self, 8);
}

x10_string *_ZN3x104lang4Byte14toBinaryStringEv(x10_byte self)
{
	return x10_byte_to_string(self, 2);
}

x10_byte _ZN3x104lang4Byte7reverseEv(x10_byte self)
{
	extern x10_int _ZN3x104lang3Int7reverseEv(x10_int);
	return _ZN3x104lang3Int7reverseEv(self) >> 24;
}

x10_int _ZN3x104lang4Byte6signumEv(x10_byte self)
{
	extern x10_int _ZN3x104lang3Int6signumEv(x10_int);
	return _ZN3x104lang3Int6signumEv(self);
}
