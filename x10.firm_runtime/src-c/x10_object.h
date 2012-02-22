#ifndef X10_OBJECT_H_
#define X10_OBJECT_H_

#include "x10.h"
#include "x10_string.h"

typedef struct {
	X10_OBJECT_HEADER
} x10_object;

// object constructor
void _ZN3x104lang6ObjectC1Ev(x10_object *);

// object methods
x10_string *_ZN3x104lang6Object8typeNameEv(x10_object *);
x10_boolean _ZN3x104lang6Object6equalsEPN3x104lang3AnyE(x10_object *, x10_any *);
x10_int _ZN3x104lang6Object8hashCodeEv(x10_object *);
x10_string *_ZN3x104lang6Object8toStringEv(x10_object *);

#endif
