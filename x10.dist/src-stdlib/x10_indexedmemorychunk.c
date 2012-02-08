#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_firmsupport.h"
#include "util.h"

// platform-specific min chunk alignment
#if defined(_POWER) || defined(__bgp__)
#define X10_MIN_INDEXEDMEMORYCHUNK_ALIGNMENT 16
#else
#define X10_MIN_INDEXEDMEMORYCHUNK_ALIGNMENT ((x10_int)sizeof(x10_double))
#endif

x10_any *_ZN3x104util18IndexedMemoryChunk14alloc_internalExiibb(x10_long numElements, x10_int sizeElement, x10_int alignment, x10_boolean congruent, x10_boolean zeroed)
{
	assert(numElements > 0 && sizeElement > 0);
	assert((alignment & (alignment-1)) == 0);
	// check for min alignment
	if(alignment < X10_MIN_INDEXEDMEMORYCHUNK_ALIGNMENT)
		alignment = X10_MIN_INDEXEDMEMORYCHUNK_ALIGNMENT;

	return _ZN3x104lang14X10FirmSupport5allocExibb(numElements * sizeElement, alignment, congruent, zeroed);
}

void _ZN3x104util18IndexedMemoryChunk16dealloc_internalEN3x104lang11FirmPointerE(x10_any *ptr)
{
	_ZN3x104lang14X10FirmSupport7deallocEN3x104lang11FirmPointerE(ptr);
}
