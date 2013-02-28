#ifndef OCTOPOS_X10_SIGNAL_OCTOPOS_H
#define OCTOPOS_X10_SIGNAL_OCTOPOS_H

#include <octopos.h>
#include "types.h"
#include "x10_signal.h"

struct X10_TYPE("x10.util.concurrent.Signal") x10_signal {
	x10_object    base;
	simple_signal signal;
};

#endif
