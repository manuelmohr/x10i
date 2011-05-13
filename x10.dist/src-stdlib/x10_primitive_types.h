#ifndef X10_PRIMITIVE_TYPES_H_
#define X10_PRIMITIVE_TYPES_H_

#include "x10_util.h"

#define X10_MAKE_COMPARETO(name, type)	\
	x10_int name(type self, type other) { return (self == other) ? 0 : (self < other) ? - 1 : 1; }

#define X10_MAKE_EQUALS(name, type) \
	x10_boolean name(type self, type other) { return (self == other); }

#define X10_MAKE_TOSTRING(name, type, fmt) \
x10_string *name(type self) \
{ \
	wchar_t buf[64]; \
	swprintf(buf, sizeof(buf) / sizeof(wchar_t), L##fmt, self); \
	return x10_string_from_wide_chars(buf); \
}

#define X10_MAKE_TYPENAME(name, type, str) \
x10_string *name(type self) \
{ \
	UNUSED(self); \
	return x10_string_from_wide_chars(L##str); \
}

// TODO:  Implement me.
#define X10_MAKE_EQUALS_ANY(name, type) \
x10_boolean name(type self, x10_any *other) \
{ \
\
	UNUSED(self); \
	switch (X10_TYPE(other)) { \
	default: \
		return false; \
	}; \
}

#define X10_MAKE_HASHCODE(name, type) \
x10_int name(type self) \
{ \
	return x10_hashCode((const unsigned char *)&self, sizeof(self)); \
}

#define BINOP(name, type, op)  \
	type name(type a, type b) { return a op b; }

#define MAKE_BINOPS(prefix, postfix, type) \
	BINOP(prefix ## plE ## postfix, type, +) \
	BINOP(prefix ## miE ## postfix, type, -) \
	BINOP(prefix ## mlE ## postfix, type, *) \
	BINOP(prefix ## dvE ## postfix, type, /)

#define MAKE_CMPOPS(prefix, postfix, type) \
	BINOP(prefix ## eqE ## postfix, type, ==) \
	BINOP(prefix ## neE ## postfix, type, !=) \
	BINOP(prefix ## ltE ## postfix, type, <) \
	BINOP(prefix ## gtE ## postfix, type, >) \
	BINOP(prefix ## leE ## postfix, type, <=) \
	BINOP(prefix ## geE ## postfix, type, >=)

#define MAKE_INT_BINOPS(prefix, postfix, type) \
	MAKE_BINOPS(prefix, postfix, type) \
	BINOP(prefix ## rmE ## postfix, type, %) \
	BINOP(prefix ## anE ## postfix, type, &) \
	BINOP(prefix ## orE ## postfix, type, |) \
	BINOP(prefix ## eoE ## postfix, type, ^) \
	BINOP(prefix ## lsE ## postfix, type, <<) \
	BINOP(prefix ## rsE ## postfix, type, >>)

#define UNOP(name, type, op)  \
	type name(type a) { return op a; }

#define MAKE_UNOPS(prefix, postfix, type) \
	UNOP(prefix ## psE ## postfix, type, +) \
	UNOP(prefix ## ngE ## postfix, type, -)

#define MAKE_INT_UNOPS(prefix, postfix, type) \
	MAKE_UNOPS(prefix, postfix, type) \
	UNOP(prefix ## coE ## postfix, type, ~)

#define MAKE_CONF(prefix, suffix, fromtype, totype) \
	totype prefix##cv##E##suffix (fromtype a) { return (totype) a; }

// implicit conf
#define MAKE_IMP_CONF(prefix, suffix, fromtype, totype) \
	totype prefix##v3icv##E##suffix (fromtype a) { return (totype) a; }

#define MAKE_CONFS(prefix, fromtype) \
	MAKE_CONF(prefix, x, x10_long,  fromtype) \
	MAKE_CONF(prefix, i, x10_int,  fromtype) \
	MAKE_CONF(prefix, s, x10_short,  fromtype) \
	MAKE_CONF(prefix, a, x10_byte,   fromtype) \
	MAKE_CONF(prefix, f, x10_float,    fromtype) \
	MAKE_CONF(prefix, d, x10_double,   fromtype) \
	MAKE_IMP_CONF(prefix, x, x10_long,  fromtype) \
	MAKE_IMP_CONF(prefix, i, x10_int,  fromtype) \
	MAKE_IMP_CONF(prefix, s, x10_short,  fromtype) \
	MAKE_IMP_CONF(prefix, a, x10_byte,   fromtype) \
	MAKE_IMP_CONF(prefix, f, x10_float,    fromtype) \
	MAKE_IMP_CONF(prefix, d, x10_double,   fromtype) \

#endif // X10_PRIMITIVE_TYPES_H_

