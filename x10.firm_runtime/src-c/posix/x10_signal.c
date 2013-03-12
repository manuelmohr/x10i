#include <pthread.h>
#include <stdio.h>

#include "x10_signal_posix.h"

void _ZN3x104util10concurrent6SignalC1Ev(x10_signal *self)
{
	pthread_mutex_init(&self->x10_signal_mutex, NULL);
	pthread_cond_init(&self->x10_signal_cond, NULL);
}

void _ZN3x104util10concurrent6Signal4waitEv(x10_signal *self)
{
	pthread_mutex_lock(&self->x10_signal_mutex);
	pthread_cond_wait(&self->x10_signal_cond, &self->x10_signal_mutex);
	pthread_mutex_unlock(&self->x10_signal_mutex);
}

void _ZN3x104util10concurrent6Signal6signalEv(x10_signal *self)
{
	pthread_cond_broadcast(&self->x10_signal_cond);
}
