#include <stdint.h>

#include "x10_object.h"
#include "x10_string.h"
#include "util.h"

x10_object *x10_alloc_object(const x10_vtable *vptr, size_t size)
{
	assert(size > 0);
	assert(vptr->runtime_type_info->size == size);
	x10_object *o = (x10_object*)gc_xmalloc(size);
	o->vptr = vptr;
	return o;
}

/* x10_object_8typeNamev(this: any ref): String */
x10_string *x10_object_8typeNamev(x10_object *self)
{
	const class_info_t   *runtime_type_info = self->vptr->runtime_type_info;
	const string_const_t *name              = runtime_type_info->name;
	const char           *cname             = get_string_const_chars(name);
	return x10_string_from_cstring(cname);
}

/* x10_object_6equalsPN3x104lang3AnyE(this: any ref, other: Any): Boolean */
x10_boolean x10_object_6equalsPN3x104lang3AnyE(x10_object *self, x10_any *other)
{
	return self == (x10_object *)other;
}

/* x10_object_8hashCodev(this: any ref): Int */
x10_int x10_object_8hashCodev(x10_object *self)
{
	x10_uint value = (x10_uint)(uintptr_t)self;
	/* most pointers are 8-byte aligned (or more), so the lowest 3 bit
	 * are typically not randomly distributed. Rotating the value for 3 bits
	 * improved most hash algorithms */
	value = (value >> 3) | (value << (sizeof(value)*8-3));
	return (x10_int)value;
}

/* x10_object_8toStringv(this: any ref): String */
x10_string *x10_object_8toStringv(x10_object *self)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "Object %p", (void*)self);
	return x10_string_from_cstring(buf);
}
