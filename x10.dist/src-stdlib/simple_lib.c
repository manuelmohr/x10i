#include "x10.h"
#include "x10_string.h"

void _ZN9SimpleLib5printEx(x10_long v)
{
	x10_string *s = _ZN3x104lang4Long8toStringEv(v);
	wprintf(T_("%ls\n"), x10_string_buf(s));
}

void _ZN9SimpleLib5printEy(x10_ulong v)
{
	x10_string *s = _ZN3x104lang5ULong8toStringEv(v);
	wprintf(T_("%ls\n"), x10_string_buf(s));
}

void _ZN9SimpleLib5printEi(x10_int v)
{
	x10_string *s = _ZN3x104lang3Int8toStringEv(v);
	wprintf(T_("%ls\n"), x10_string_buf(s));
}

void _ZN9SimpleLib5printEj(x10_uint v)
{
	x10_string *s = _ZN3x104lang4UInt8toStringEv(v);
	wprintf(T_("%ls\n"), x10_string_buf(s));
}

void _ZN9SimpleLib5printEs(x10_short v)
{
	x10_string *s = _ZN3x104lang5Short8toStringEv(v);
	wprintf(T_("%ls\n"), x10_string_buf(s));
}

void _ZN9SimpleLib5printEt(x10_ushort v)
{
	x10_string *s = _ZN3x104lang6UShort8toStringEv(v);
	wprintf(T_("%ls\n"), x10_string_buf(s));
}

void _ZN9SimpleLib5printEa(x10_byte v)
{
	x10_string *s = _ZN3x104lang4Byte8toStringEv(v);
	wprintf(T_("%ls\n"), x10_string_buf(s));
}

void _ZN9SimpleLib5printEh(x10_ubyte v)
{
	x10_string *s = _ZN3x104lang5UByte8toStringEv(v);
	wprintf(T_("%ls\n"), x10_string_buf(s));
}

void _ZN9SimpleLib5printEDi(x10_char v)
{
	x10_string *s = _ZN3x104lang4Char8toStringEv(v);
	wprintf(T_("%ls\n"), x10_string_buf(s));
}

void _ZN9SimpleLib5printEf(x10_float v)
{
	x10_string *s = _ZN3x104lang5Float8toStringEv(v);
	wprintf(T_("%ls\n"), x10_string_buf(s));
}

void _ZN9SimpleLib5printEd(x10_double v)
{
	x10_string *s = _ZN3x104lang6Double8toStringEv(v);
	wprintf(T_("%ls\n"), x10_string_buf(s));
}

void _ZN9SimpleLib5printEb(x10_boolean v)
{
	x10_string *s = _ZN3x104lang7Boolean8toStringEv(v);
	wprintf(T_("%ls\n"), x10_string_buf(s));
}

void _ZN9SimpleLib5printEPN3x104lang6StringE(x10_string *str)
{
	wprintf(T_("%ls\n"), x10_string_buf(str));
}

