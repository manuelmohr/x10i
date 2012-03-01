#include "x10.h"
#include "x10_string.h"

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
