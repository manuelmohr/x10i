#include "types.h"

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

x10_pointer x10_asPointer(x10_any *any)
{
	return any;
}

x10_int _ZN3x104lang7Pointer8hashCodeEv(x10_pointer ptr)
{
#ifdef __x86_64__
	uintptr_t val  = (uintptr_t)ptr;
	x10_int   hash = 17;
	hash = hash * 31 + (x10_int)(val >> 32);
	hash = hash * 31 + (x10_int)(val & 0xFFFFFFFFU);
	return hash;
#else
	return (x10_int)ptr;
#endif
}
