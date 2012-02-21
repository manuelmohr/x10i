#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

/* Booleans */
X10_MAKE_EQUALS(_ZN3x104lang7Boolean6equalsEb, x10_boolean)

UNOP(_ZN3x104lang7BooleanntEv, x10_boolean, !)
BINOP3(_ZN3x104lang7BooleananEb, x10_boolean, &)
BINOP3(_ZN3x104lang7BooleanorEb, x10_boolean, |)
BINOP3(_ZN3x104lang7BooleaneoEb, x10_boolean, ^)
