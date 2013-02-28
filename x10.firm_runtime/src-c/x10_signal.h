#ifndef X10_SIGNAL_H
#define X10_SIGNAL_H

#include "types.h"

typedef struct x10_signal x10_signal;

void _ZN3x104util10concurrent6SignalC1Ev(x10_signal *);
void _ZN3x104util10concurrent6Signal4waitEv(x10_signal *);
void _ZN3x104util10concurrent6Signal6signalEv(x10_signal *);

#endif
