#include "x10_firmsupport.h"

/* memcmp */
x10_boolean _ZN3x104lang14X10FirmSupport6memcmpEN3x104lang11FirmPointerEN3x104lang11FirmPointerEx(x10_any *ptr1, x10_any *ptr2, x10_long bytes)
{
	return memcmp((const void *)ptr1, (const void *)ptr2, bytes) == 0;
}

/* memcpy */
void _ZN3x104lang14X10FirmSupport6memcpyEN3x104lang11FirmPointerEN3x104lang11FirmPointerExb(x10_any *dst, x10_any *src, x10_long bytes, x10_boolean overlap)
{
	if(overlap) {
		memmove((void *)dst, (const void *)src, bytes);
	} else {
		memcpy((void *)dst, (const void *)src, bytes);
	}
}

/* memset */
void _ZN3x104lang14X10FirmSupport6memsetEN3x104lang11FirmPointerEix(x10_any *dest, x10_int c, x10_long bytes)
{
	memset(dest, c, bytes);
}

/** allocation of memory; the returned memory pointer is not aligned !!! (Use align_ptr for alignment of pointers) */
x10_any *_ZN3x104lang14X10FirmSupport5allocExibb(x10_long numBytes, x10_int alignment, x10_boolean congruent, x10_boolean zeroed)
{
	x10_any *ret = X10_NULL;
	if(congruent) {
		assert(false && "No support for congruent memory allocation yet");
	} else {
		const x10_long size = numBytes + alignment;
		ret = x10_malloc(size);
		if(zeroed)
		memset(ret, 0, size);
	}
	assert(ret != X10_NULL);
	return ret;
}

/** deallocation of memory; The given memory pointer must be the real memory pointer returned by "alloc"; (not the aligned) */
void _ZN3x104lang14X10FirmSupport7deallocEN3x104lang11FirmPointerE(x10_any *ptr)
{
	assert(ptr != NULL);
	x10_free(ptr);
}
