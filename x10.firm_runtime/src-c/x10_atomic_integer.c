#include "x10_atomic_integer.h"
#include "x10_atomic_ops.h"

x10_boolean _ZN3x104util10concurrent13AtomicInteger13compareAndSetEii(x10_atomic_integer *self, x10_int expect, x10_int update)
{
	return x10_atomic_ops_compareAndSet_32(&self->value, expect, update) == expect;
}

x10_boolean _ZN3x104util10concurrent13AtomicInteger17weakCompareAndSetEii(x10_atomic_integer *self, x10_int expect, x10_int update)
{
	// TODO: for minor optimization on ppc we could add a weakCompareAndSet in atomic_ops and use that here
	return x10_atomic_ops_compareAndSet_32(&self->value, expect, update) == expect;
}

x10_int _ZN3x104util10concurrent13AtomicInteger9getAndAddEi(x10_atomic_integer *self, x10_int delta)
{
	x10_int oldValue = self->value;
	while (x10_atomic_ops_compareAndSet_32(&self->value, oldValue, oldValue+delta) != oldValue) {
		oldValue = self->value;
	}
	return oldValue;
}

x10_int _ZN3x104util10concurrent13AtomicInteger9addAndGetEi(x10_atomic_integer *self, x10_int delta)
{
	x10_int oldValue = self->value;
	while (x10_atomic_ops_compareAndSet_32(&self->value, oldValue, oldValue+delta) != oldValue) {
		oldValue = self->value;
	}
	return oldValue + delta;
}
