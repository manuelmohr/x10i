#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdlib.h>

#include "x10.h"
#include "x10_object.h"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define X10_NULL NULL

#define ARRAY_SIZE(array)  (sizeof(array)/sizeof(array[0]))

static const bool X10_TRUE = true;
static const bool X10_FALSE = false;

#define X10_NULL_POINTER_EXCEPTION  T_("NullPointerException")
#define X10_NUMBER_FORMAT_EXCEPTION T_("NumberFormatException")
#define X10_INDEX_OUT_OF_BOUNDS_EXCEPTION T_("IndexOutOfBoundsException")
#define X10_ILLEGAL_MONITOR_STATE_EXCEPTION T_("IllegalMonitorStateException")

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

static inline void x10_null_check(const void *obj)
{
	if (obj == X10_NULL)
		x10_throw_exception(X10_NULL_POINTER_EXCEPTION, T_("null check"));
}

#endif
