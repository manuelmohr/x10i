#ifndef ARRAY_H
#define ARRAY_H

typedef struct flexible_array_t {
	size_t capacity;
	size_t size;
	char  *data;
} flexible_array_t;

void flexible_array_grow_po2(flexible_array_t *array, size_t min_capacity);

static inline void flexible_array_ensure_capacity(flexible_array_t *array,
                                                  size_t const capacity)
{
	if (capacity <= array->capacity)
		return;
	flexible_array_grow_po2(array, capacity);
}

#define ARR_INIT(array)           memset((array), 0, sizeof(array))
#define ARR_LEN(type, array)      ((array)->size /= sizeof(type))
#define ARR_APPEND(type, array, x) do {                                  \
	flexible_array_t *const array_ = (array);                            \
	flexible_array_ensure_capacity(array_, array_->size + sizeof(type)); \
	*((type*)(&array_->data[array_->size])) = (x);                       \
	array_->size += sizeof(type);                                        \
} while(0)
#define ARR_ARRAY(type, array)    ((type*)(array)->data)
#define ARR_FREE(array)           gc_free((array)->data)

#endif
