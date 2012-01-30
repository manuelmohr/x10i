#ifndef X10_STRING_H_
#define X10_STRING_H_

#include <wchar.h>
#include <wctype.h>

#include "x10.h"


typedef struct {
	X10_OBJECT_HEADER
	size_t len;
	x10_char buf[1];
} x10_string;

static inline x10_char *x10_string_buf(x10_string *s) {
	return s->buf;
}

static inline x10_int x10_string_len(const x10_string *s) {
	return s->len;
}


X10_EXTERN x10_string *x10_string_from_wide_chars(const x10_char *);
X10_EXTERN x10_string *x10_string_literal(size_t, x10_char *);

X10_EXTERN x10_string *_ZN3x104lang6StringC1Ev(void);
X10_EXTERN x10_string *_ZN3x104lang6StringC1EPN3x104lang6StringE(
		x10_string *str);

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

// String methods
X10_EXTERN x10_boolean _ZN3x104lang6String6equalsEPN3x104lang3AnyE(x10_string *, x10_any *);
X10_EXTERN x10_int _ZN3x104lang6String8hashCodeEv(x10_string *);
X10_EXTERN x10_boolean _ZN3x104lang6String16equalsIgnoreCaseEPN3x104lang6StringE(x10_string *, x10_string *);
X10_EXTERN x10_int _ZN3x104lang6String6lengthEv(x10_string *);
X10_EXTERN x10_string *_ZN3x104lang6String8toStringEv(x10_string *);
X10_EXTERN x10_string *_ZN3x104lang6String8typeNameEv(x10_string *);
X10_EXTERN x10_char _ZN3x104lang6StringapplyEi(x10_string *, x10_int);
X10_EXTERN x10_char _ZN3x104lang6String6charAtEi(x10_string *, x10_int);
X10_EXTERN x10_int _ZN3x104lang6String7indexOfEDi(x10_string *, x10_char);
X10_EXTERN x10_int _ZN3x104lang6String7indexOfEDii(x10_string *, x10_char, x10_int);
X10_EXTERN x10_int _ZN3x104lang6String7indexOfEPN3x104lang6StringE(x10_string *, x10_string *);
X10_EXTERN x10_int _ZN3x104lang6String7indexOfEPN3x104lang6StringEi(x10_string *, x10_string *, x10_int);
X10_EXTERN x10_int _ZN3x104lang6String11lastIndexOfEDi(x10_string *, x10_char);
X10_EXTERN x10_int _ZN3x104lang6String11lastIndexOfEDii(x10_string *, x10_char, x10_int);
X10_EXTERN x10_int _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringE(x10_string *, x10_string *);
X10_EXTERN x10_int _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringEi(x10_string *, x10_string *, x10_int);
X10_EXTERN x10_string *_ZN3x104lang6String9substringEi(x10_string *, x10_int);
X10_EXTERN x10_string *_ZN3x104lang6String9substringEii(x10_string *, x10_int, x10_int);
X10_EXTERN x10_boolean _ZN3x104lang6String8endsWithEPN3x104lang6StringE(x10_string *, x10_string *);
X10_EXTERN x10_boolean _ZN3x104lang6String10startsWithEPN3x104lang6StringE(x10_string *, x10_string *);
X10_EXTERN x10_string *_ZN3x104lang6String4trimEv(x10_string *);
X10_EXTERN x10_string *_ZN3x104lang6String11toLowerCaseEv(x10_string *);
X10_EXTERN x10_string *_ZN3x104lang6String11toUpperCaseEv(x10_string *);
X10_EXTERN x10_int _ZN3x104lang6String9compareToEPN3x104lang6StringE(x10_string *, x10_string *);
X10_EXTERN x10_int _ZN3x104lang6String19compareToIgnoreCaseEPN3x104lang6StringE(x10_string *, x10_string *);

// operator <(String)
X10_EXTERN x10_boolean _ZN3x104lang6StringltEPN3x104lang6StringE(x10_string *, x10_string *);
// operator <=(String)
X10_EXTERN x10_boolean _ZN3x104lang6StringleEPN3x104lang6StringE(x10_string *, x10_string *);
// operator >(String)
X10_EXTERN x10_boolean _ZN3x104lang6StringgtEPN3x104lang6StringE(x10_string *, x10_string *);
// operator >=(String)
X10_EXTERN x10_boolean _ZN3x104lang6StringgeEPN3x104lang6StringE(x10_string *, x10_string *);
// operator+(String)
X10_EXTERN x10_string *_ZN3x104lang6StringplEPN3x104lang6StringE(x10_string *, x10_string *);
// static operator+(String, String)
X10_EXTERN x10_string *_ZN3x104lang6StringplEPN3x104lang6StringEPN3x104lang6StringE(x10_string *, x10_string *);

#endif // X10_STRING_H_
