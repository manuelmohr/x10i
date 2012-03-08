#include <stdio.h>
#include "x10.h"
#include "x10_string.h"

void _ZN9SimpleLib5printEx(x10_long v)
{
	printf("%"PRIx10_long"\n", v);
}

void _ZN9SimpleLib5printEy(x10_ulong v)
{
	printf("%"PRIx10_ulong"\n", v);
}

void _ZN9SimpleLib5printEi(x10_int v)
{
	printf("%"PRIx10_int"\n", v);
}

void _ZN9SimpleLib5printEj(x10_uint v)
{
	printf("%"PRIx10_uint"\n", v);
}

void _ZN9SimpleLib5printEs(x10_short v)
{
	printf("%"PRIx10_short"\n", v);
}

void _ZN9SimpleLib5printEt(x10_ushort v)
{
	printf("%"PRIx10_ushort"\n", v);
}

void _ZN9SimpleLib5printEa(x10_byte v)
{
	printf("%"PRIx10_byte"\n", v);
}

void _ZN9SimpleLib5printEh(x10_ubyte v)
{
	printf("%"PRIx10_ubyte"\n", v);
}

void _ZN9SimpleLib5printEc(x10_char v)
{
	printf("%"PRIx10_char"\n", v);
}

void _ZN9SimpleLib5printEf(x10_float v)
{
	printf("%"PRIx10_float"\n", v);
}

void _ZN9SimpleLib5printEd(x10_double v)
{
	printf("%"PRIx10_double"\n", v);
}

void _ZN9SimpleLib5printEb(x10_boolean v)
{
	printf("%s\n", v != X10_FALSE ? "true" : "false");
}

void _ZN9SimpleLib5printEPN3x104lang6StringE(x10_string *str)
{
	x10_write_block(str->chars, str->len);
	putchar('\n');
}
