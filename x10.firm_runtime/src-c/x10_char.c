#include <ctype.h>
#include "x10.h"
#include "x10_string.h"

x10_string *_ZN3x104lang4Char8toStringEv(x10_char self)
{
	return x10_string_from_cstring_len(1, &self);
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
	return false;
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

x10_boolean _ZN3x104lang4Char11isSpaceCharEv(x10_char self)
{
	return self == ' ';
}

x10_boolean _ZN3x104lang4Char12isWhitespaceEv(x10_char self)
{
	return isspace(self);
}

x10_boolean _ZN3x104lang4Char12isISOControlEv(x10_char self)
{
	return iscntrl(self);
}

x10_char _ZN3x104lang4Char11toLowerCaseEv(x10_char self)
{
	return (x10_char)tolower((unsigned char)self);
}

x10_char _ZN3x104lang4Char11toUpperCaseEv(x10_char self)
{
	return (x10_char)toupper((unsigned char)self);
}

x10_char _ZN3x104lang4Char11toTitleCaseEv(x10_char self)
{
	X10_UNIMPLEMENTED();
	return self;
}

x10_int _ZN3x104lang4Char3ordEv(x10_char self)
{
	return (unsigned char)self;
}
