#ifndef X10_INPUTSTREAMREADER_H
#define X10_INPUTSTREAMREADER_H

#include <stdio.h>
#include "x10.h"

typedef struct x10_inputstreamreader {
	x10_object  base;
	FILE       *in;
} x10_inputstreamreader;

#endif
