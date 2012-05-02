#ifndef X10_LOCK_H_
#define X10_LOCK_H_

#include "x10.h"

typedef struct x10_lock x10_lock;

// TODO: Implement destructor

// Lock methods
void _ZN3x104util10concurrent4LockC1Ev(x10_lock *);
void _ZN3x104util10concurrent4Lock4lockEv(x10_lock *);
x10_boolean _ZN3x104util10concurrent4Lock7tryLockEv(x10_lock *);
void _ZN3x104util10concurrent4Lock6unlockEv(x10_lock *);
x10_int _ZN3x104util10concurrent4Lock12getHoldCountEv(x10_lock *);

#endif
