#include "array.h"
#include "xmalloc.h"

void flexible_array_grow_po2(flexible_array_t *array, size_t min_capacity)
{
	size_t new_capacity;
	if (min_capacity < 16) {
		new_capacity = 16;
	} else {
		new_capacity = array->capacity;
		do {
			new_capacity <<= 1;
		} while (new_capacity < min_capacity);
	}
	array->data     = gc_xrealloc(array->data, new_capacity);
	array->capacity = new_capacity;
}
