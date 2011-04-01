#include "x10.h"
#include "x10_string.h"

void _ZN9SimpleLib5printEx(x10_long v)
{
	wprintf(L"%"PRIi64"\n", v);
}
void _ZN9SimpleLib5printEy(x10_ulong v)
{
	wprintf(L"%"PRIu64"\n", v);
}
void _ZN9SimpleLib5printEi(x10_int v)
{
	wprintf(L"%"PRIi32"\n", v);
}
void _ZN9SimpleLib5printEj(x10_uint v)
{
	wprintf(L"%"PRIu32"\n", v);
}
void _ZN9SimpleLib5printEs(x10_short v)
{
	wprintf(L"%"PRIi16"\n", v);
}
void _ZN9SimpleLib5printEt(x10_ushort v)
{
	wprintf(L"%"PRIu16"\n", v);
}
void _ZN9SimpleLib5printEa(x10_byte v)
{
	wprintf(L"%"PRIi8"\n", v);
}
void _ZN9SimpleLib5printEh(x10_ubyte v)
{
	wprintf(L"%"PRIu8"\n", v);
}
void _ZN9SimpleLib5printEDi(x10_char v)
{
	wprintf(L"%lc\n", v);
}
void _ZN9SimpleLib5printEf(x10_float v)
{
	wprintf(L"%f\n", v);
}
void _ZN9SimpleLib5printEd(x10_double v)
{
	wprintf(L"%f\n", v);
}
void _ZN9SimpleLib5printEb(x10_boolean v)
{
	wprintf(L"%ls\n", v ? L"true" : L"false");
}

void _ZN9SimpleLib5printEPN3x104lang6StringE(x10_string *str)
{
	wprintf(L"%ls\n", str->buf);
}

