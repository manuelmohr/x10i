#ifndef X10_FIRMSUPPORT_H
#define X10_FIRMSUPPORT_H

#include "x10.h"
#include "x10_primitive_types.h"
#include "util.h"

/* memcmp */
x10_boolean _ZN3x104lang13NativeSupport6memcmpEN3x104lang7PointerEN3x104lang7PointerEi(x10_pointer ptr1, x10_pointer ptr2, x10_int bytes);

/* memcpy */
void _ZN3x104lang13NativeSupport6memcpyEN3x104lang7PointerEN3x104lang7PointerEib(x10_pointer dst, x10_pointer src, x10_int bytes, x10_boolean overlap);

/* memset */
void _ZN3x104lang13NativeSupport6memsetEN3x104lang7PointerEii(x10_pointer dest, x10_int c, x10_int bytes);

/** allocation of memory; the returned memory pointer is not aligned !!! (Use align_ptr for alignment of pointers) */
x10_pointer _ZN3x104lang13NativeSupport5allocEiibb(x10_int numBytes, x10_int alignment, x10_boolean congruent, x10_boolean zeroed);

/** deallocation of memory; The given memory pointer must be the real memory pointer returned by "alloc"; (not the aligned) */
void _ZN3x104lang13NativeSupport7deallocEN3x104lang7PointerE(x10_pointer ptr);

#endif
