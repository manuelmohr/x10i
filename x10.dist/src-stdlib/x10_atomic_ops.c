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

/**
* Ensure that all loads before the barrier have loaded their
* data before any load after the data accesses its data.
*/
void _ZN3x104util10concurrent6Fences15loadLoadBarrierEv() {
#if (defined(_ARCH_PPC) || defined(_ARCH_450) || defined(_ARCH_450d))
   x10_atomic_ops_ppc_sync(); /* TODO: sync is overkill for this barrier */
#endif
}

/**
* Ensure that all loads before the barrier have loaded
* their data before any data stored by a store after
* the barrier has been flushed.
*/
void _ZN3x104util10concurrent6Fences16loadStoreBarrierEv() {
#if (defined(_ARCH_PPC) || defined(_ARCH_450) || defined(_ARCH_450d))
   x10_atomic_ops_ppc_isync();
#endif
}

/**
* Ensure that all data from stores before the barrier
* has been flushed before any data for loads after the
* barrier is accessed.
*/
void _ZN3x104util10concurrent6Fences16storeLoadBarrierEv() {
#if (defined(_ARCH_PPC) || defined(_ARCH_450) || defined(_ARCH_450d))
   x10_atomic_ops_ppc_sync();
#endif
}

/**
* Ensure that all data from stores before the barrier
* has been flushed before any data for stores after
* the barrier is flushed.
*/
void _ZN3x104util10concurrent6Fences17storeStoreBarrierEv() {
#if (defined(_ARCH_PPC) || defined(_ARCH_450) || defined(_ARCH_450d))
   x10_atomic_ops_ppc_lwsync();
#endif
}

