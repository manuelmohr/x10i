#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

/* Booleans */
X10_MAKE_EQUALS(_ZN3x104lang7Boolean6equalsEb, x10_boolean)
X10_MAKE_HASHCODE(_ZN3x104lang7Boolean8hashCodeEv, x10_boolean)

// toString
x10_string *_ZN3x104lang7Boolean8toStringEv(x10_boolean self)
{
	return self ? x10_string_from_wide_chars(T_("true")) :
		x10_string_from_wide_chars(T_("false"));
}

X10_MAKE_TYPENAME(_ZN3x104lang7Boolean8typeNameEv, x10_boolean,
	"x10.lang.Boolean")
X10_MAKE_EQUALS_ANY(_ZN3x104lang7Boolean6equalsEPN3x104lang3AnyE, x10_int)


// compareTo from Comparable
x10_int _ZN3x104lang7Boolean9compareToEb(x10_boolean self, x10_boolean other)
{
	return (self == other) ? 0 : self ? 1 : -1;
}

UNOP(_ZN3x104lang7BooleanntEv, x10_boolean, !)
BINOP(_ZN3x104lang7BooleananEb, x10_boolean, &)
BINOP(_ZN3x104lang7BooleanorEb, x10_boolean, |)
BINOP(_ZN3x104lang7BooleaneoEb, x10_boolean, ^)

x10_boolean _ZN3x104lang7Boolean12parseBooleanEPN3x104lang6StringE(x10_string *s) 
{
	return s != X10_NULL && !wcscmp(x10_string_buf(s), T_("true")); 
}
