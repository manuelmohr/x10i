#ifndef X10_DOUBLE_H_
#define X10_DOUBLE_H_

#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang6Double9compareToEd, x10_double)
X10_MAKE_EQUALS(_ZN3x104lang6Double6equalsEd, x10_double)

// typename
x10_string *_ZN3x104lang6Double8typeNameEv(x10_double self) { 
	UNUSED(self); 
	return x10_string_from_wide_chars(T_("x10.lang.Double")); 
}

MAKE_BINOPS(_ZN3x104lang6Double, d, x10_double)
MAKE_CMPOPS(_ZN3x104lang6Double, d, x10_double)
MAKE_UNOPS(_ZN3x104lang6Double, v, x10_double)
x10_double _ZN3x104lang6DoublermEd(x10_double a, x10_double b)
{
	return fmod(a, b);
}
MAKE_CONFS(_ZN3x104lang6Double, x10_double)

x10_string *_ZN3x104lang6Double8toStringEv(x10_double self) {
	wchar_t buf[64];
	swprintf(buf, sizeof(buf) / sizeof(wchar_t), L"%lf", self);
	return x10_string_from_wide_chars(buf);
}

x10_boolean _ZN3x104lang6Double6equalsEPN3x104lang3AnyE(x10_double self,
		x10_any *other)
{
	// TODO Implement me.

	UNUSED(self);
	switch (X10_TYPE(other)) {
	default:
		return false;
	};
}

#endif // X10_DOUBLE_H_
