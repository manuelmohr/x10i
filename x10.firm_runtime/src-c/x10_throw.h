#ifndef X10_THROW_H
#define X10_THROW_H

#include "types.h"
#include "x10_object.h"

void __attribute__((noreturn)) x10_exception_unwind(x10_object *checked_throwable);

#endif
