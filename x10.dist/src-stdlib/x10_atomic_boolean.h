#ifndef X10_ATOMIC_BOOLEAN_H_
#define X10_ATOMIC_BOOLEAN_H_

#include "x10.h"
#include "x10_atomic_ops.h"

typedef struct {
	X10_OBJECT_HEADER
	/* An int that will only contain 0 or 1 and is interpreted as an boolean.
    * We do this instead of using a boolean so that we know that compareAndSet_32 
    * can work on the whole memory word.
   */
	volatile x10_int value;
} x10_atomic_boolean;

X10_EXTERN x10_boolean _ZN3x104util10concurrent13AtomicBoolean13compareAndSetEbb(x10_atomic_boolean *, x10_boolean, x10_boolean);
X10_EXTERN x10_boolean _ZN3x104util10concurrent13AtomicBoolean17weakCompareAndSetEbb(x10_atomic_boolean *, x10_boolean, x10_boolean);

#endif // X10_ATOMIC_BOOLEAN_H_
