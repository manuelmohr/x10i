#ifndef OCTOPOS_PLATFORM_ATOMIC_OPS_H
#define OCTOPOS_PLATFORM_ATOMIC_OPS_H

#include <octopos.h>

extern simple_spinlock x10_op_lock;

static inline void x10_atomic_ops_lock(void)
{
	simple_spinlock_lock(&x10_op_lock);
}

static inline void x10_atomic_ops_unlock(void)
{
	simple_spinlock_unlock(&x10_op_lock);
}

#endif
