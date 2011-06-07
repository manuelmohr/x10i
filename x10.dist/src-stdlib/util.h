#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdlib.h>

#include "x10.h"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

static inline bool x10_instance_of(x10_object_header *obj, uintptr_t type) {
	return obj->type == type;
}

static const void *X10_NULL = NULL;

static const bool X10_TRUE = true;
static const bool X10_FALSE = false;

static inline void* x10_malloc(size_t size) {
	void *data = malloc(size);
	// TODO Out of memory exception?
	return data;
}

static inline void* x10_realloc(x10_object *obj, size_t size) {
	void *data = realloc(obj, size);
	// TODO Out of memory exception?
	return data;
}

static inline void x10_free(void *obj) {
	(void) obj;
	// Do nothing
}

extern void *X10NullPointerException;
extern void *X10IndexOutOfBoundsException;

static inline void x10_throw_exception(x10_object *exc) {
	(void) exc;
	// TODO
}

static inline void x10_null_check(void *obj) {
	if (obj == X10_NULL)
		x10_throw_exception(X10NullPointerException);
}

#endif // UTIL_H

