#include <stddef.h>
#include "x10.h"
#include "x10_string.h"

/* x10.lang.Double.operator%(Double):Double */
x10_double _ZN3x104lang6DoublermEd(x10_double a, x10_double b)
{
	return fmod(a, b);
}

/* x10.lang.Double.toHexString():String */
x10_string *_ZN3x104lang6Double11toHexStringEv(x10_double self)
{
	X10_UNUSED(self);
	X10_UNIMPLEMENTED();
	return X10_NULL;
}

/*
 * For Double, we need a special toString() method to be compatible
 * to x10c++.  The following code is copied from
 * x10aux/basic_functions.cc.
 */

/* precondition: buf contains decimal point */
static void kill_excess_zeroes(char *buf, size_t sz)
{
	if (buf[sz-1] != '0')
		return;
	size_t i;
	for (i = sz; i-- > 0; ) {
		if (buf[i] != '0') {
			buf[i+1] = '\0';
			break;
		}
	}
}

x10_string *_ZN3x104lang6Double8toStringEv(x10_double v)
{
	x10_char buf[120];
	if (isnan(v)) {
		return x10_string_from_cstring("NaN");
	} else if (isinf(v)) {
		return x10_string_from_cstring(v > 0.0 ? "Infinity" : "-Infinity");
	} else if (fabs(v) >= 1E-3 && fabs(v) < 1E7) {
		snprintf(buf, sizeof(buf), "%.15f", v);
		kill_excess_zeroes(buf, sizeof(buf));
	} else if (v == 0.0) {
		snprintf(buf, sizeof(buf), "%.1f", v);
	} else {
#ifdef __OCTOPOS__
		abort();
#else
		/* scientific notation */
		int e = (int)floor(log(fabs(v))/log(10.0)); /* exponent */
		/* volatile because reordering could change computed floating point value */
		double m = v / pow(10.0, e); /* mantissa */
		if (e < -10) {
			/* avoid touching -Infinity */
			m = v * 1E10;
			m /= pow(10.0, e+10);
		}
		if (e < 0) {
			snprintf(buf, sizeof(buf), "%.1f", m);
		} else {
			snprintf(buf, sizeof(buf), T_("%.16f"), m);
		}
		kill_excess_zeroes(buf, sizeof(buf));
		char *rest = buf + strlen(buf);
		snprintf(rest, sizeof(buf)+buf-rest, "E%d", e);
#endif
	}
	return x10_string_from_cstring(buf);
}

/* static x10.lang.Double.parse(String): Double */
x10_double _ZN3x104lang6Double5parseEPN3x104lang6StringE(x10_string *string)
{
	X10_UNUSED(string);
	X10_UNIMPLEMENTED();
	return NAN;
}

/* x10.lang.Double.isNaN(): Boolean */
x10_boolean _ZN3x104lang6Double5isNaNEv(x10_double self)
{
	return isnan(self) ? X10_TRUE : X10_FALSE;
}

/* x10.lang.Double.isInfinite(): Boolean */
x10_boolean _ZN3x104lang6Double10isInfiniteEv(x10_double self)
{
	return isinf(self) ? X10_TRUE : X10_FALSE;
}

/* x10.lang.Double.toLongBits(): Long */
x10_long _ZN3x104lang6Double13toRawLongBitsEv(x10_double self)
{
	assert(sizeof(x10_long) == sizeof(x10_double));
	char buf[sizeof(x10_double)];
	x10_double *as_double = (x10_double*)buf;
	x10_long   *as_long   = (x10_long*)buf;
	*as_double = self;
	return *as_long;
}

/* static x10.lang.Double.fromLongBits(Long): Double */
x10_double _ZN3x104lang6Double12fromLongBitsEx(x10_long x)
{
	assert(sizeof(x10_long) == sizeof(x10_double));
	char buf[sizeof(x10_double)];
	x10_double *as_double = (x10_double*)buf;
	x10_long   *as_long   = (x10_long*)buf;
	*as_long = x;
	return *as_double;
}
