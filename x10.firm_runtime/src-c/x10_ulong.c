#include "x10.h"
#include "x10_string.h"

x10_int _ZN3x104lang5ULong8bitCountEv(x10_ulong ux)
{
	return __builtin_popcountll(ux);
}

x10_int _ZN3x104lang5ULong21numberOfTrailingZerosEv(x10_ulong self)
{
	if (self == 0)
		return sizeof(self)*8;
	return __builtin_ctzll(self);
}

x10_int _ZN3x104lang5ULong20numberOfLeadingZerosEv(x10_ulong self)
{
	if (self == 0)
		return sizeof(self)*8;
	return __builtin_clzll(self);
}

x10_ulong _ZN3x104lang5ULong13highestOneBitEv(x10_ulong self)
{
	self |= (self >> 1);
	self |= (self >> 2);
	self |= (self >> 4);
	self |= (self >> 8);
	self |= (self >> 16);
	self |= (self >> 32);
	return self & ~(((x10_ulong)self) >> 1);
}
