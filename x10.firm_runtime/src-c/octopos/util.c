#include <octo_leon.h>
#include "types.h"

x10_ulong _ZN7octopos4Util15getNocTimestampE(void)
{
	return leon_get_noc_ts();
}
