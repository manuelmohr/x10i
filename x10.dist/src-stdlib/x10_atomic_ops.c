#include "x10_atomic_ops.h"

static pthread_mutex_t _longOperationLock = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

void x10_atomic_ops_lock()
{
	pthread_mutex_lock(&_longOperationLock);
}

void x10_atomic_ops_unlock()
{
    pthread_mutex_unlock(&_longOperationLock);
}

