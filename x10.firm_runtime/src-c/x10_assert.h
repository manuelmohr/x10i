#ifndef X10_ASSERT_H
#define X10_ASSERT_H

#include "types.h"
#include "x10_string.h"

void x10_assert(x10_boolean cond, x10_string* message, x10_string* position);

#endif
