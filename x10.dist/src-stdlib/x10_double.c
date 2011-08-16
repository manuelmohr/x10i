#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang6Double9compareToEd, x10_double)
X10_MAKE_HASHCODE(_ZN3x104lang6Double8hashCodeEv, x10_double)
X10_MAKE_EQUALS(_ZN3x104lang6Double6equalsEd, x10_double)

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
#undef STRBUF_SIZE
}

MAKE_BINOPS(_ZN3x104lang6Double, d, x10_double)
MAKE_CMPOPS(_ZN3x104lang6Double, d, x10_double)
MAKE_UNOPS(_ZN3x104lang6Double, v, x10_double)
x10_double _ZN3x104lang6DoublermEd(x10_double a, x10_double b)
{
	return fmod(a, b);
}
MAKE_CONFS(_ZN3x104lang6Double, x10_double)

/* Use to move bits between x10_long/x10_double without confusing the compiler */
typedef union TypePunner {
    x10_long l;
    x10_double d;
} TypePunner;

x10_long _ZN3x104lang6Double13toRawLongBitsEv(x10_double self)
{
    TypePunner tmp;
    tmp.d = self;
    return tmp.l;
}

x10_double _ZN3x104lang6Double12fromLongBitsEx(x10_long digits)
{
    TypePunner tmp;
    tmp.l = digits;
    return tmp.d;
}

x10_boolean _ZN3x104lang6Double5isNaNEv(x10_double self)
{
	return isnan(self) != 0 ? X10_TRUE : X10_FALSE;
}

x10_boolean _ZN3x104lang6Double10isInfiniteEv(x10_double self)
{
	return isinf(self) != 0 ? X10_TRUE : X10_FALSE;
}

x10_long _ZN3x104lang6Double10toLongBitsEv(x10_double self)
{
	return _ZN3x104lang6Double5isNaNEv(self) ? 0x7ff8000000000000LL : _ZN3x104lang6Double13toRawLongBitsEv(self);
}

x10_string *_ZN3x104lang6Double11toHexStringEv(x10_double self)
{
	UNUSED(self);
	X10_UNIMPLEMENTED();
	return X10_NULL;
}

