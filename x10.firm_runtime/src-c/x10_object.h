#ifndef X10_OBJECT_H_
#define X10_OBJECT_H_

#include "x10.h"
#include <liboo/rts_types.h>

typedef struct x10_vtable {
	const class_info_t *runtime_type_info;
	void *fptrs[]; /* function pointer follow here */
} x10_vtable;

typedef struct {
	const x10_vtable *vptr;
} x10_object;

x10_object *x10_alloc_object(const x10_vtable *vptr, size_t size);

#define X10_ALLOC_OBJECT(type, vptr) \
	((type*)x10_alloc_object(vptr, sizeof(type)))

#endif
