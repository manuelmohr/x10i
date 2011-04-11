#ifndef X10_BOOLEAN_H_
#define X10_BOOLEAN_H_

#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

/* Booleans */

// equals
X10_MAKE_EQUALS(_ZN3x104lang7Boolean6equalsEb, x10_boolean)

// compareTo from Comparable
x10_int _ZN3x104lang7Boolean9compareToEb(x10_boolean self, x10_boolean other) { 
	return (self == other) ? 0 : self ? 1 : -1; 
}

// hashCode
x10_int _ZN3x104lang7Boolean8hashCodeEv(x10_boolean self) { 
	return (x10_int)self; 
}

// typename
x10_string *_ZN3x104lang7Boolean8typeNameEv(x10_boolean self) { 
	UNUSED(self); 
	return x10_string_from_wide_chars(T_("x10.lang.Boolean")); 
}

// toString
x10_string *_ZN3x104lang7Boolean8toStringEv(x10_boolean self) { 
	UNUSED(self); 
	return self ? x10_string_from_wide_chars(T_("true")) : x10_string_from_wide_chars(T_("false")); 
}


UNOP(_ZN3x104lang7BooleanntEv, x10_boolean, !)
BINOP(_ZN3x104lang7BooleananEb, x10_boolean, &)
BINOP(_ZN3x104lang7BooleanorEb, x10_boolean, |)
BINOP(_ZN3x104lang7BooleaneoEb, x10_boolean, ^)


#endif // X10_BOOLEAN_H_
