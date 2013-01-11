#ifndef X10_ATOMIC_LONG_H
#define X10_ATOMIC_LONG_H

#include "types.h"
#include "x10_atomic_ops.h"

typedef struct {
	x10_object        base;
	volatile x10_long value;
} x10_atomic_long;

x10_boolean _ZN3x104util10concurrent10AtomicLong13compareAndSetExx(x10_atomic_long *, x10_long, x10_long);
x10_boolean _ZN3x104util10concurrent10AtomicLong17weakCompareAndSetExx(x10_atomic_long *, x10_long, x10_long);
x10_long _ZN3x104util10concurrent10AtomicLong9getAndAddEx(x10_atomic_long *, x10_long);
x10_long _ZN3x104util10concurrent10AtomicLong9addAndGetEx(x10_atomic_long *, x10_long);

#endif
