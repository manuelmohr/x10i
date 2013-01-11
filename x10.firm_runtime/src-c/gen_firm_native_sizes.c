#include <stdio.h>
/* make sure all X10_TYPE headers are included */

/* this is the definition used by the cparser --print-compound-sizes flag
 * which then prints the size of all dllexported types and uses "x" as
 * description */
#define X10_TYPE(x)  __attribute__((dllexport, deprecated(x)))

#include "types.h"
#include "x10_string.h"
#include "x10_outputstreamwriter.h"
#include "platform_native_sizes.c"

