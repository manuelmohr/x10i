#ifndef X10_ATOMIC_INTEGER_H
#define X10_ATOMIC_INTEGER_H

#include "types.h"
#include "x10_atomic_ops.h"

typedef struct {
	x10_object       base;
	volatile x10_int value;
} x10_atomic_integer;

x10_boolean _ZN3x104util10concurrent13AtomicInteger13compareAndSetEii(x10_atomic_integer *, x10_int, x10_int);
x10_boolean _ZN3x104util10concurrent13AtomicInteger17weakCompareAndSetEii(x10_atomic_integer *, x10_int, x10_int);
x10_int _ZN3x104util10concurrent13AtomicInteger9getAndAddEi(x10_atomic_integer *, x10_int);
x10_int _ZN3x104util10concurrent13AtomicInteger9addAndGetEi(x10_atomic_integer *, x10_int);

#endif
