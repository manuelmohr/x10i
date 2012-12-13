#ifndef X10_RUNTIME_H
#define X10_RUNTIME_H

#include "x10_object.h"

/* x10.lang.Runtime.execute(body: ()=>void): void
 * implemented in X10 */
extern void _ZN3x104lang7Runtime7executeEPN3x104lang12$VoidFun_0_0E(x10_object *body);
/* x10.lang.Runtime.evaluate(eval: ()=>Any): Any
 * implemented in X10 */
extern void *_ZN3x104lang7Runtime8evaluateEPN3x104lang8$Fun_0_0IPN3x104lang3AnyEEE(x10_object *closure);

#endif
