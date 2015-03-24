#include <math.h>

#include "types.h"

#ifdef DOUBLE_IS_32BIT
	#define FUN(x) x##f
#else
	#define FUN(x) x
#endif

x10_double _ZN3x104lang4Math4ceilEd(x10_double a)  { return FUN(ceil)(a); }
x10_double _ZN3x104lang4Math5floorEd(x10_double a) { return FUN(floor)(a); }
x10_double _ZN3x104lang4Math5roundEd(x10_double a) { return FUN(round)(a); }
x10_double _ZN3x104lang4Math3powEdd(x10_double a, x10_double b) { return FUN(pow)(a, b); }
x10_double _ZN3x104lang4Math3expEd(x10_double a) { return FUN(exp)(a); }
x10_float  _ZN3x104lang4Math3expEf(x10_float a) { return FUN(exp)(a); }
x10_double _ZN3x104lang4Math5expm1Ed(x10_double a) { return FUN(expm1)(a); }
x10_double _ZN3x104lang4Math3cosEd(x10_double a) { return FUN(cos)(a); }
x10_double _ZN3x104lang4Math3sinEd(x10_double a) { return FUN(sin)(a); }
x10_double _ZN3x104lang4Math3tanEd(x10_double a) { return FUN(tan)(a); }
x10_double _ZN3x104lang4Math4acosEd(x10_double a) { return FUN(acos)(a); }
x10_double _ZN3x104lang4Math4asinEd(x10_double a) { return FUN(asin)(a); }
x10_double _ZN3x104lang4Math4atanEd(x10_double a) { return FUN(atan)(a); }
x10_double _ZN3x104lang4Math5atan2Edd(x10_double a, x10_double b) { return FUN(atan2)(a, b); }
x10_double _ZN3x104lang4Math4coshEd(x10_double a) { return FUN(cosh)(a); }
x10_double _ZN3x104lang4Math4sinhEd(x10_double a) { return FUN(sinh)(a); }
x10_double _ZN3x104lang4Math4tanhEd(x10_double a) { return FUN(tanh)(a); }
x10_double _ZN3x104lang4Math4sqrtEd(x10_double a) { return FUN(sqrt)(a); }
x10_float  _ZN3x104lang4Math4sqrtEf(x10_float a) { return FUN(sqrt)(a); }
x10_double _ZN3x104lang4Math4cbrtEd(x10_double a) { return FUN(cbrt)(a); }
x10_double _ZN3x104lang4Math3erfEd(x10_double a) { return FUN(erf)(a); }
x10_double _ZN3x104lang4Math4erfcEd(x10_double a) { return FUN(erfc)(a); }
x10_double _ZN3x104lang4Math5hypotEdd(x10_double a, x10_double b) { return FUN(hypot)(a, b); }
x10_double _ZN3x104lang4Math3logEd(x10_double a) { return FUN(log)(a); }
x10_float  _ZN3x104lang4Math3logEf(x10_float a) { return FUN(log)(a); }
x10_double _ZN3x104lang4Math5log10Ed(x10_double a) { return FUN(log10)(a); }
x10_double _ZN3x104lang4Math5log1pEd(x10_double a) { return FUN(log1p)(a); }
x10_double _ZN3x104lang4Math8copySignEdd(x10_double a, x10_double b) { return FUN(copysign)(a, b); }
