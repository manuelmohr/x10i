#include "x10.h"
#include "x10_primitive_types.h"
#include "util.h"

x10_any *_ZN3x104lang14X10FirmSupport14alloc_internalEiiibb(x10_int numElements, x10_int elementSize, x10_int alignment, x10_boolean congruent, x10_boolean zeroed)
{
	// TODO: Implement me
	X10_UNUSED(alignment);
	X10_UNUSED(congruent);
	X10_UNUSED(zeroed);
	return x10_malloc(numElements * elementSize);
}
