#include "x10_signal_octopos.h"

void _ZN3x104util10concurrent6SignalC1Ev(x10_signal *self)
{
	simple_signal_init(&self->signal, 1);
}

void _ZN3x104util10concurrent6Signal4waitEv(x10_signal *self)
{
	simple_signal_wait(&self->signal);
}

void _ZN3x104util10concurrent6Signal6signalEv(x10_signal *self)
{
	simple_signal_signal(&self->signal);
}
