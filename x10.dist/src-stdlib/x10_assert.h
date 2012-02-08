#ifndef X10_ASSERT_H_
#define X10_ASSERT_H_

#include "x10.h"
#include "x10_string.h"

X10_EXTERN void x10_assert(x10_boolean cond, x10_string* message,
                           x10_string* position);

#endif
