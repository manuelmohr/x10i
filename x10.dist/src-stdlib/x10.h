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

#define T_OBJECT 		 (1L << 0)
#define T_STRING		 (1L << 1)
#define T_CONSOLE		 (1L << 2)
#define T_PRINTER		 (1L << 3)
#define T_INT			 (1L << 4)
#define T_UINT			 (1L << 5)
#define T_LONG			 (1L << 6)
#define T_ULONG			 (1L << 7)
#define T_SHORT			 (1L << 8)
#define T_USHORT		 (1L << 10)
#define T_BYTE			 (1L << 11)
#define T_UBYTE			 (1L << 12)
#define T_BOOLEAN		 (1L << 13)
#define T_CHAR			 (1L << 14)
#define T_FLOAT			 (1L << 15)
#define T_DOUBLE		 (1L << 16)

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

#define X10_CHECK_TYPE(o,t)     ((X10_TYPE(o) & (t)) != 0)

typedef void   			x10_any;

typedef struct x10_object 	x10_object;
typedef struct x10_string 	x10_string;
typedef struct x10_console 	x10_console;
typedef struct x10_printer 	x10_printer;

typedef int64_t 		x10_long;
typedef struct x10_long_w	x10_long_w;

typedef uint64_t 		x10_ulong;
typedef struct x10_ulong_w	x10_ulong_w;

typedef int32_t 		x10_int;
typedef struct x10_int_w	x10_int_w;

typedef uint32_t 		x10_uint;
typedef struct x10_uint_w	x10_uint_w;

typedef int16_t 		x10_short;
typedef struct x10_short_w	x10_short_w;

typedef uint16_t 		x10_ushort;
typedef struct x10_ushort_w	x10_ushort_w;

typedef int8_t  		x10_byte;
typedef struct x10_byte_w	x10_byte_w;

typedef uint8_t			x10_ubyte;
typedef struct x10_ubyte_w	x10_ubyte_w;

typedef bool 			x10_boolean;
typedef struct x10_boolean_w	x10_boolean_w;

typedef wchar_t			x10_char;
typedef struct x10_char_w	x10_char_w;

typedef float 			x10_float;
typedef struct x10_float_w	x10_float_w;

typedef double 			x10_double;
typedef struct x10_double_w 	x10_double_w;

#define X10_EXTERN extern

#define X10_NULL   NULL

#define X10_MALLOC(s)   	malloc(s)
#define X10_REALLOC(v,s)	realloc((v), (s))
#define X10_FREE(o)		// DO NOTHING

#define X10_ALLOC_OBJECT(o) (o *)X10_MALLOC(sizeof(o))

#define UNUSED(s) (void)(s)

#endif // X10_H

