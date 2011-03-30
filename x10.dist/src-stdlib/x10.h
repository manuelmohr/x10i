#ifndef X10_H
#define X10_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <wchar.h>
#include <assert.h>
#include <stdio.h>

typedef int64_t 	x10_long;
typedef uint64_t 	x10_ulong;

typedef int32_t 	x10_int;
typedef uint32_t 	x10_uint;

typedef int16_t 	x10_short;
typedef uint16_t 	x10_ushort;

typedef int8_t  	x10_byte;
typedef uint8_t		x10_ubyte;

typedef bool 		x10_boolean;

typedef wchar_t		x10_char;
typedef wint_t          x10_char_int;

typedef float 		x10_float;
typedef double 		x10_double;

typedef void *          x10_any;

typedef struct x10_object x10_object;
typedef struct x10_string x10_string;

#define X10_EXTERN extern

#define X10_NULL   NULL

#define XMALLOC(s)   malloc(sizeof(s))

#endif // X10_H

