#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang3Int9compareToEi, x10_int)
X10_MAKE_HASHCODE(_ZN3x104lang3Int8hashCodeEv, x10_int)
X10_MAKE_EQUALS(_ZN3x104lang3Int6equalsEi, x10_int)
X10_MAKE_TOSTRING(_ZN3x104lang3Int8toStringEv, x10_int, "%d")

MAKE_INT_BINOPS(_ZN3x104lang3Int, i, x10_int)
MAKE_CMPOPS(_ZN3x104lang3Int, i, x10_int)
MAKE_INT_UNOPS(_ZN3x104lang3Int, v, x10_int)
x10_int _ZN3x104lang3Intv3rbsEi(x10_int a, x10_int b)
{
	return (x10_int) ((x10_uint) a >> (0x1F & (b)));
}
MAKE_CONFS(_ZN3x104lang3Int, x10_int)

x10_int _ZN3x104lang3Int8parseIntEPN3x104lang6StringEi(x10_string *s, x10_int radix)
{
    x10_null_check(s); 
    const x10_char *start = x10_string_buf(s); 
    x10_char *end;
    errno = 0;
    x10_int ans = wcstol(start, &end, radix);
    if (errno == ERANGE || (errno != 0 && ans == 0) || ((end-start) != x10_string_len(s))) {
	    x10_throw_exception(X10_NUMBER_FORMAT_EXCEPTION, x10_string_buf(s)); 
    }
    return ans;
}

x10_int _ZN3x104lang3Int8parseIntEPN3x104lang6StringE(x10_string *s)
{
	return _ZN3x104lang3Int8parseIntEPN3x104lang6StringEi(s, 10); 
}

x10_int _ZN3x104lang3Int5parseEPN3x104lang6StringE(x10_string *s)
{
	return _ZN3x104lang3Int8parseIntEPN3x104lang6StringEi(s, 10); 
}

x10_int _ZN3x104lang3Int5parseEPN3x104lang6StringEi(x10_string *s, x10_int radix)
{
	return _ZN3x104lang3Int8parseIntEPN3x104lang6StringEi(s, radix); 
}

x10_int _ZN3x104lang3Int6signumEv(x10_int self)
{
	return (self >> 31) | (((x10_uint)(-self)) >> 31);
}

x10_int _ZN3x104lang3Int12reverseBytesEv(x10_int self) 
{
    x10_long value = 0;
    if (self<0) {
        value = 0x80000000;
        self &= 0x7FFFFFFF;
    }
    value += self;
    x10_long b0 = value & 0x000000FF;
    x10_long b1 = value & 0x0000FF00;
    x10_long b2 = value & 0x00FF0000;
    x10_long b3 = value & 0xFF000000;
    // reverse bytes
    b0 <<= 24; b1 <<= 8; b2 >>= 8; b3 >>= 24;
    return b0 | b1 | b2 | b3;
}

x10_int _ZN3x104lang3Int7reverseEv(x10_int self) 
{
    x10_uint ux = (x10_uint)self;
    ux = ((ux & 0x55555555) << 1) | ((ux >> 1) & 0x55555555);
    ux = ((ux & 0x33333333) << 2) | ((ux >> 2) & 0x33333333);
    ux = ((ux & 0x0F0F0F0F) << 4) | ((ux >> 4) & 0x0F0F0F0F);
    ux = (ux << 24) | ((ux & 0xFF00) << 8) | ((ux >> 8) & 0xFF00) | (ux >> 24);
    return (x10_int)ux;
}

x10_int _ZN3x104lang3Int11rotateRightEi(x10_int self, x10_int distance) 
{
   return (((x10_uint)self) >> distance) | (self << (32 - distance));
}

x10_int _ZN3x104lang3Int10rotateLeftEi(x10_int self, x10_int distance)
{
    return (self << distance) | (((x10_uint)self) >> (32 - distance));
}

x10_int _ZN3x104lang3Int8bitCountEv(x10_int self)
{
    x10_uint ux = (x10_uint)self;
    ux = ux - ((ux >> 1) & 0x55555555);
    ux = (ux & 0x33333333) + ((ux >> 2) & 0x33333333);
    ux = (ux + (ux >> 4)) & 0x0F0F0F0F;
    ux = ux + (ux >> 8);
    ux = ux + (ux >> 16);
    return (x10_int)(ux & 0x3F);
}

x10_int _ZN3x104lang3Int21numberOfTrailingZerosEv(x10_int self)
{
   return _ZN3x104lang3Int8bitCountEv(~self & (self-1));
}

x10_int _ZN3x104lang3Int20numberOfLeadingZerosEv(x10_int self)
{
    self |= (self >> 1);
    self |= (self >> 2);
    self |= (self >> 4);
    self |= (self >> 8);
    self |= (self >> 16);
    return _ZN3x104lang3Int8bitCountEv(~self);
}

x10_int _ZN3x104lang3Int12lowestOneBitEv(x10_int self)
{
   return self & (-self);
}

x10_int _ZN3x104lang3Int13highestOneBitEv(x10_int self)
{
    self |= (self >> 1);
    self |= (self >> 2);
    self |= (self >> 4);
    self |= (self >> 8);
    self |= (self >> 16);
    return self & ~(((x10_uint)self) >> 1);
}

static x10_string *x10_int_to_string(x10_int value, x10_int radix) 
{
    if (0 == value) return x10_string_from_wide_chars(T_("0"));
    assert(radix>=2);
    assert(radix<=36);
    static x10_char numerals[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
                               	  'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                               	  'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                               	  'x', 'y', 'z' };
    // worst case is binary of Int.MIN_VALUE -- - plus 32 digits and a '\0'
    x10_char buf[34] = T_(""); //zeroes entire buffer (S6.7.8.21)
    x10_long value2 = 0;
    if (value<0) {
        value2 = 0x80000000;
        value &= 0x7FFFFFFF;
    }
    value2 += value;
    x10_char *b;
    // start on the '\0', will predecrement so will not clobber it
    for (b=&buf[33] ; value2>0 ; value2/=radix) {
        *(--b) = numerals[value2 % radix];
    }
    return x10_string_from_wide_chars(b);
}

x10_string *_ZN3x104lang3Int8toStringEi(x10_int self, x10_int radix) 
{
	return x10_int_to_string(self, radix);
}

x10_string *_ZN3x104lang3Int11toHexStringEv(x10_int self)
{
	return x10_int_to_string(self, 16);
}

x10_string *_ZN3x104lang3Int13toOctalStringEv(x10_int self)
{
	return x10_int_to_string(self, 8);
}

x10_string *_ZN3x104lang3Int14toBinaryStringEv(x10_int self)
{
	return x10_int_to_string(self, 2);
}

