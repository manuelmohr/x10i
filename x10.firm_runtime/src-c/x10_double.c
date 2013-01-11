#include <stddef.h>
#include <stdio.h>
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
static size_t kill_excess_zeroes(char *buf, size_t sz)
{
	if (sz == 0 || buf[sz-1] != '0')
		return sz;
	for (size_t i = sz; i-- > 0; ) {
		if (buf[i] != '0' || (i>1 && buf[i-1] == '.')) {
			return i + 1;
		}
	}
	return sz;
}

x10_string *_ZN3x104lang6Double8toStringEv(x10_double v)
{
	x10_char buf[120];
	if (isnan(v)) {
		return X10_STRING_FROM_CLITERAL("NaN");
	} else if (isinf(v)) {
		if (v > 0.0)
			return X10_STRING_FROM_CLITERAL("Infinity");
		else
			return X10_STRING_FROM_CLITERAL("-Infinity");
	} else if (fabs(v) >= 1E-3 && fabs(v) < 1E7) {
		size_t p = (size_t)snprintf(buf, sizeof(buf), "%.15f", v);
		p = kill_excess_zeroes(buf, p);
		buf[p] = '\0';
	} else if (v == 0.0) {
		snprintf(buf, sizeof(buf), "%.1f", v);
	} else {
		/* scientific notation */
		int e = (int)floor(log(fabs(v))/log(10.0)); /* exponent */
		/* volatile because reordering could change computed floating point value */
		double m = v / pow(10.0, e); /* mantissa */
		if (e < -10) {
			/* avoid touching -Infinity */
			m = v * 1E10;
			m /= pow(10.0, e+10);
		}
		size_t p;
		if (e < 0) {
			p = (size_t) snprintf(buf, sizeof(buf), "%.1f", m);
		} else {
			p = (size_t) snprintf(buf, sizeof(buf), T_("%.16f"), m);
		}
		p = kill_excess_zeroes(buf, p);
		snprintf(buf+p, sizeof(buf)+p, "E%d", e);
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
	return isnan(self);
}

/* x10.lang.Double.isInfinite(): Boolean */
x10_boolean _ZN3x104lang6Double10isInfiniteEv(x10_double self)
{
	return isinf(self);
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
