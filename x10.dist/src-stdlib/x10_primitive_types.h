#ifndef X10_PRIMITIVE_TYPES_H_
#define X10_PRIMITIVE_TYPES_H_

#include "x10_util.h"
#include "util.h"

#define X10_MAKE_TYPENAME(name, type, str) \
x10_string *name(type self) \
{ \
   UNUSED(self); \
   return x10_string_from_wide_chars(L##str); \
}

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
	BINOP3(prefix ## eqE ## postfix, type, ==) \
	BINOP3(prefix ## neE ## postfix, type, !=) \
	BINOP3(prefix ## ltE ## postfix, type,  <) \
	BINOP3(prefix ## gtE ## postfix, type,  >) \
	BINOP3(prefix ## leE ## postfix, type, <=) \
	BINOP3(prefix ## geE ## postfix, type, >=)

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
#define MAKE_U_BINOPS2(prefix, postfix1, postfix2, type) \
	MAKE_INT_BINOPS2(prefix, postfix1, type) \
	BINOP3(prefix ## anE ## postfix2, type, &) \
	BINOP3(prefix ## orE ## postfix2, type, |) \
	BINOP3(prefix ## eoE ## postfix2, type, ^) \
	BINOP3(prefix ## v3i ## anE ## postfix2, type, &) \
	BINOP3(prefix ## v3i ## orE ## postfix2, type, |) \
	BINOP3(prefix ## v3i ## eoE ## postfix2, type, ^) 

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

#endif // X10_PRIMITIVE_TYPES_H_

