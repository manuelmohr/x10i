#ifndef X10_LOCK_H_
#define X10_LOCK_H_

#include <pthread.h>

#include "x10.h"

typedef struct {
	X10_OBJECT_HEADER
   // lock id
   pthread_mutex_t __lock;
   // lock attributes
   pthread_mutexattr_t __lock_attr;
} x10_lock;

// TODO: Implement destructor

// Lock methods
X10_EXTERN x10_lock *_ZN3x104util10concurrent4LockC1Ev(x10_lock *);
X10_EXTERN void _ZN3x104util10concurrent4Lock4lockEv(x10_lock *);
X10_EXTERN x10_boolean _ZN3x104util10concurrent4Lock7tryLockEv(x10_lock *);
X10_EXTERN void _ZN3x104util10concurrent4Lock6unlockEv(x10_lock *);
X10_EXTERN x10_int _ZN3x104util10concurrent4Lock12getHoldCountEv(x10_lock *);

#endif
