#include <stdint.h>
#include <stdbool.h>
#include <math.h>

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
	totype prefix##cv##suffix##E (fromtype a) { return (totype) a; }

#define MAKE_CONFS(prefix, fromtype) \
	MAKE_CONF(prefix, x, int64_t,  fromtype) \
	MAKE_CONF(prefix, i, int32_t,  fromtype) \
	MAKE_CONF(prefix, s, int16_t,  fromtype) \
	MAKE_CONF(prefix, a, int8_t,   fromtype) \
	MAKE_CONF(prefix, f, float,    fromtype) \
	MAKE_CONF(prefix, d, double,   fromtype)

MAKE_INT_BINOPS(_ZN3x104lang4Long, xx, int64_t)
MAKE_CMPOPS(_ZN3x104lang4Long, xx, int64_t)
MAKE_INT_UNOPS(_ZN3x104lang4Long, x, int64_t)
int64_t _ZN3x104lang4Longv3rbsExx(int64_t a, int64_t b)
{
	return (int64_t) ((uint64_t) a >> (uint64_t) b);
}
MAKE_CONFS(_ZN3x104lang4Long, int64_t)

MAKE_INT_BINOPS(_ZN3x104lang5ULong, yy, uint64_t)
MAKE_CMPOPS(_ZN3x104lang5ULong, yy, uint64_t)
MAKE_INT_UNOPS(_ZN3x104lang5ULong, y, uint64_t)
MAKE_CONFS(_ZN3x104lang5ULong, uint64_t)

MAKE_INT_BINOPS(_ZN3x104lang3Int, ii, int32_t)
MAKE_CMPOPS(_ZN3x104lang3Int, ii, int32_t)
MAKE_INT_UNOPS(_ZN3x104lang3Int, i, int32_t)
int32_t _ZN3x104lang3Intv3rbsEii(int32_t a, int32_t b)
{
	return (int32_t) ((uint32_t) a >> (uint32_t) b);
}
MAKE_CONFS(_ZN3x104lang3Int, int32_t)

MAKE_INT_BINOPS(_ZN3x104lang5Short, ss, int16_t)
MAKE_CMPOPS(_ZN3x104lang5Short, ss, int16_t)
MAKE_INT_UNOPS(_ZN3x104lang5Short, s, int16_t)
int16_t _ZN3x104lang5Shortv3rbsEss(int16_t a, int16_t b)
{
	return (int16_t) ((uint16_t) a >> (uint16_t) b);
}
MAKE_CONFS(_ZN3x104lang5Short, int16_t)

MAKE_INT_BINOPS(_ZN3x104lang4Byte, aa, int8_t)
MAKE_CMPOPS(_ZN3x104lang4Byte, aa, int8_t)
MAKE_INT_UNOPS(_ZN3x104lang4Byte, a, int8_t)
int8_t _ZN3x104lang4Bytev3rbsEaa(int8_t a, int8_t b)
{
	return (int8_t) ((uint8_t) a >> (uint8_t) b);
}
MAKE_CONFS(_ZN3x104lang4Byte, int8_t)

MAKE_BINOPS(_ZN3x104lang5Float, ff, float)
MAKE_CMPOPS(_ZN3x104lang5Float, ff, float)
MAKE_UNOPS(_ZN3x104lang5Float, f, float)
float _ZN3x104lang5FloatrmEff(float a, float b)
{
	return fmodf(a, b);
}
MAKE_CONFS(_ZN3x104lang5Float, float)

MAKE_BINOPS(_ZN3x104lang6Double, dd, double)
MAKE_CMPOPS(_ZN3x104lang6Double, dd, double)
MAKE_UNOPS(_ZN3x104lang6Double, d, double)
double _ZN3x104lang6DoublermEdd(double a, double b)
{
	return fmod(a, b);
}
MAKE_CONFS(_ZN3x104lang6Double, double)

/* Booleans */
UNOP(_ZN3x104lang7BooleanntEb, bool, !)
BINOP(_ZN3x104lang7BooleananEbb, bool, &)
BINOP(_ZN3x104lang7BooleanorEbb, bool, |)
BINOP(_ZN3x104lang7BooleaneoEbb, bool, ^)
