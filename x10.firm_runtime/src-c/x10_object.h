#ifndef X10_OBJECT_H_
#define X10_OBJECT_H_

#include "x10.h"

/* vtable struct (no definition in the C runtime) */
typedef struct x10_vtable    x10_vtable;
/* typeinfo struct (no definition in the C runtime) */
typedef struct x10_classinfo x10_classinfo;

typedef struct {
	const x10_vtable *vptr;
} x10_object;

static inline void x10_init_object(x10_object *o, const x10_vtable *vptr)
{
	o->vptr = vptr;
}

#endif
