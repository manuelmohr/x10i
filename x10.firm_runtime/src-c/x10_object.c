#include <stdint.h>

#include "x10_object.h"
#include "x10_string.h"
#include "util.h"

x10_object *x10_alloc_object(const x10_vtable *vptr, size_t size)
{
	assert(size > 0);
	assert(vptr->runtime_type_info->size == size);
	x10_object *o = XMALLOC(x10_object);
	o->vptr = vptr;
	return o;
}

/* Object.this() */
void _ZN3x104lang6ObjectC1Ev(x10_object *self)
{
	X10_UNUSED(self);
}

/* Object.typeName(): String */
x10_string *_ZN3x104lang6Object8typeNameEv(x10_object *self)
{
	const class_info_t   *runtime_type_info = self->vptr->runtime_type_info;
	const string_const_t *name              = runtime_type_info->name;
	const char           *cname             = get_string_const_chars(name);
	return x10_string_from_cstring(cname);
}

/* Object.equals(other: Object): Boolean */
x10_boolean _ZN3x104lang6Object6equalsEPN3x104lang3AnyE(x10_object *self, x10_any *other)
{
	return self == (x10_object *)other;
}

/* Object.hashCode(): Int */
x10_int _ZN3x104lang6Object8hashCodeEv(x10_object *self)
{
	x10_uint value = (x10_uint)(uintptr_t)self;
	/* most pointers are 8-byte aligned (or more), so the lowest 3 bit
	 * are typically not randomly distributed. Rotating the value for 3 bits
	 * improved most hash algorithms */
	value = (value >> 3) | (value << (sizeof(value)*8-3));
	return (x10_int)value;
}

/* Object.toString(): String */
x10_string *_ZN3x104lang6Object8toStringEv(x10_object *self)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "Object %p", (void*)self);
	return x10_string_from_cstring(buf);
}
