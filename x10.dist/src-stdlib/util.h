#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdlib.h>

#include "x10.h"
#include "x10_object.h"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

static const void *X10_NULL = NULL;
static const bool X10_TRUE = true;
static const bool X10_FALSE = false;

static inline x10_object_header *x10_object_head(const x10_object *obj)
{
	return (x10_object_header *) obj;
}

static inline void x10_init_object(x10_object *o, const x10_vtable_t *vptr)
{
	x10_object_head(o)->vptr = (uintptr_t*) vptr;
}

#define X10_INIT_OBJECT(o, v) x10_init_object((x10_object *) o, v)

// liboo does allow for different vtable layouts where the classinfo does not
// reside in the first vtable entry.  We ignore these cases here.
static inline bool x10_instance_of(const x10_object* o,
		const x10_classinfo_t *c)
{
	return x10_object_head(o)->vptr[0] == (uintptr_t) c;
}

static inline void* x10_malloc(size_t size)
{
	void *data = malloc(size);
	// TODO Out of memory exception?
	return data;
}

static inline void* x10_realloc(x10_object *obj, size_t size)
{
	void *data = realloc(obj, size);
	// TODO Out of memory exception?
	return data;
}

static inline void x10_free(void *obj)
{
	(void) obj;
	// Do nothing
}

static inline x10_object *new_exception(const char *name, const char *msg)
{
	(void) name;
	(void) msg;
	// TODO this is just a dummy!
	return NULL;
}

static inline void x10_throw_exception(x10_object *exc)
{
	(void) exc;
	// TODO
}

static inline void x10_null_check(void *obj)
{
	if (obj == X10_NULL)
		x10_throw_exception(new_exception("NullPointerException", "null check"));
}

#endif // UTIL_H
