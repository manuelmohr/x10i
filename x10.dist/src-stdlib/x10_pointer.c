#include "x10.h"
#include "x10_primitive_types.h"

x10_int _ZN3x104lang7Pointer8hashCodeEv(x10_pointer self)
{
	return (x10_int)(intptr_t)self;
}

x10_pointer _ZN3x104lang7Pointer14getNullPointerEv()
{
	return (x10_pointer)0;
}

x10_pointer _ZN3x104lang7PointerplEx(x10_pointer self, x10_long bytes_diff)
{
	return self + bytes_diff;
}

x10_pointer _ZN3x104lang7PointermiEx(x10_pointer self, x10_long bytes_diff)
{
	return self - bytes_diff;
}

x10_long _ZN3x104lang7PointermiEN3x104lang7PointerE(x10_pointer self,
                                                    x10_pointer other)
{
	return (x10_long)(self - other);
}

x10_boolean _ZN3x104lang7PointerltEN3x104lang7PointerE(x10_pointer self,
                                                       x10_pointer other)
{
	return self < other;
}

x10_boolean _ZN3x104lang7PointergtEN3x104lang7PointerE(x10_pointer self,
                                                       x10_pointer other)
{
	return self > other;
}

x10_boolean _ZN3x104lang7PointerleEN3x104lang7PointerE(x10_pointer self,
                                                       x10_pointer other)
{
	return self <= other;
}

x10_boolean _ZN3x104lang7PointergeEN3x104lang7PointerE(x10_pointer self,
                                                       x10_pointer other)
{
	return self >= other;
}

x10_int _ZN3x104lang7Pointer9compareToEN3x104lang7PointerE(x10_pointer self,
                                                           x10_pointer other)
{
	if(self < other) return -1;
	else if(self > other) return 1;
	return 0;
}

x10_pointer _ZN3x104lang7Pointer5alignEN3x104lang7PointerEi(x10_pointer ptr,
                                                            x10_int alignment)
{
   const uintptr_t alignDelta = alignment-1;
   const uintptr_t alignMask = ~alignDelta;
   return (x10_pointer)(((uintptr_t)ptr + alignDelta) & alignMask);
}