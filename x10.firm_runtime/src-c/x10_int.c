#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang3Int9compareToEi, x10_int)
X10_MAKE_HASHCODE(_ZN3x104lang3Int8hashCodeEv, x10_int)
X10_MAKE_EQUALS(_ZN3x104lang3Int6equalsEi, x10_int)
X10_MAKE_TOSTRING(_ZN3x104lang3Int8toStringEi, x10_int)
X10_MAKE_PARSE(_ZN3x104lang3Int5parseEPN3x104lang6StringEi, x10_int)

MAKE_INT_BINOPS(_ZN3x104lang3Int, i, x10_int)
MAKE_CMPOPS(_ZN3x104lang3Int, i, x10_int)
MAKE_INT_UNOPS(_ZN3x104lang3Int, v, x10_int)
x10_int _ZN3x104lang3Intv3rbsEi(x10_int a, x10_int b)
{
	return (x10_int) ((x10_uint) a >> (0x1F & (b)));
}
MAKE_CONFS(_ZN3x104lang3Int, x10_int)

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
