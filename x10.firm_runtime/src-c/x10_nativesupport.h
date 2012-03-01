#ifndef X10_FIRMSUPPORT_H
#define X10_FIRMSUPPORT_H

#include "x10.h"
#include "util.h"

/* memcmp */
x10_boolean _ZN3x104lang13NativeSupport6memcmpEPvPvi(x10_pointer ptr1, x10_pointer ptr2, x10_int bytes);

/* memcpy */
void _ZN3x104lang13NativeSupport6memcpyEPvPvib(x10_pointer dst, x10_pointer src, x10_int bytes, x10_boolean overlap);

/* memset */
void _ZN3x104lang13NativeSupport6memsetEPvii(x10_pointer dest, x10_int c, x10_int bytes);

/** allocation of memory; the returned memory pointer is not aligned !!! (Use align_ptr for alignment of pointers) */
x10_pointer _ZN3x104lang13NativeSupport5allocEiibb(x10_int numBytes, x10_int alignment, x10_boolean congruent, x10_boolean zeroed);

/** deallocation of memory; The given memory pointer must be the real memory pointer returned by "alloc"; (not the aligned) */
void _ZN3x104lang13NativeSupport7deallocEPv(x10_pointer ptr);

#endif
