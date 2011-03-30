#include "x10_object.h"

/* Object constructor */
void _ZN3x104lang6ObjectC1Ev(x10_object *self)
{
	(void)self;
}

// TODO: Implement me
const x10_string *_ZN3x104lang6Object8typeNameEv(const x10_object *self)
{
	(void)self;
	return X10_NULL;
}

// TODO: Implement me
x10_boolean _ZN3x104lang6Object6equalsEPN3x104lang3AnyE(const x10_object *self, const x10_any other)
{
	return self == other;
}

// TODO: Implement me
x10_int _ZN3x104lang6Object8hashCodeEv(const x10_object *self)
{
	return (x10_int)self;
}

// TODO: Implement me
const x10_string *_ZN3x104lang6Object8toStringEv(const x10_object *self)
{
	(void)self;
	return X10_NULL;
}
