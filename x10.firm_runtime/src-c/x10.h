#ifndef X10_H
#define X10_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

typedef void        x10_any;

typedef int64_t     x10_long;
typedef uint64_t    x10_ulong;
typedef int32_t     x10_int;
typedef uint32_t    x10_uint;
typedef int16_t     x10_short;
typedef uint16_t    x10_ushort;
typedef int8_t      x10_byte;
typedef uint8_t     x10_ubyte;
typedef bool        x10_boolean;
typedef char        x10_char;
typedef float       x10_float;
typedef double      x10_double;
typedef char       *x10_pointer;

#define PRIx10_long   PRIi64
#define PRIx10_ulong  PRIu64
#define PRIx10_int    PRIi32
#define PRIx10_uint   PRIu32
#define PRIx10_short  PRIi16
#define PRIx10_ushort PRIu16
#define PRIx10_byte   PRId8
#define PRIx10_ubyte  PRIu8
#define PRIx10_char   "c"
#define PRIx10_float  "f"
#define PRIx10_double "f"

#define X10_UNUSED(s) (void)(s)
#define T_(x) x

#define X10_UNIMPLEMENTED() printf("%s not implemented yet", __FUNCTION__); abort();

#ifndef X10_TYPE
#define X10_TYPE(x)
#endif

#endif
