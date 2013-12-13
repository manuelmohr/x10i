#include <stdio.h>

#include "remote_exec.h"
#include "places.h"

void __attribute__((weak)) _ZN3x104lang7Runtime15callVoidClosureEPN3x104lang12$VoidFun_0_0E(x10_object *closure)
{
	/** dummy implementation, normal X10 should override this */
	(void)closure;
	abort();
}

x10_object *__attribute__((weak)) _ZN3x104lang7Runtime14callAnyClosureEPN3x104lang8$Fun_0_0IPN3x104lang3AnyEEE(x10_object *closure)
{
	/** dummy implementation, normal X10 should override this */
	(void)closure;
	abort();
}


void _ZN3x104lang7Runtime15runAtOtherPlaceEiPN3x104lang3AnyE(x10_int place_id, x10_object *closure)
{
	x10_execute_at(place_id, MSG_RUN_AT, closure);
}

x10_object *_ZN3x104lang7Runtime16evalAtOtherPlaceEiPN3x104lang3AnyE(x10_int place_id, x10_object *closure)
{
	return x10_execute_at(place_id, MSG_EVAL_AT, closure);
}

// x10.lang.Runtime.getHere() : Int
x10_int _ZN3x104lang7Runtime9getHereIdEv()
{
#ifdef USE_AGENTSYSTEM
	return x10_get_here_placeid();
#else
	return (x10_int)place_id;
#endif
}
