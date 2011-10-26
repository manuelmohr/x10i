#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdlib.h>

#include "x10.h"
#include "x10_object.h"
#include "debug.h"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define X10_NULL NULL

static const bool X10_TRUE = true;
static const bool X10_FALSE = false;

#define X10_NULL_POINTER_EXCEPTION  T_("NullPointerException")
#define X10_NUMBER_FORMAT_EXCEPTION T_("NumberFormatException")
#define X10_INDEX_OUT_OF_BOUNDS_EXCEPTION T_("IndexOutOfBoundsException")
#define X10_ILLEGAL_MONITOR_STATE_EXCEPTION T_("IllegalMonitorStateException")


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

static inline void *x10_sysalloc(size_t size)
{
	return malloc(size); 
}

static inline void x10_sysfree(void *ptr)
{
	free(ptr); 
}

static inline void *x10_sysrealloc(void *ptr, size_t size)
{
	return realloc(ptr, size);
}


static inline void* x10_malloc(size_t size)
{
	// TODO: Garbage collection, Out of memory exception
	void *data = malloc(size);
	return data;
}

static inline void* x10_realloc(void *ptr, size_t size)
{
	void *data = realloc(ptr, size);
	// TODO Out of memory exception?
	return data;
}

static inline void x10_free(void *obj)
{
	// TODO: Garbage collection
	X10_UNUSED(obj);
	// Do nothing
}

static inline x10_object *x10_new_exception_object(const x10_char *name, const x10_char *msg)
{
	X10_UNUSED(name); 
	X10_UNUSED(msg); 
	// TODO this is just a dummy!
	return X10_NULL;
}

static inline void x10_throw_exception_object(x10_object *obj)
{
	// TODO: Implement me
	X10_UNUSED(obj);
}

static inline void x10_throw_exception(const x10_char *name, const x10_char *msg)
{
	x10_throw_exception_object(x10_new_exception_object(name, msg));
}

static inline void x10_null_check(void *obj)
{
	if (obj == X10_NULL)
		x10_throw_exception(X10_NULL_POINTER_EXCEPTION, T_("null check"));
}

#endif // UTIL_H
