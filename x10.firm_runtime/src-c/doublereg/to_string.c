#include "types.h"
#include "x10_string.h"
#include <math.h>
#include <stdio.h>

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
			p = (size_t) snprintf(buf, sizeof(buf), "%.16f", m);
		}
		p = kill_excess_zeroes(buf, p);
		snprintf(buf+p, sizeof(buf)+p, "E%d", e);
	}
	return x10_string_from_cstring(buf);
}
