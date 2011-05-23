#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

#include <math.h>

X10_MAKE_COMPARETO(_ZN3x104lang6Double9compareToEd, x10_double)
X10_MAKE_HASHCODE(_ZN3x104lang6Double8hashCodeEv, x10_double)
X10_MAKE_EQUALS(_ZN3x104lang6Double6equalsEd, x10_double)
X10_MAKE_TYPENAME(_ZN3x104lang6Double8typeNameEv, x10_double, "x10.lang.Double")
X10_MAKE_EQUALS_ANY(_ZN3x104lang6Double6equalsEPN3x104lang3AnyE, x10_int)

/* 
 * For Double, we need a special toString() method to be compatible
 * to x10c++.  The following code is copied from
 * x10aux/basic_functions.cc.
 */

/* precondition: buf contains decimal point */
static void kill_excess_zeroes(wchar_t *buf, size_t sz)
{
	for (int i=sz-1 ; i>0 && (buf[i]==L'0' || buf[i]==T_('\0')) ; --i) {
		if (buf[i-1] == T_('.'))
			break;
		buf[i] = T_('\0');
	}
}

x10_string *_ZN3x104lang6Double8toStringEv(x10_double v)
{
#define STRBUF_SIZE 120
	wchar_t buf[STRBUF_SIZE] = T_("");
	if (isnan(v)) {
		swprintf(buf, STRBUF_SIZE, T_("NaN"));
	} else if (isinf(v) && v > 0.0) {
		swprintf(buf, STRBUF_SIZE, T_("Infinity")); 
	} else if (isinf(v) && v < 0.0) {
		swprintf(buf, STRBUF_SIZE, T_("-Infinity"));
	} else if (fabs(v) >= 1E-3 && fabs(v) < 1E7) {
		swprintf(buf, STRBUF_SIZE, T_("%.15f"), v);
		kill_excess_zeroes(buf, STRBUF_SIZE);
	} else if (v == 0.0) {
		swprintf(buf, STRBUF_SIZE, T_("%.1f"), v);
	} else {
		/* scientific notation */
		int e = (int)floor(log(fabs(v))/log(10.0)); /* exponent */
		/* volatile because reordering could change computed floating point value */
		volatile double m = v / pow(10.0, e); /* mantissa */
		if (e < -10) {
			/* avoid touching -Infinity */
			m = v * 1E10;
			m /= pow(10.0, e+10);
		}
		if (e < 0) {
			swprintf(buf, STRBUF_SIZE, T_("%.1f"), m);
		} else {
			swprintf(buf, STRBUF_SIZE, T_("%.16f"), m);
		}
		kill_excess_zeroes(buf, STRBUF_SIZE);
		wchar_t *rest = buf + wcslen(buf);
		swprintf(rest, STRBUF_SIZE + buf - rest, T_("E%d"), e);
	}
	return x10_string_from_wide_chars(buf);
#undef BUF_SIZE
}   


MAKE_BINOPS(_ZN3x104lang6Double, d, x10_double)
MAKE_CMPOPS(_ZN3x104lang6Double, d, x10_double)
MAKE_UNOPS(_ZN3x104lang6Double, v, x10_double)
x10_double _ZN3x104lang6DoublermEd(x10_double a, x10_double b)
{
	return fmod(a, b);
}
MAKE_CONFS(_ZN3x104lang6Double, x10_double)
