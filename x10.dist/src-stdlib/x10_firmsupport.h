#include "x10.h"
#include "x10_primitive_types.h"
#include "util.h"

/* memcmp */
x10_boolean _ZN3x104lang14X10FirmSupport6memcmpEN3x104lang11FirmPointerEN3x104lang11FirmPointerEx(x10_any *ptr1, x10_any *ptr2, x10_long bytes);

/* memcpy */
void _ZN3x104lang14X10FirmSupport6memcpyEN3x104lang11FirmPointerEN3x104lang11FirmPointerExb(x10_any *dst, x10_any *src, x10_long bytes, x10_boolean overlap);

/* memset */
void _ZN3x104lang14X10FirmSupport6memsetEN3x104lang11FirmPointerEix(x10_any *dest, x10_int c, x10_long bytes); 

/** allocation of memory; the returned memory pointer is not aligned !!! (Use align_ptr for alignment of pointers) */
x10_any *_ZN3x104lang14X10FirmSupport5allocExibb(x10_long numBytes, x10_int alignment, x10_boolean congruent, x10_boolean zeroed);

/** deallocation of memory; The given memory pointer must be the real memory pointer returned by "alloc"; (not the aligned) */
void _ZN3x104lang14X10FirmSupport7deallocEN3x104lang11FirmPointerE(x10_any *ptr);
