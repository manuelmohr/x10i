#include <string.h>
#include "types.h"
#include "xmalloc.h"

/* static x10.lang.NativeSupport.memcmp(Pointer,Pointer,Int): Int */
x10_int _ZN3x104lang13NativeSupport6memcmpEPvPvi(x10_pointer ptr1, x10_pointer ptr2, x10_int numBytes)
{
	return memcmp(ptr1, ptr2, numBytes);
}

/* static x10.lang.NativeSupport.memcpy(Pointer,Pointer,Int) */
void _ZN3x104lang13NativeSupport6memcpyEPvPvi(x10_pointer dst, x10_pointer src, x10_int numBytes)
{
	memcpy(dst, src, numBytes);
}

/* static x10.lang.NativeSupport.memmove(Pointer,Pointer,Int) */
void _ZN3x104lang13NativeSupport7memmoveEPvPvi(x10_pointer dst, x10_pointer src, x10_int numBytes)
{
	memmove(dst, src, numBytes);
}

/* static x10.lang.NativeSupport.memset(Pointer,Int,Int) */
void _ZN3x104lang13NativeSupport6memsetEPvii(x10_pointer dest, x10_int c, x10_int numBytes)
{
	memset(dest, c, numBytes);
}

/* static x10.lang.NativeSupport.alloc(UInt): Pointer */
x10_pointer _ZN3x104lang13NativeSupport5allocEi(x10_int numBytes)
{
	return gc_xmalloc(numBytes);
}

/* static x10.lang.NativeSupport.allocZeroed(Uint): Pointer */
x10_pointer _ZN3x104lang13NativeSupport11allocZeroedEi(x10_int numBytes)
{
	return gc_xmalloc(numBytes);
}

/* static x10.lang.NativeSupport.allocAtomic(UInt): Pointer */
x10_pointer _ZN3x104lang13NativeSupport11allocAtomicEi(x10_int numBytes)
{
	return gc_xmalloc_atomic(numBytes);
}

/* static x10.lang.NativeSupport.allocAtomicZeroed(UInt): Pointer */
x10_pointer _ZN3x104lang13NativeSupport17allocAtomicZeroedEi(x10_int numBytes)
{
	void *mem = gc_xmalloc_atomic(numBytes);
	memset(mem, 0, numBytes);
	return mem;
}

/* static x10.lang.NativeSupport.realloc(Pointer, Int, Int): Pointer */
x10_pointer _ZN3x104lang13NativeSupport7reallocEPvii(x10_pointer prev,
	x10_int prev_bytes, x10_int num_bytes)
{
	(void) prev_bytes;
	return gc_xrealloc(prev, num_bytes);
}

/* static x10.lang.NativeSupport.reallocZeroed(Pointer, Int, Int): Pointer */
x10_pointer _ZN3x104lang13NativeSupport13reallocZeroedEPvii(x10_pointer prev,
	x10_int prev_bytes, x10_int num_bytes)
{
	(void) prev_bytes;
	return gc_xrealloc(prev, num_bytes);
}

/* static x10.lang.NativeSupport.dealloc(Pointer) */
void _ZN3x104lang13NativeSupport7deallocEPv(x10_pointer ptr)
{
	gc_free(ptr);
}
