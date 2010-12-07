#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define BINOP(name, type, op)  \
	type name(type a, type b) { return a op b; }

#define MAKE_BINOPS(prefix, postfix, type) \
	BINOP(prefix ## plEJ ## postfix, type, +) \
	BINOP(prefix ## miEJ ## postfix, type, -) \
	BINOP(prefix ## mlEJ ## postfix, type, *) \
	BINOP(prefix ## dvEJ ## postfix, type, /)

#define MAKE_CMPOPS(prefix, postfix, type) \
	BINOP(prefix ## eqEJ ## postfix, type, ==) \
	BINOP(prefix ## neEJ ## postfix, type, !=) \
	BINOP(prefix ## ltEJ ## postfix, type, <) \
	BINOP(prefix ## gtEJ ## postfix, type, >) \
	BINOP(prefix ## leEJ ## postfix, type, <=) \
	BINOP(prefix ## geEJ ## postfix, type, >=)

#define MAKE_INT_BINOPS(prefix, postfix, type) \
	MAKE_BINOPS(prefix, postfix, type) \
	BINOP(prefix ## rmEJ ## postfix, type, %) \
	BINOP(prefix ## anEJ ## postfix, type, &) \
	BINOP(prefix ## orEJ ## postfix, type, |) \
	BINOP(prefix ## eoEJ ## postfix, type, ^) \
	BINOP(prefix ## lsEJ ## postfix, type, <<) \
	BINOP(prefix ## rsEJ ## postfix, type, >>)

#define UNOP(name, type, op)  \
	type name(type a) { return op a; }

#define MAKE_UNOPS(prefix, postfix, type) \
	UNOP(prefix ## plEJ ## postfix, type, +) \
	UNOP(prefix ## miEJ ## postfix, type, -)

#define MAKE_INT_UNOPS(prefix, postfix, type) \
	MAKE_UNOPS(prefix, postfix, type) \
	UNOP(prefix ## coEJ ## postfix, type, ~)

/* TODO: name mangling not correct yet, it should have the target type
 * behind the "cv", but our X10 versions mangles it in this incorrect
 * version at the moment */
#define MAKE_CONF(prefix, suffix, fromtype, totype) \
	totype prefix##cvEJ##suffix (fromtype a) { return (totype) a; }

#define MAKE_CONFS(prefix, fromtype_mangled, fromtype) \
	MAKE_CONF(prefix, fromtype_mangled##x, int64_t,  fromtype) \
	MAKE_CONF(prefix, fromtype_mangled##i, int32_t,  fromtype) \
	MAKE_CONF(prefix, fromtype_mangled##s, int16_t,  fromtype) \
	MAKE_CONF(prefix, fromtype_mangled##a, int8_t,   fromtype) \
	MAKE_CONF(prefix, fromtype_mangled##f, float,    fromtype) \
	MAKE_CONF(prefix, fromtype_mangled##d, double,   fromtype)

MAKE_INT_BINOPS(_ZN4Long, xxx, int64_t)
MAKE_CMPOPS(_ZN4Long, bxx, int64_t)
MAKE_INT_UNOPS(_ZN4Long, xx, int64_t)
int64_t _ZN4Longv3rbsEJxxx(int64_t a, int64_t b)
{
	return (int64_t) ((uint64_t) a >> (uint64_t) b);
}
MAKE_CONFS(_ZN4Long, x, int64_t)

MAKE_INT_BINOPS(_ZN5ULong, yyy, uint64_t)
MAKE_CMPOPS(_ZN5ULong, byy, uint64_t)
MAKE_INT_UNOPS(_ZN5ULong, yy, uint64_t)
MAKE_CONFS(_ZN5ULong, y, uint64_t)

MAKE_INT_BINOPS(_ZN3Int, iii, int32_t)
MAKE_CMPOPS(_ZN3Int, bii, int32_t)
MAKE_INT_UNOPS(_ZN3Int, ii, int32_t)
int32_t _ZN3Intv3rbsEJiii(int32_t a, int32_t b)
{
	return (int32_t) ((uint32_t) a >> (uint32_t) b);
}
MAKE_CONFS(_ZN3Int, i, int32_t)

MAKE_INT_BINOPS(_ZN5Short, sss, int16_t)
MAKE_CMPOPS(_ZN5Short, bss, int16_t)
MAKE_INT_UNOPS(_ZN5Short, ss, int16_t)
int16_t _ZN5Shortv3rbsEJsss(int16_t a, int16_t b)
{
	return (int16_t) ((uint16_t) a >> (uint16_t) b);
}
MAKE_CONFS(_ZN5Short, s, int16_t)

MAKE_INT_BINOPS(_ZN4Byte, aaa, int8_t)
MAKE_CMPOPS(_ZN4Byte, baa, int8_t)
MAKE_INT_UNOPS(_ZN4Byte, aa, int8_t)
int8_t _ZN4Bytev3rbsEJaaa(int8_t a, int8_t b)
{
	return (int8_t) ((uint8_t) a >> (uint8_t) b);
}
MAKE_CONFS(_ZN4Byte, a, int8_t)

MAKE_BINOPS(_ZN5Float, fff, float)
MAKE_CMPOPS(_ZN5Float, bff, float)
MAKE_UNOPS(_ZN5Float, ff, float)
float _ZN5FloatrmEJfff(float a, float b)
{
	return fmodf(a, b);
}
MAKE_CONFS(_ZN5Float, f, float)

MAKE_BINOPS(_ZN6Double, ddd, double)
MAKE_CMPOPS(_ZN6Double, bdd, double)
MAKE_UNOPS(_ZN6Double, dd, double)
double _ZN6DoublermEJddd(double a, double b)
{
	return fmod(a, b);
}
MAKE_CONFS(_ZN6Double, d, double)

/* Booleans */
UNOP(_ZN7BooleanntEJbb, bool, !)
BINOP(_ZN7BooleananEJbbb, bool, &)
BINOP(_ZN7BooleanorEJbbb, bool, |)
BINOP(_ZN7BooleaneoEJbbb, bool, ^)
