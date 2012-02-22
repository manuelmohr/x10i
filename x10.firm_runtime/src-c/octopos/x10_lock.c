#include "platform_atomic_ops.h"

simple_spinlock x10_op_lock;

static void __attribute__((constructor)) init_locks(void)
{
	simple_spinlock_init(&x10_op_lock);
}
