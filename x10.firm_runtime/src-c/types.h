#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

typedef void      x10_any;
typedef int64_t   x10_long;
typedef uint64_t  x10_ulong;
typedef int32_t   x10_int;
typedef uint32_t  x10_uint;
typedef int16_t   x10_short;
typedef uint16_t  x10_ushort;
typedef int8_t    x10_byte;
typedef uint8_t   x10_ubyte;
typedef bool      x10_boolean;
typedef char      x10_char;
typedef float     x10_float;
#ifdef DOUBLE_IS_32BIT
typedef float     x10_double;
#else
typedef double    x10_double;
#endif
typedef char     *x10_pointer;
typedef void     *x10_opaque_handle;

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

#ifndef X10_TYPE
/** used to mark structs which become true X10 classes. A separate code analysis
 * step looks for these marked classes and creates nativesizes config. */
#define X10_TYPE(x)
#endif

#endif
