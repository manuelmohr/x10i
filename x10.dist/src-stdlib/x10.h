#ifndef X10_H
#define X10_H

#define _GNU_SOURCE

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <wchar.h>
#include <assert.h>
#include <stdio.h>
#include <errno.h>

typedef struct {
	uintptr_t dummy;
} x10_vtable_t;

typedef struct {
	uintptr_t dummy;
} x10_classinfo_t;

#define OBJECT_CLASSINFO _ZN3x104lang6ObjectE$
#define OBJECT_VTABLE    _ZTVN3x104lang6ObjectE
#define STRING_CLASSINFO _ZN3x104lang6StringE$
#define STRING_VTABLE    _ZTVN3x104lang6StringE
extern const x10_vtable_t    OBJECT_VTABLE;
extern const x10_classinfo_t OBJECT_CLASSINFO;
extern const x10_vtable_t    STRING_VTABLE;
extern const x10_classinfo_t STRING_CLASSINFO;

typedef struct {
	uintptr_t *vptr;
} x10_object_header;

#define X10_OBJECT_HEADER x10_object_header head;

typedef void         x10_any;

typedef int64_t     x10_long;
typedef uint64_t    x10_ulong;
typedef int32_t     x10_int;
typedef uint32_t    x10_uint;
typedef int16_t     x10_short;
typedef uint16_t    x10_ushort;
typedef int8_t      x10_byte;
typedef uint8_t     x10_ubyte;
typedef bool        x10_boolean;
typedef wchar_t     x10_char;
typedef float       x10_float;
typedef double      x10_double;

#define X10_EXTERN extern

#define X10_OBJECT_CAST(to, what) ((to *)(what))
#define X10_ALLOC_OBJECT(o) (o *)X10_MALLOC(sizeof(o))

#define UNUSED(s) (void)(s)
#define T_(x) L##x

#endif // X10_H
