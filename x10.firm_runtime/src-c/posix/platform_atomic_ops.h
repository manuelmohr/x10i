#ifndef __PLATFORM_ATOMIC_OPS_H__
#define __PLATFORM_ATOMIC_OPS_H__

#include <pthread.h>

extern pthread_mutex_t x10_op_lock;

static inline void x10_atomic_ops_lock(void)
{
	pthread_mutex_lock(&x10_op_lock);
}

static inline void x10_atomic_ops_unlock(void)
{
	pthread_mutex_unlock(&x10_op_lock);
}

#endif