#ifndef POSIX_X10_INPUTSTREAMREADER_H
#define POSIX_X10_INPUTSTREAMREADER_H

#include <stdio.h>
#include "x10.h"

typedef struct X10_TYPE("x10.io.InputStreamReader") x10_inputstreamreader {
	x10_object  base;
	FILE       *in;
} x10_inputstreamreader;

#endif
