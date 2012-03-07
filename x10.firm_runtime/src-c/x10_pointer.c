#include "x10.h"

x10_pointer _ZN3x104lang7Pointer14getNullPointerEv()
{
	return (x10_pointer)0;
}

x10_pointer _ZN3x104lang7Pointer5alignEPvi(x10_pointer ptr, x10_int alignment)
{
   const uintptr_t alignDelta = alignment-1;
   const uintptr_t alignMask = ~alignDelta;
   return (x10_pointer)(((uintptr_t)ptr + alignDelta) & alignMask);
}

x10_string *_ZN3x104lang7Pointer8toStringEv(x10_pointer ptr)
{
	char buf[20];
	snprintf(buf, sizeof(buf), "%p", ptr);
	return x10_string_from_cstring(buf);
}
