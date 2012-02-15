#ifndef X10_LOCK_H_
#define X10_LOCK_H_

#include "x10.h"

struct x10_lock;

// TODO: Implement destructor

// Lock methods
X10_EXTERN struct x10_lock *_ZN3x104util10concurrent4LockC1Ev(struct x10_lock *);
X10_EXTERN void _ZN3x104util10concurrent4Lock4lockEv(struct x10_lock *);
X10_EXTERN x10_boolean _ZN3x104util10concurrent4Lock7tryLockEv(struct x10_lock *);
X10_EXTERN void _ZN3x104util10concurrent4Lock6unlockEv(struct x10_lock *);
X10_EXTERN x10_int _ZN3x104util10concurrent4Lock12getHoldCountEv(struct x10_lock *);

#endif
