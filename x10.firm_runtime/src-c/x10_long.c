#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang4Long9compareToEx, x10_long)
X10_MAKE_EQUALS(_ZN3x104lang4Long6equalsEx, x10_long)
X10_MAKE_HASHCODE(_ZN3x104lang4Long8hashCodeEv, x10_long)
X10_MAKE_TOSTRING(_ZN3x104lang4Long8toStringEi, x10_long)
X10_MAKE_PARSE(_ZN3x104lang4Long5parseEPN3x104lang6StringEi, x10_long)

MAKE_INT_BINOPS2(_ZN3x104lang4Long, x, x10_long)
MAKE_CMPOPS(_ZN3x104lang4Long, x, x10_long)
MAKE_INT_UNOPS(_ZN3x104lang4Long, v, x10_long)
x10_long _ZN3x104lang4Longv3rbsEi(x10_long a, x10_int b)
{
	return ((x10_long)((x10_ulong) (a) >> (0x3f & (b))));
}
MAKE_CONFS(_ZN3x104lang4Long, x10_long)

x10_long _ZN3x104lang4Long13highestOneBitEv(x10_long self)
{
    self |= (self >> 1);
    self |= (self >> 2);
    self |= (self >> 4);
    self |= (self >> 8);
    self |= (self >> 16);
    self |= (self >> 32);
    return self & ~(((x10_ulong)self) >> 1);
}

x10_long _ZN3x104lang4Long12lowestOneBitEv(x10_long self)
{
   return self & (-self);
}

x10_int _ZN3x104lang4Long8bitCountEv(x10_long self)
{
    x10_ulong ux = (x10_ulong)self;
    ux = ux - ((ux >> 1) & 0x5555555555555555LL);
    ux = (ux & 0x3333333333333333LL) + ((ux >> 2) & 0x3333333333333333LL);
    ux = (ux & 0x0F0F0F0F0F0F0F0FLL) + ((ux >> 4) & 0x0F0F0F0F0F0F0F0FLL);
    ux = (ux & 0x00FF00FF00FF00FFLL) + ((ux >> 8) & 0x00FF00FF00FF00FFLL);
    ux = ux + (ux >> 16);
    ux = ux + (ux >> 32);
    return (x10_int)(ux & 0x7F);
}

x10_int _ZN3x104lang4Long20numberOfLeadingZerosEv(x10_long self)
{
    self |= (self >> 1);
    self |= (self >> 2);
    self |= (self >> 4);
    self |= (self >> 8);
    self |= (self >> 16);
    self |= (self >> 32);
    return _ZN3x104lang4Long8bitCountEv(~self);
}

x10_int _ZN3x104lang4Long21numberOfTrailingZerosEv(x10_long self)
{
   return _ZN3x104lang4Long8bitCountEv(~self & (self-1));
}

x10_long _ZN3x104lang4Long12reverseBytesEv(x10_long self)
{
    x10_ulong ux = self;
    x10_ulong ans = ux << 56;
    ans |= (ux & 0xFF00L) << 40;
    ans |= (ux & 0xFF0000L) << 24;
    ans |= (ux & 0xFF000000L) << 8;
    ans |= (ux >> 8) & 0xFF000000L;
    ans |= (ux >> 24) & 0xFF0000L;
    ans |= (ux >> 40) & 0xFF00L;
    ans |= (ux >> 56);
    return (x10_long)ans;
}
