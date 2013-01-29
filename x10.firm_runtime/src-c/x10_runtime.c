#include <stdio.h>

#include "remote_exec.h"

void _ZN3x104lang7Runtime15runAtOtherPlaceEiPN3x104lang3AnyE(x10_int place_id, x10_object *closure)
{
	x10_execute_at(place_id, MSG_RUN_AT, closure);
}

x10_object *_ZN3x104lang7Runtime16evalAtOtherPlaceEiPN3x104lang3AnyE(x10_int place_id, x10_object *closure)
{
	return x10_execute_at(place_id, MSG_EVAL_AT, closure);
}
