#include <stdint.h>

#include "x10_object.h"
#include "x10_string.h"
#include "util.h"

/* Object constructor */
void _ZN3x104lang6ObjectC1Ev(x10_object *self)
{
	X10_UNUSED(self);
}

// Object.typeName()
x10_string *_ZN3x104lang6Object8typeNameEv(x10_object *self)
{
	X10_UNUSED(self);
	return x10_string_from_cstring("Object");
}

x10_boolean _ZN3x104lang6Object6equalsEPN3x104lang3AnyE(x10_object *self, x10_any *other)
{
	return self == (x10_object *)other;
}

x10_int _ZN3x104lang6Object8hashCodeEv(x10_object *self)
{
	return (x10_int)(intptr_t)self;
}

x10_string *_ZN3x104lang6Object8toStringEv(x10_object *self)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "Object %p", (void*)self);
	return x10_string_from_cstring(buf);
}
