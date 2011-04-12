#ifndef X10_OBJECT_H_
#define X10_OBJECT_H_

#include "x10.h"

struct x10_object {
	X10_OBJECT_HEADER
};

// object constructor
X10_EXTERN void _ZN3x104lang6ObjectC1Ev(x10_object *);

// object methods
X10_EXTERN x10_string *_ZN3x104lang6Object8typeNameEv(x10_object *);
X10_EXTERN x10_boolean _ZN3x104lang6Object6equalsEPN3x104lang3AnyE(x10_object *, x10_any *);
X10_EXTERN x10_int _ZN3x104lang6Object8hashCodeEv(x10_object *);
X10_EXTERN x10_string *_ZN3x104lang6Object8toStringEv(x10_object *);


#endif // X10_OBJECT_H_