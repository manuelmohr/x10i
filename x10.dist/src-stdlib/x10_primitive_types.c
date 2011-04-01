#include "x10_primitive_types.h"

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

MAKE_INT_BINOPS(_ZN3x104lang4Long, x, x10_long)
MAKE_CMPOPS(_ZN3x104lang4Long, x, x10_long)
MAKE_INT_UNOPS(_ZN3x104lang4Long, v, x10_long)
x10_long _ZN3x104lang4Longv3rbsEx(x10_long a, x10_long b)
{
	return (x10_long) ((x10_ulong) a >> (x10_ulong) b);
}
MAKE_CONFS(_ZN3x104lang4Long, x10_long)

MAKE_INT_BINOPS(_ZN3x104lang5ULong, y, x10_ulong)
MAKE_CMPOPS(_ZN3x104lang5ULong, y, x10_ulong)
MAKE_INT_UNOPS(_ZN3x104lang5ULong, v, x10_ulong)
MAKE_CONFS(_ZN3x104lang5ULong, x10_ulong)

MAKE_INT_BINOPS(_ZN3x104lang3Int, i, x10_int)
MAKE_CMPOPS(_ZN3x104lang3Int, i, x10_int)
MAKE_INT_UNOPS(_ZN3x104lang3Int, v, x10_int)
x10_int _ZN3x104lang3Intv3rbsEi(x10_int a, x10_int b)
{
	return (x10_int) ((x10_uint) a >> (x10_uint) b);
}
MAKE_CONFS(_ZN3x104lang3Int, x10_int)

MAKE_INT_BINOPS(_ZN3x104lang5Short, s, x10_short)
MAKE_CMPOPS(_ZN3x104lang5Short, s, x10_short)
MAKE_INT_UNOPS(_ZN3x104lang5Short, v, x10_short)
x10_short _ZN3x104lang5Shortv3rbsEs(x10_short a, x10_short b)
{
	return (x10_short) ((x10_ushort) a >> (x10_ushort) b);
}
MAKE_CONFS(_ZN3x104lang5Short, x10_short)

MAKE_INT_BINOPS(_ZN3x104lang4Byte, a, x10_byte)
MAKE_CMPOPS(_ZN3x104lang4Byte, a, x10_byte)
MAKE_INT_UNOPS(_ZN3x104lang4Byte, v, x10_byte)
x10_byte _ZN3x104lang4Bytev3rbsEa(x10_byte a, x10_byte b)
{
	return (x10_byte) ((x10_ubyte) a >> (x10_ubyte) b);
}
MAKE_CONFS(_ZN3x104lang4Byte, x10_byte)

MAKE_BINOPS(_ZN3x104lang5Float, f, x10_float)
MAKE_CMPOPS(_ZN3x104lang5Float, f, x10_float)
MAKE_UNOPS(_ZN3x104lang5Float, v, x10_float)
float _ZN3x104lang5FloatrmEf(x10_float a, x10_float b)
{
	return fmodf(a, b);
}
MAKE_CONFS(_ZN3x104lang5Float, x10_float)

MAKE_BINOPS(_ZN3x104lang6Double, d, x10_double)
MAKE_CMPOPS(_ZN3x104lang6Double, d, x10_double)
MAKE_UNOPS(_ZN3x104lang6Double, v, x10_double)
double _ZN3x104lang6DoublermEd(x10_double a, x10_double b)
{
	return fmod(a, b);
}
MAKE_CONFS(_ZN3x104lang6Double, x10_double)

/* Booleans */
UNOP(_ZN3x104lang7BooleanntEv, x10_boolean, !)
BINOP(_ZN3x104lang7BooleananEb, x10_boolean, &)
BINOP(_ZN3x104lang7BooleanorEb, x10_boolean, |)
BINOP(_ZN3x104lang7BooleaneoEb, x10_boolean, ^)
