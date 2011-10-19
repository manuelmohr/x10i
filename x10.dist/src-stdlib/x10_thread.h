#ifndef X10_THREAD_H_
#define X10_THREAD_H_

#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>

#include "x10_string.h"
#include "x10.h"

// execution thread condition & associated lock pair
typedef struct {
	pthread_cond_t cond;
	pthread_mutex_t mutex;
} cond_mutex_t;

// thread permit type
typedef struct {
	pthread_cond_t cond;
	pthread_mutex_t mutex;
	x10_boolean permit;
} permit_t;

typedef struct {
	X10_OBJECT_HEADER
	// thread id
	x10_long __thread_id;
	// thread name
	x10_string *__thread_name;
	// thread's pthread id
	pthread_t __xthread;
	// thread attributes
	pthread_attr_t __xthread_attr;
	// thread run flags
	x10_boolean __thread_already_started;
	x10_boolean __thread_running;
	// thread start condition & associated lock
	pthread_cond_t __thread_start_cond;
	pthread_mutex_t __thread_start_lock;
	// thread specific permit object
	permit_t __thread_permit;
} x10_thread;

// Returns the identifier of this thread.
X10_EXTERN x10_long x10_thread_get_id(x10_thread *);
// Returns the system thread id.
X10_EXTERN x10_long x10_thread_get_tid();
// Waits forever for this thread to die.
X10_EXTERN void x10_thread_join(x10_thread *);
// Tests if this thread is alive.
X10_EXTERN x10_boolean x10_thread_is_alive(x10_thread *);
// Interrupts this thread.
X10_EXTERN void x10_thread_interrupt(x10_thread *);

// Thread methods
X10_EXTERN x10_thread * _ZN3x104lang6ThreadC1EPN3x104lang6StringE(x10_thread *, x10_string *);
X10_EXTERN x10_thread *_ZN3x104lang6Thread13currentThreadEv();
X10_EXTERN void _ZN3x104lang6Thread5startEv(x10_thread *);
X10_EXTERN void _ZN3x104lang6Thread5sleepEx(x10_thread *, x10_long);
X10_EXTERN void _ZN3x104lang6Thread5sleepExi(x10_thread *, x10_long, x10_int);
X10_EXTERN void _ZN3x104lang6Thread4parkEv();
X10_EXTERN void _ZN3x104lang6Thread9parkNanosEx(x10_long);
X10_EXTERN void _ZN3x104lang6Thread6unparkEv(x10_thread *);

X10_EXTERN void _ZN3x104lang6Thread4nameEPN3x104lang6StringE(x10_thread *, x10_string *);
X10_EXTERN void _ZN3x104lang6ThreadapplyEv(x10_thread *);
X10_EXTERN x10_string *_ZN3x104lang6Thread4nameEv(x10_thread *);

// TODO: Add home struct as return type
X10_EXTERN x10_any *_ZN3x104lang6Thread4homeEv(x10_thread *);

#endif // X10_THREAD_H_
