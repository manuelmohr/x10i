#ifndef X10_STRING_H_
#define X10_STRING_H_

#include "x10.h"

typedef struct {
	X10_OBJECT_HEADER
	x10_int        len;
	const x10_char chars[];
} x10_string;

x10_string *x10_string_literal(x10_int len, const x10_char *chars);
x10_string *x10_string_from_cstring(const char *string);

x10_string *_ZN3x104lang6StringC1Ev(void);
x10_string *_ZN3x104lang6StringC1EPN3x104lang6StringE(x10_string *str);

// String methods
x10_boolean _ZN3x104lang6String6equalsEPN3x104lang3AnyE(const x10_string *, const x10_string *);
x10_int _ZN3x104lang6String8hashCodeEv(const x10_string *);
x10_boolean _ZN3x104lang6String16equalsIgnoreCaseEPN3x104lang6StringE(const x10_string *, const x10_string *);
x10_int _ZN3x104lang6String6lengthEv(const x10_string *);
x10_string *_ZN3x104lang6String8toStringEv(const x10_string *);
x10_string *_ZN3x104lang6String8typeNameEv(const x10_string *);
x10_char _ZN3x104lang6StringapplyEi(const x10_string *, x10_int);
x10_char _ZN3x104lang6String6charAtEi(const x10_string *, x10_int);
x10_int _ZN3x104lang6String7indexOfEDi(const x10_string *, x10_char);
x10_int _ZN3x104lang6String7indexOfEDii(const x10_string *, x10_char, x10_int);
x10_int _ZN3x104lang6String7indexOfEPN3x104lang6StringE(const x10_string *, const x10_string *);
x10_int _ZN3x104lang6String7indexOfEPN3x104lang6StringEi(const x10_string *, const x10_string *, x10_int);
x10_int _ZN3x104lang6String11lastIndexOfEDi(const x10_string *, x10_char);
x10_int _ZN3x104lang6String11lastIndexOfEDii(const x10_string *, x10_char, x10_int);
x10_int _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringE(const x10_string *, const x10_string *);
x10_int _ZN3x104lang6String11lastIndexOfEPN3x104lang6StringEi(const x10_string *, const x10_string *, x10_int);
x10_string *_ZN3x104lang6String9substringEi(const x10_string *, x10_int);
x10_string *_ZN3x104lang6String9substringEii(const x10_string *, x10_int, x10_int);
x10_boolean _ZN3x104lang6String8endsWithEPN3x104lang6StringE(const x10_string *, const x10_string *);
x10_boolean _ZN3x104lang6String10startsWithEPN3x104lang6StringE(const x10_string *, const x10_string *);
x10_string *_ZN3x104lang6String4trimEv(const x10_string *);
x10_string *_ZN3x104lang6String11toLowerCaseEv(const x10_string *);
x10_string *_ZN3x104lang6String11toUpperCaseEv(const x10_string *);
x10_int _ZN3x104lang6String9compareToEPN3x104lang6StringE(const x10_string *, const x10_string *);
x10_int _ZN3x104lang6String19compareToIgnoreCaseEPN3x104lang6StringE(const x10_string *, const x10_string *);

// operator <(String)
x10_boolean _ZN3x104lang6StringltEPN3x104lang6StringE(const x10_string *, const x10_string *);
// operator <=(String)
x10_boolean _ZN3x104lang6StringleEPN3x104lang6StringE(const x10_string *, const x10_string *);
// operator >(String)
x10_boolean _ZN3x104lang6StringgtEPN3x104lang6StringE(const x10_string *, const x10_string *);
// operator >=(String)
x10_boolean _ZN3x104lang6StringgeEPN3x104lang6StringE(const x10_string *, const x10_string *);
// operator+(String)
x10_string *_ZN3x104lang6StringplEPN3x104lang6StringE(const x10_string *, const x10_string *);
// static operator+(String, String)
x10_string *_ZN3x104lang6StringplEPN3x104lang6StringEPN3x104lang6StringE(const x10_string *, const x10_string *);

#endif
