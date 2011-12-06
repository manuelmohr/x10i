#include "x10.h"
#include "x10_primitive_types.h"

x10_long _ZN3x104lang11FirmPointer10native_ptrEv(x10_any *self) 
{
	return (x10_long)self;
}

x10_any *_ZN3x104lang11FirmPointer14getNullPointerEv()
{
	return X10_NULL;
}

x10_any *_ZN3x104lang11FirmPointerplEx(x10_any *self, x10_long bytes_diff)
{
	return (x10_any *)(((char *)self) + bytes_diff);
}

x10_any *_ZN3x104lang11FirmPointermiEx(x10_any *self, x10_long bytes_diff)
{
	return (x10_any *)(((char *)self) - bytes_diff);
}

x10_long _ZN3x104lang11FirmPointermiEN3x104lang11FirmPointerE(x10_any *self, x10_any *other)
{
	return (char *)self - (char *)other;
}

x10_boolean _ZN3x104lang11FirmPointerltEN3x104lang11FirmPointerE(x10_any *self, x10_any *other)
{
	return self < other;
}

x10_boolean _ZN3x104lang11FirmPointergtEN3x104lang11FirmPointerE(x10_any *self, x10_any *other)
{
	return self > other;
}

x10_boolean _ZN3x104lang11FirmPointerleEN3x104lang11FirmPointerE(x10_any *self, x10_any *other)
{
	return self <= other;
}

x10_boolean _ZN3x104lang11FirmPointergeEN3x104lang11FirmPointerE(x10_any *self, x10_any *other)
{
	return self >= other;
}

x10_int _ZN3x104lang11FirmPointer9compareToEN3x104lang11FirmPointerE(x10_any *self, x10_any *other)
{
	if(self < other) return -1;
	else if(self > other) return 1;
	return 0;
}

x10_any *_ZN3x104lang11FirmPointer5alignEN3x104lang11FirmPointerEi(x10_any *ptr, x10_int alignment)
{
   const uintptr_t alignDelta = alignment-1;
   const uintptr_t alignMask = ~alignDelta;
   return (x10_any *)(((uintptr_t)ptr + alignDelta) & alignMask);
}

