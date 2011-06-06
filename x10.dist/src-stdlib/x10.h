#ifndef X10_H
#define X10_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <wchar.h>
#include <assert.h>
#include <stdio.h>

#define T_OBJECT 		 (1)
#define T_STRING		 (2)

// TODO: Vtable etc
typedef struct {
	uintptr_t type;
} x10_object_header;

#define X10_OBJECT_HEADER \
	x10_object_header head;

#define X10_OBJECT_HEAD(o)      ((x10_object_header *)(o))

#define X10_TYPE(o) 		(X10_OBJECT_HEAD(o)->type)
#define X10_INIT_TYPE(o,t) 	X10_TYPE(o) = (t)

// TODO: more to come
#define X10_INIT_OBJECT(o,t) 	X10_INIT_TYPE(o,t)

#define X10_INSTANCE_OF(o,t)    (X10_TYPE(o) == (t))

typedef void   			x10_any;

typedef struct x10_object 	x10_object;
typedef struct x10_string 	x10_string;
typedef struct x10_printer      x10_printer;

typedef int64_t 		x10_long;
typedef uint64_t 		x10_ulong;
typedef int32_t 		x10_int;
typedef uint32_t 		x10_uint;
typedef int16_t 		x10_short;
typedef uint16_t 		x10_ushort;
typedef int8_t  		x10_byte;
typedef uint8_t			x10_ubyte;
typedef bool 			x10_boolean;
typedef wchar_t			x10_char;
typedef float 			x10_float;
typedef double 			x10_double;

#define X10_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define X10_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define X10_EXTERN extern

#define X10_NULL   NULL

#define X10_TRUE 	(true)
#define X10_FALSE	(false)

#define X10_MALLOC(s)   	malloc(s)
#define X10_REALLOC(v,s)	realloc((v), (s))
#define X10_FREE(o)		// DO NOTHING

#define X10_OBJECT_CAST(to, what) ((to *)(what))

#define X10_ALLOC_OBJECT(o) (o *)X10_MALLOC(sizeof(o))

#define UNUSED(s) (void)(s)

#define T_(x) L##x

#define X10_NULL_CHECK(obj) \
	if(obj == X10_NULL) { \
		X10_THROW_EXCEPTION(X10_NULL_POINTER_EXCEPTION); \
	}

#define X10_NULL_POINTER_EXCEPTION // TODO: name assoziation
#define X10_INDEX_OUT_OF_BOUNDS_EXCEPTION // TODO: name assoziation

#define X10_THROW_EXCEPTION(...)	\
	{ } // TODO: Throw exception

#endif // X10_H

