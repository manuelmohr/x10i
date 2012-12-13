#include "x10_atomic_long.h"
#include "x10_atomic_ops.h"

x10_boolean _ZN3x104util10concurrent10AtomicLong13compareAndSetExx(x10_atomic_long *self, x10_long expect, x10_long update)
{
	return x10_atomic_ops_compareAndSet_64(&self->value, expect, update) == expect;
}

x10_boolean _ZN3x104util10concurrent10AtomicLong17weakCompareAndSetExx(x10_atomic_long *self, x10_long expect, x10_long update)
{
	// TODO: for minor optimization on ppc we could add a weakCompareAndSet in atomic_ops and use that here
	return x10_atomic_ops_compareAndSet_64(&self->value, expect, update) == expect;
}

x10_long _ZN3x104util10concurrent10AtomicLong9getAndAddEx(x10_atomic_long *self, x10_long delta)
{
	x10_long oldValue = self->value;
	while (x10_atomic_ops_compareAndSet_64(&self->value, oldValue, oldValue+delta) != oldValue) {
		oldValue = self->value;
	}

	return oldValue;
}

x10_long _ZN3x104util10concurrent10AtomicLong9addAndGetEx(x10_atomic_long *self, x10_long delta)
{
	x10_long oldValue = self->value;
	while (x10_atomic_ops_compareAndSet_64(&self->value, oldValue, oldValue+delta) != oldValue) {
		oldValue = self->value;
	}
	return oldValue + delta;
}
