#include "x10.h"
#include "x10_string.h"

/* We currently do not have header files for these */
X10_EXTERN x10_string *_ZN3x104lang4Long8toStringEv   (x10_long);
X10_EXTERN x10_string *_ZN3x104lang5ULong8toStringEv  (x10_ulong);
X10_EXTERN x10_string *_ZN3x104lang3Int8toStringEv    (x10_int);
X10_EXTERN x10_string *_ZN3x104lang4UInt8toStringEv   (x10_uint);
X10_EXTERN x10_string *_ZN3x104lang5Short8toStringEv  (x10_short);
X10_EXTERN x10_string *_ZN3x104lang6UShort8toStringEv (x10_ushort);
X10_EXTERN x10_string *_ZN3x104lang4Byte8toStringEv   (x10_byte);
X10_EXTERN x10_string *_ZN3x104lang5UByte8toStringEv  (x10_ubyte);
X10_EXTERN x10_string *_ZN3x104lang4Char8toStringEv   (x10_char);
X10_EXTERN x10_string *_ZN3x104lang5Float8toStringEv  (x10_float);
X10_EXTERN x10_string *_ZN3x104lang6Double8toStringEv (x10_double);
X10_EXTERN x10_string *_ZN3x104lang7Boolean8toStringEv(x10_boolean);

void _ZN9SimpleLib5printEx(x10_long v)
{
	x10_string *s = _ZN3x104lang4Long8toStringEv(v);
	wprintf(L"%ls\n", X10_STRING_BUF(s));
}

void _ZN9SimpleLib5printEy(x10_ulong v)
{
	x10_string *s = _ZN3x104lang5ULong8toStringEv(v);
	wprintf(L"%ls\n", X10_STRING_BUF(s));
}

void _ZN9SimpleLib5printEi(x10_int v)
{
	x10_string *s = _ZN3x104lang3Int8toStringEv(v);
	wprintf(L"%ls\n", X10_STRING_BUF(s));
}

void _ZN9SimpleLib5printEj(x10_uint v)
{
	x10_string *s = _ZN3x104lang4UInt8toStringEv(v);
	wprintf(L"%ls\n", X10_STRING_BUF(s));
}

void _ZN9SimpleLib5printEs(x10_short v)
{
	x10_string *s = _ZN3x104lang5Short8toStringEv(v);
	wprintf(L"%ls\n", X10_STRING_BUF(s));
}

void _ZN9SimpleLib5printEt(x10_ushort v)
{
	x10_string *s = _ZN3x104lang6UShort8toStringEv(v);
	wprintf(L"%ls\n", X10_STRING_BUF(s));
}

void _ZN9SimpleLib5printEa(x10_byte v)
{
	x10_string *s = _ZN3x104lang4Byte8toStringEv(v);
	wprintf(L"%ls\n", X10_STRING_BUF(s));
}

void _ZN9SimpleLib5printEh(x10_ubyte v)
{
	x10_string *s = _ZN3x104lang5UByte8toStringEv(v);
	wprintf(L"%ls\n", X10_STRING_BUF(s));
}

void _ZN9SimpleLib5printEDi(x10_char v)
{
	x10_string *s = _ZN3x104lang4Char8toStringEv(v);
	wprintf(L"%ls\n", X10_STRING_BUF(s));
}

void _ZN9SimpleLib5printEf(x10_float v)
{
	x10_string *s = _ZN3x104lang5Float8toStringEv(v);
	wprintf(L"%ls\n", X10_STRING_BUF(s));
}

void _ZN9SimpleLib5printEd(x10_double v)
{
	x10_string *s = _ZN3x104lang6Double8toStringEv(v);
	wprintf(L"%ls\n", X10_STRING_BUF(s));
}

void _ZN9SimpleLib5printEb(x10_boolean v)
{
	x10_string *s = _ZN3x104lang7Boolean8toStringEv(v);
	wprintf(L"%ls\n", X10_STRING_BUF(s));
}

void _ZN9SimpleLib5printEPN3x104lang6StringE(x10_string *str)
{
	wprintf(L"%ls\n", X10_STRING_BUF(str));
}

