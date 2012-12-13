#include "x10.h"
#include "x10_string.h"

x10_int _ZN3x104lang4UInt8bitCountEv(x10_uint ux)
{
	return __builtin_popcount(ux);
}

x10_int _ZN3x104lang4UInt21numberOfTrailingZerosEv(x10_uint self)
{
	if (self == 0)
		return sizeof(self)*8;
	return __builtin_ctz(self);
}

x10_int _ZN3x104lang4UInt20numberOfLeadingZerosEv(x10_uint self)
{
	if (self == 0)
		return sizeof(self)*8;
	return __builtin_clz(self);
}

x10_uint _ZN3x104lang4UInt13highestOneBitEv(x10_uint self)
{
	self |= (self >> 1);
	self |= (self >> 2);
	self |= (self >> 4);
	self |= (self >> 8);
	self |= (self >> 16);
	return self & ~(((x10_uint)self) >> 1);
}
