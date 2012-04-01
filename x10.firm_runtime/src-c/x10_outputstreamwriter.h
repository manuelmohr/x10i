#ifndef X10_OUTPUTSTREAMWRITER_H
#define X10_OUTPUTSTREAMWRITER_H

#include <stdio.h>
#include "x10.h"

typedef struct x10_outputstreamwriter {
	x10_object  base;
	FILE       *out;
} x10_outputstreamwriter;

#endif
