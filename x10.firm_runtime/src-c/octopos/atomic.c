#include <stdio.h>
#include "util.h"

#include "async.h"

struct waiting_ilet_signal {
	struct waiting_ilet_signal *next;
	simple_signal              *signal;
};

typedef struct waiting_ilet_signal waiting_ilet_signal;

static recursive_spinlock   atomic_mutex;
static waiting_ilet_signal *atomic_signals;

static void broadcast(void)
{
	while (atomic_signals != NULL) {
		simple_signal_signal(atomic_signals->signal);
		atomic_signals = atomic_signals->next;
	}
}

static void __attribute__((constructor)) init_atomic(void)
{
	recursive_spinlock_init(&atomic_mutex);
	atomic_signals = NULL;
}

void _ZN3x104lang7Runtime11enterAtomicEv(void)
{
	recursive_spinlock_lock(&atomic_mutex);
	activity_inc_atomic_depth();
}

void _ZN3x104lang7Runtime10exitAtomicEv(void)
{
	activity_dec_atomic_depth();
	broadcast();
	recursive_spinlock_unlock(&atomic_mutex);
}

void _ZN3x104lang7Runtime17ensureNotInAtomicEv(void)
{
	unsigned atomic_depth = activity_get_atomic_depth();
	if (atomic_depth > 0)
		panic("Illegal Operation Exception!");
}

void _ZN3x104lang7Runtime11awaitAtomicEv(void)
{
	simple_signal signal;
	simple_signal_init(&signal, 1);

	waiting_ilet_signal wait;
	wait.signal    = &signal;
	wait.next      = atomic_signals;
	atomic_signals = &wait;

	recursive_spinlock_unlock(&atomic_mutex);
	simple_signal_wait(&signal);
	recursive_spinlock_lock(&atomic_mutex);
}
