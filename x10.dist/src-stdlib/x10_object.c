#include "x10_object.h"

#include "x10_string.h"

/* Object constructor */
void _ZN3x104lang6ObjectC1Ev(x10_object *self)
{
	(void)self;
}

// TODO: Implement me
x10_string *_ZN3x104lang6Object8typeNameEv(x10_object *self)
{
	UNUSED(self);
	return x10_string_from_wide_chars(L"Object");
}

// TODO: Implement me
x10_boolean _ZN3x104lang6Object6equalsEPN3x104lang3AnyE(x10_object *self, x10_any *other)
{
	return self == (x10_object *)other;
}

// TODO: Implement me
x10_int _ZN3x104lang6Object8hashCodeEv(x10_object *self)
{
	return (x10_int)self;
}

// TODO: Implement me
x10_string *_ZN3x104lang6Object8toStringEv(x10_object *self)
{
	x10_char tmp[30];
	swprintf(tmp, 30, L"Object %p", self);
	return x10_string_from_wide_chars(tmp);
}
