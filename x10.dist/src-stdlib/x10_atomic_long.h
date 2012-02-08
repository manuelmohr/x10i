#ifndef X10_ATOMIC_LONG_H_
#define X10_ATOMIC_LONG_H_

#include "x10.h"
#include "x10_atomic_ops.h"

typedef struct {
	X10_OBJECT_HEADER
	volatile x10_long value;
} x10_atomic_long;

X10_EXTERN x10_boolean _ZN3x104util10concurrent10AtomicLong13compareAndSetExx(x10_atomic_long *, x10_long, x10_long);
X10_EXTERN x10_boolean _ZN3x104util10concurrent10AtomicLong17weakCompareAndSetExx(x10_atomic_long *, x10_long, x10_long);
X10_EXTERN x10_long _ZN3x104util10concurrent10AtomicLong9getAndAddEx(x10_atomic_long *, x10_long);
X10_EXTERN x10_long _ZN3x104util10concurrent10AtomicLong9addAndGetEx(x10_atomic_long *, x10_long);

#endif
