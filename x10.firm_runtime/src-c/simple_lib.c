#include <stdio.h>
#include "types.h"
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
	/* use Float.toString to match x10cpp based output */
	extern x10_string *_ZN3x104lang5Float8toStringEv(x10_float v);
	x10_string *str = _ZN3x104lang5Float8toStringEv(v);
	fwrite(str->chars, str->len, 1, stdout);
	putchar('\n');
}

void _ZN9SimpleLib5printEd(x10_double v)
{
	/* use Double.toString to match x10cpp based output */
	extern x10_string *_ZN3x104lang6Double8toStringEv(x10_double v);
	x10_string *str = _ZN3x104lang6Double8toStringEv(v);
	fwrite(str->chars, str->len, 1, stdout);
	putchar('\n');
}

void _ZN9SimpleLib5printEb(x10_boolean v)
{
	printf("%s\n", v ? "true" : "false");
}

void _ZN9SimpleLib5printEPN3x104lang6StringE(x10_string *str)
{
	fwrite(str->chars, str->len, 1, stdout);
	putchar('\n');
}
