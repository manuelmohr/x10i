#include <ctype.h>
#include "x10.h"
#include "x10_primitive_types.h"
#include "x10_string.h"

X10_MAKE_COMPARETO(_ZN3x104lang4Char9compareToEDi, x10_char)
X10_MAKE_HASHCODE(_ZN3x104lang4Char8hashCodeEv, x10_char)
X10_MAKE_EQUALS(_ZN3x104lang4Char6equalsEDi, x10_char)

MAKE_INT_BINOPS(_ZN3x104lang4Char, Di, x10_char)
MAKE_CMPOPS(_ZN3x104lang4Char, Di, x10_char)
MAKE_INT_UNOPS(_ZN3x104lang4Char, v, x10_char)
x10_char _ZN3x104lang4Charv3rbsEDi(x10_char a, x10_char b)
{
	return (x10_char) ((x10_char) a >> (x10_char) b);
}
MAKE_CONFS(_ZN3x104lang4Char, x10_char)

x10_string *_ZN3x104lang4Char8toStringEv(x10_char self)
{
	return x10_string_literal(1, &self);
}

x10_boolean _ZN3x104lang4Char11isLowerCaseEv(x10_char self)
{
	return islower(self);
}

x10_boolean _ZN3x104lang4Char11isUpperCaseEv(x10_char self)
{
	return isupper(self);
}

x10_boolean _ZN3x104lang4Char11isTitleCaseEv(x10_char self)
{
	X10_UNUSED(self);
	X10_UNIMPLEMENTED();
	return X10_FALSE;
}

x10_boolean _ZN3x104lang4Char7isDigitEv(x10_char self)
{
	return isdigit(self);
}

x10_boolean _ZN3x104lang4Char8isLetterEv(x10_char self)
{
	return isalpha(self);
}

x10_boolean _ZN3x104lang4Char15isLetterOrDigitEv(x10_char self)
{
	return isalnum(self);
}

x10_boolean _ZN3x104lang4Char12isWhitespaceEv(x10_char self)
{
	return isspace(self);
}

x10_boolean _ZN3x104lang4Char11isSpaceCharEv(x10_char self)
{
	X10_UNUSED(self);
	X10_UNIMPLEMENTED();
	return X10_FALSE;
}

x10_boolean _ZN3x104lang4Char12isISOControlEv(x10_char self)
{
	return iscntrl(self);
}

x10_char _ZN3x104lang4Char11toLowerCaseEv(x10_char self)
{
	return (x10_char)tolower(self);
}

x10_char _ZN3x104lang4Char11toUpperCaseEv(x10_char self)
{
	return (x10_char)toupper(self);
}

x10_char _ZN3x104lang4Char11toTitleCaseEv(x10_char self)
{
	return _ZN3x104lang4Char11toUpperCaseEv(self);
}

x10_int _ZN3x104lang4Char3ordEv(x10_char self)
{
	return (x10_int)self;
}
