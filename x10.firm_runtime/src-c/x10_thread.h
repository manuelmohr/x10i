#ifndef X10_THREAD_H_
#define X10_THREAD_H_

#include "x10_string.h"
#include "x10.h"

struct x10_thread;

// Returns the identifier of this thread.
X10_EXTERN x10_long x10_thread_get_id(struct x10_thread *);
// Returns the system thread id.
X10_EXTERN x10_long x10_thread_get_tid(void);
// Waits forever for this thread to die.
X10_EXTERN void x10_thread_join(struct x10_thread *);
// Tests if this thread is alive.
X10_EXTERN x10_boolean x10_thread_is_alive(struct x10_thread *);
// Interrupts this thread.
X10_EXTERN void x10_thread_interrupt(struct x10_thread *);

// Thread methods
X10_EXTERN struct x10_thread *_ZN3x104lang6ThreadC1EPN3x104lang6StringE(struct x10_thread *, x10_string *);
X10_EXTERN struct x10_thread *_ZN3x104lang6Thread13currentThreadEv(void);
X10_EXTERN void _ZN3x104lang6Thread5startEv(struct x10_thread *);
X10_EXTERN void _ZN3x104lang6Thread5sleepEx(struct x10_thread *, x10_long);
X10_EXTERN void _ZN3x104lang6Thread5sleepExi(struct x10_thread *, x10_long, x10_int);
X10_EXTERN void _ZN3x104lang6Thread4parkEv(void);
X10_EXTERN void _ZN3x104lang6Thread9parkNanosEx(x10_long);
X10_EXTERN void _ZN3x104lang6Thread6unparkEv(struct x10_thread *);

X10_EXTERN void _ZN3x104lang6Thread4nameEPN3x104lang6StringE(struct x10_thread *, x10_string *);
X10_EXTERN void _ZN3x104lang6ThreadapplyEv(struct x10_thread *);
X10_EXTERN x10_string *_ZN3x104lang6Thread4nameEv(struct x10_thread *);

// TODO: Add home struct as return type
X10_EXTERN x10_any *_ZN3x104lang6Thread4homeEv(struct x10_thread *);

#endif
