#include "x10_atomic_boolean.h"

x10_boolean _ZN3x104util10concurrent13AtomicBoolean13compareAndSetEbb(x10_atomic_boolean *self, x10_boolean expect, x10_boolean update)
{
    x10_int expectI = expect ? 1 : 0;
    x10_int updateI = update ? 1 : 0;
    x10_int oldVal = x10_atomic_ops_compareAndSet_32(&self->value, expectI, updateI) == expectI;
    return oldVal == 1;
}

x10_boolean _ZN3x104util10concurrent13AtomicBoolean17weakCompareAndSetEbb(x10_atomic_boolean *self, x10_boolean expect, x10_boolean update)
{
    // TODO: for minor optimization on ppc we could add a weakCompareAndSet in atomic_ops and use that here
    x10_int expectI = expect ? 1 : 0;
    x10_int updateI = update ? 1 : 0;
    x10_int oldVal = x10_atomic_ops_compareAndSet_32(&self->value, expectI, updateI) == expectI;
    return oldVal == 1;
}

