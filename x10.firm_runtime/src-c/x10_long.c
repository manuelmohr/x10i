#include "x10.h"
#include "x10_string.h"

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
