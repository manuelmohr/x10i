#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdlib.h>

#include "types.h"
#include "x10_object.h"
#include "x10_throw.h"

#define X10_UNUSED(s) (void)(s)

#define X10_UNIMPLEMENTED() printf("%s not implemented yet", __FUNCTION__); abort();

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#define ARRAY_SIZE(array)  (sizeof(array)/sizeof(array[0]))

#define T_(x) x
#define X10_NULL_POINTER_EXCEPTION  T_("NullPointerException")
#define X10_NUMBER_FORMAT_EXCEPTION T_("NumberFormatException")
#define X10_INDEX_OUT_OF_BOUNDS_EXCEPTION T_("IndexOutOfBoundsException")
#define X10_ILLEGAL_MONITOR_STATE_EXCEPTION T_("IllegalMonitorStateException")
#define X10_ILLEGAL_OPERATION_EXCEPTION T_("IllegalOperationException")

static inline x10_object *x10_new_exception_object(const x10_char *name, const x10_char *msg)
{
	X10_UNUSED(name);
	X10_UNUSED(msg);
	// TODO this is just a dummy!
	return NULL;
}

static inline void x10_throw_exception_object(x10_object *obj)
{
	// TODO: Implement me
	X10_UNUSED(obj);
	x10_throw_stub();
}

static inline void x10_throw_exception(const x10_char *name, const x10_char *msg)
{
	x10_throw_exception_object(x10_new_exception_object(name, msg));
}

static inline void x10_null_check(const void *obj)
{
	if (obj == NULL)
		x10_throw_exception(X10_NULL_POINTER_EXCEPTION, T_("null check"));
}

#endif
