#ifndef X10_OUTPUTSTREAMWRITER_H
#define X10_OUTPUTSTREAMWRITER_H

#include <stdio.h>
#include "types.h"

typedef struct X10_TYPE("x10.io.OutputStreamWriter") x10_outputstreamwriter {
	x10_object  base;
	FILE       *out;
} x10_outputstreamwriter;

#endif
