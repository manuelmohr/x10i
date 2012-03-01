#include "x10_nativesupport.h"
#include <string.h>

/* memcmp */
x10_boolean _ZN3x104lang13NativeSupport6memcmpEPvPvi(x10_pointer ptr1, x10_pointer ptr2, x10_int bytes)
{
	return memcmp(ptr1, ptr2, bytes) == 0;
}

/* memcpy */
void _ZN3x104lang13NativeSupport6memcpyEPvPvib(x10_pointer dst, x10_pointer src, x10_int bytes, x10_boolean overlap)
{
	if(overlap) {
		memmove(dst, src, bytes);
	} else {
		memcpy(dst, src, bytes);
	}
}

/* memset */
void _ZN3x104lang13NativeSupport6memsetEPvii(x10_pointer dest, x10_int c, x10_int bytes)
{
	memset(dest, c, bytes);
}

/** allocation of memory; the returned memory pointer is not aligned !!! (Use align_ptr for alignment of pointers) */
x10_pointer _ZN3x104lang13NativeSupport5allocEiibb(x10_int numBytes, x10_int alignment, x10_boolean congruent, x10_boolean zeroed)
{
	x10_pointer ret = X10_NULL;
	if(congruent) {
		assert(false && "No support for congruent memory allocation yet");
	} else {
		const x10_int size = numBytes + alignment;
		ret = x10_malloc(size);
		if(zeroed)
		memset(ret, 0, size);
	}
	assert(ret != X10_NULL);
	return ret;
}

/** deallocation of memory; The given memory pointer must be the real memory pointer returned by "alloc"; (not the aligned) */
void _ZN3x104lang13NativeSupport7deallocEPv(x10_pointer ptr)
{
	assert(ptr != NULL);
	x10_free(ptr);
}
