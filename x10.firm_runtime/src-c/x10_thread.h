#ifndef X10_THREAD_H
#define X10_THREAD_H

#include "x10_string.h"
#include "x10.h"

typedef struct x10_thread x10_thread;
typedef struct x10_place  x10_place;

// Returns the identifier of this thread.
x10_long x10_thread_get_id(x10_thread *);
// Returns the system thread id.
x10_long x10_thread_get_tid(void);
// Waits forever for this thread to die.
void x10_thread_join(x10_thread *);
// Tests if this thread is alive.
x10_boolean x10_thread_is_alive(x10_thread *);
// Interrupts this thread.
void x10_thread_interrupt(x10_thread *);

// Thread methods
x10_thread *_ZN3x104lang6ThreadC1EPN3x104lang6StringE(x10_thread *, x10_string *);
x10_thread *_ZN3x104lang6Thread13currentThreadEv(void);
void _ZN3x104lang6Thread5startEv(x10_thread *);
void _ZN3x104lang6Thread5sleepEx(x10_long);
void _ZN3x104lang6Thread5sleepExi(x10_long, x10_int);
void _ZN3x104lang6Thread4parkEv(void);
void _ZN3x104lang6Thread9parkNanosEx(x10_long);
void _ZN3x104lang6Thread6unparkEv(x10_thread *);

void _ZN3x104lang6Thread4nameEPN3x104lang6StringE(x10_thread *, x10_string *);
x10_string *_ZN3x104lang6Thread4nameEv(x10_thread *);

// TODO: Add Place struct as return type
x10_place _ZN3x104lang6Thread4homeEv(x10_thread *);

#endif
