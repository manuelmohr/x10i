#ifndef X10_PRIMITIVE_TYPES_H_
#define X10_PRIMITIVE_TYPES_H_

#include "x10_util.h"
#include "util.h"

#define X10_MAKE_TYPENAME(name, type, str) \
x10_string *name(type self) \
{ \
   X10_UNUSED(self); \
   return x10_string_from_wide_chars(L##str); \
}

#define X10_MAKE_COMPARETO(name, type) \
	x10_int name(type self, type other) { return (self == other) ? 0 : (self < other) ? - 1 : 1; }

#define X10_MAKE_EQUALS(name, type) \
	x10_boolean name(type self, type other) { return (self == other); }

#define X10_MAKE_HASHCODE(name, type) \
x10_int name(type self) \
{ \
	if(sizeof(type) <= sizeof(x10_int)) { \
		union { x10_int i; type u; } m; \
		m.u = self; \
		return m.i; \
	} else { \
		return x10_hashCode((const unsigned char *)&self, sizeof(type)); \
	} \
}

static x10_char numerals[] = {
	T_('0'), T_('1'), T_('2'), T_('3'), T_('4'),
	T_('5'), T_('6'), T_('7'), T_('8'), T_('9'),
	T_('a'), T_('b'), T_('c'), T_('d'), T_('e'), T_('f') };

#define X10_MAKE_TOSTRING(name, type)                                     \
x10_string *name(type self, x10_int radix)                                \
{                                                                         \
	assert(radix >= 2);                                                   \
	assert(radix <= (x10_int)ARRAY_SIZE(numerals));                       \
	x10_char buf[21];                                                     \
	type normalised = self;                                               \
	if (self < 0) {                                                       \
		normalised = -self;                                               \
	}                                                                     \
	x10_char *b;                                                          \
	for (b = &buf[ARRAY_SIZE(buf)]; normalised!=0; normalised /= radix) { \
		*(--b) = numerals[normalised % radix];                            \
	}                                                                     \
	if (self < 0) {                                                       \
		*(--b) = '-';                                                     \
	}                                                                     \
	return x10_string_literal((buf+sizeof(buf)-b)/sizeof(buf[0]), b);     \
}

#define X10_MAKE_PARSE(name, type)                                        \
type name(x10_string *string, x10_int radix)                              \
{                                                                         \
	assert(radix >= 2);                                                   \
	assert(radix <= 36);                                                  \
	type result = 0;                                                      \
	type dradix = (type)radix;                                            \
	for (x10_int i = 0; i < string->len; ++i) {                           \
		x10_char c = string->chars[i];                                    \
		type digit_value;                                                 \
		if (c >= T_('0') && c <= T_('9')) {                               \
			digit_value = (type)(c - T_('0'));                            \
		} else if (c >= T_('a') && c <= T_('z')) {                        \
			digit_value = (type)(c - T_('a'));                            \
		} else if (c >= T_('A') && c <= T_('Z')) {                        \
			digit_value = (type)(c - T_('A'));                            \
		} else {                                                          \
			x10_throw_exception_object(0);                                \
		}                                                                 \
		if (digit_value > dradix)                                         \
			x10_throw_exception_object(0);                                \
		result = result*dradix + digit_value;                             \
	}                                                                     \
	return result;                                                        \
}

#define X10_MAKE_TOSTRING_UNSIGNED(name, type)                            \
x10_string *name(type self, x10_int radix)                                \
{                                                                         \
	assert(radix >= 2);                                                   \
	assert(radix <= (x10_int)ARRAY_SIZE(numerals));                       \
	x10_char buf[21];                                                     \
	type normalised = self;                                               \
	x10_char *b;                                                          \
	for (b = &buf[ARRAY_SIZE(buf)]; normalised!=0; normalised /= radix) { \
		*(--b) = numerals[normalised % radix];                            \
	}                                                                     \
	return x10_string_literal((buf+sizeof(buf)-b)/sizeof(buf[0]), b);     \
}

#define BINOP(name, type_ret, type1, type2, op)  \
	type_ret name(type1 a, type2 b) { return a op b; }

#define BINOP2(name, type_ret, type, op) \
	BINOP(name, type_ret, type, type, op)

#define BINOP3(name, type, op) \
	BINOP(name, type, type, type, op)

#define MAKE_BINOPS(prefix, postfix, type) \
	BINOP3(prefix ## plE ## postfix, type, +) \
	BINOP3(prefix ## miE ## postfix, type, -) \
	BINOP3(prefix ## mlE ## postfix, type, *) \
	BINOP3(prefix ## dvE ## postfix, type, /)

#define MAKE_CMPOPS(prefix, postfix, type) \
	BINOP2(prefix ## eqE ## postfix, x10_boolean, type, ==) \
	BINOP2(prefix ## neE ## postfix, x10_boolean, type, !=) \
	BINOP2(prefix ## ltE ## postfix, x10_boolean, type,  <) \
	BINOP2(prefix ## gtE ## postfix, x10_boolean, type,  >) \
	BINOP2(prefix ## leE ## postfix, x10_boolean, type, <=) \
	BINOP2(prefix ## geE ## postfix, x10_boolean, type, >=)

#define MAKE_INT_BINOPS(prefix, postfix, type) \
	MAKE_BINOPS(prefix, postfix, type) \
	BINOP3(prefix ## rmE ## postfix, type, %) \
	BINOP3(prefix ## anE ## postfix, type, &) \
	BINOP3(prefix ## orE ## postfix, type, |) \
	BINOP3(prefix ## eoE ## postfix, type, ^) \
	BINOP3(prefix ## lsE ## postfix, type, <<) \
	BINOP3(prefix ## rsE ## postfix, type, >>)

/* for byte, short ... -> "<<" and ">>" have int as the second argument */
#define MAKE_INT_BINOPS2(prefix, postfix, type) \
	MAKE_BINOPS(prefix, postfix, type) \
	BINOP3(prefix ## rmE ## postfix, type, %) \
	BINOP3(prefix ## anE ## postfix, type, &) \
	BINOP3(prefix ## orE ## postfix, type, |) \
	BINOP3(prefix ## eoE ## postfix, type, ^) \
	BINOP(prefix  ## lsE ## i, type, type, x10_int, <<) \
	BINOP(prefix  ## rsE ## i, type, type, x10_int, >>)

/* for unsigned types -> operators '&', '|', '^' have 3 forms; ->
	1. Form: Normal operator with posftix1 as the first argument;
	2. Form: Normal operator with postfix2 as the first argument
	3. Form: Inverse operator with postfix2 as the first argument
	Comment: 'v3i' is the prefix for inverse operators
	-> '<<' and '>>' have int as the second argument
*/
#define MAKE_UNSIGNED_BINOPS(prefix, postfix1, postfix2, type) \
	MAKE_INT_BINOPS2(prefix, postfix1, type)

#define UNOP(name, type, op)  \
	type name(type a) { return op a; }

#define MAKE_UNOPS(prefix, postfix, type) \
	UNOP(prefix ## psE ## postfix, type, +) \
	UNOP(prefix ## ngE ## postfix, type, -)

#define MAKE_INT_UNOPS(prefix, postfix, type) \
	MAKE_UNOPS(prefix, postfix, type) \
	UNOP(prefix ## v3utiE ## postfix, type, ~)

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

#endif
