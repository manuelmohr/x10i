/*
 *  This file is part of the X10 project (http://x10-lang.org).
 *
 *  This file is licensed to You under the Eclipse Public License (EPL);
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *      http://www.opensource.org/licenses/eclipse-1.0.php
 *
 *  (C) Copyright IBM Corporation 2006-2010.
 */

#include "../x10_atomic_ops.h"

#include <pthread.h>

/**
 * Atomic compare and swap of a 32 bit value.
 * The semantics of this operation are:
 * <pre>
 *
 * x10_int tmp;
 * Atomic {
 *    tmp = *address;
 *    if (tmp == oldValue) *address = newValue;
 * }
 * return tmp;
 *
 * </pre>
 */
x10_int x10_atomic_ops_compareAndSet_32(volatile x10_int* address, x10_int oldValue, x10_int newValue) {
#if defined(__i386__) || defined(__x86_64__)
   __asm ("lock cmpxchgl %2, %3"
          : "=a" (oldValue), "+m" (*address)
          : "q" (newValue), "m" (*address), "0" (oldValue)
          : "cc");
   return oldValue;
#elif (defined(_ARCH_PPC) || defined(_ARCH_450) || defined(_ARCH_450d))
   return ppc_compareAndSet32(oldValue, address, newValue);
#elif defined(__sparc__)
	#if defined(__sparc_v9__)
		/* FIXME: is the memory barrier needed? */
		__asm__ __volatile__("cas [%2], %3, %0\n\t"
		                     "membar #StoreLoad | #StoreStore"
		                     : "=&r" (newValue)
		                     : "0" (newValue), "r" (address), "r" (oldValue)
		                     : "memory");
		return newValue;
	#else
		(void) address;
		(void) oldValue;
		(void) newValue;
		X10_UNIMPLEMENTED();
	#endif
#else
	#error "Unknown architecture"
#endif
}

static pthread_mutexattr_t attr;
static pthread_mutex_t     opLock;

static void x10_atomic_ops_lock()
{
	pthread_mutex_lock(&opLock);
}

static void x10_atomic_ops_unlock()
{
    pthread_mutex_unlock(&opLock);
}

static void __attribute__((constructor)) init_locks(void)
{
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&opLock, &attr);
}

static void __attribute__((destructor)) destroy_locks(void)
{
	pthread_mutex_destroy(&opLock);
	pthread_mutexattr_destroy(&attr);
}

/**
 * Atomic compare and swap of a 64 bit value.
 * The semantics of this operation are:
 * <pre>
 *
 * x10_int tmp;
 * Atomic {
 *    tmp = *address;
 *    if (tmp == oldValue) *address = newValue;
 * }
 * return tmp;
 *
 * </pre>
 */
x10_long x10_atomic_ops_compareAndSet_64(volatile x10_long* address, x10_long oldValue, x10_long newValue) {
#if !defined(_LP64)
   /* TODO: in theory on i586 hardware we could do this with inline asm and cmpxchg8b instead of a mutex,
    * but it isn't trivial to get the register constraints to work correctly.
    */
   x10_atomic_ops_lock();
   x10_long curValue = *address;
   if (curValue == oldValue) {
       *address = newValue;
   }
   x10_atomic_ops_unlock();
   return curValue;
#else
#if defined(__x86_64__)
   __asm ("lock cmpxchgq %2, %3"
          : "=a" (oldValue), "+m" (*address)
          : "q" (newValue), "m" (*address), "0" (oldValue)
          : "cc");
   return oldValue;
#elif (defined(_ARCH_PPC) || defined(_ARCH_450) || defined(_ARCH_450d))
   return ppc_compareAndSet64(oldValue, address, newValue);
#elif defined(__sparc__)
	#if defined(__sparc_v9__)
		/* FIXME: is the memory barrier needed? */
		__asm__ __volatile__("casx [%2], %3, %0\n\t"
		                     "membar #StoreLoad | #StoreStore"
		                     : "=&r" (newValue)
		                     : "0" (newValue), "r" (address), "r" (oldValue)
		                     : "memory");
		return newValue;
	#else
		(void) address;
		(void) oldValue;
		(void) newValue;
		X10_UNIMPLEMENTED();
	#endif
#else
	#error "Unknown architecture"
#endif
#endif
}

/**
 * Atomic compare and swap of a pointer value.
 * The semantics of this operation are:
 * <pre>
 *
 * x10_int tmp;
 * Atomic {
 *    tmp = *address;
 *    if (tmp == oldValue) *address = newValue;
 * }
 * return tmp;
 *
 * </pre>
 */
void* x10_atomic_ops_compareAndSet_ptr(volatile void** address, void* oldValue, void* newValue) {
#if defined(_LP64)
   return (void*)(x10_atomic_ops_compareAndSet_64((volatile x10_long*)address, (x10_long)oldValue, (x10_long)newValue));
#else
   return (void*)(x10_atomic_ops_compareAndSet_32((volatile x10_int*)address, (x10_int)oldValue, (x10_int)newValue));
#endif
}

/**
 * Ensure that all loads before the barrier have loaded their
 * data before any load after the data accesses its data.
 */
void _ZN3x104util10concurrent6Fences15loadLoadBarrierEv() {
}

/**
 * Ensure that all loads before the barrier have loaded
 * their data before any data stored by a store after
 * the barrier has been flushed.
 */
void _ZN3x104util10concurrent6Fences16loadStoreBarrierEv() {
}

/**
 * Ensure that all data from stores before the barrier
 * has been flushed before any data for loads after the
 * barrier is accessed.
 */
void _ZN3x104util10concurrent6Fences16storeLoadBarrierEv() {
}

/**
 * Ensure that all data from stores before the barrier
 * has been flushed before any data for stores after
 * the barrier is flushed.
 */
void _ZN3x104util10concurrent6Fences17storeStoreBarrierEv() {
}
