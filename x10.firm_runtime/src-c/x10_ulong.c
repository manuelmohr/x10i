#include "x10.h"
#include "x10_string.h"

x10_int _ZN3x104lang5ULong8bitCountEv(x10_ulong self)
{
	extern x10_int _ZN3x104lang4Long8bitCountEv(x10_long);
	return _ZN3x104lang4Long8bitCountEv((x10_long)self);
}

x10_int _ZN3x104lang5ULong21numberOfTrailingZerosEv(x10_ulong self)
{
	extern x10_int _ZN3x104lang4Long21numberOfTrailingZerosEv(x10_long);
	return _ZN3x104lang4Long21numberOfTrailingZerosEv((x10_long)self);
}

x10_int _ZN3x104lang5ULong20numberOfLeadingZerosEv(x10_ulong self)
{
	extern x10_int _ZN3x104lang4Long20numberOfLeadingZerosEv(x10_long);
	return _ZN3x104lang5ULong20numberOfLeadingZerosEv((x10_long)self);
}

x10_ulong _ZN3x104lang5ULong12lowestOneBitEv(x10_ulong self)
{
	extern x10_long _ZN3x104lang4Long12lowestOneBitEv(x10_long);
	return (x10_ulong)_ZN3x104lang4Long12lowestOneBitEv((x10_long)self);
}

x10_ulong _ZN3x104lang5ULong13highestOneBitEv(x10_ulong self)
{
	extern x10_long _ZN3x104lang4Long13highestOneBitEv(x10_long);
	return (x10_ulong)_ZN3x104lang4Long13highestOneBitEv((x10_long)self);
}
