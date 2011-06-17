#ifndef X10_STRING_H_
#define X10_STRING_H_

#include "x10.h"

struct x10_string {
	X10_OBJECT_HEADER
	size_t len;
	x10_char buf[1];
};

#define X10_STRING_BUF(s)       ((s)->buf)
#define X10_STRING_CHAR(s,i)    X10_STRING_BUF((s))[(i)]

X10_EXTERN x10_string *x10_string_from_wide_chars(const x10_char *);

X10_EXTERN x10_string *x10_string_literal(size_t, x10_char *);

// constructors
// this(String)
X10_EXTERN x10_string *_ZN3x104lang6StringC1EPN3x104lang6StringE(x10_string *);
// this()
X10_EXTERN x10_string *_ZN3x104lang6StringC1Ev();

// String methods
X10_EXTERN x10_boolean _ZN3x104lang6String6equalsEPN3x104lang3AnyE (x10_string *, x10_any *);
X10_EXTERN x10_int _ZN3x104lang6String6lengthEv(x10_string *);
X10_EXTERN x10_string *_ZN3x104lang6String8toStringEv(x10_string *);
X10_EXTERN x10_string *_ZN3x104lang6String8typeNameEv(x10_string *);
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
X10_EXTERN x10_int _ZN3x104lang6String9compareToEPN3x104lang6StringE(x10_string *, x10_string *);

// operator+(String)
X10_EXTERN x10_string *_ZN3x104lang6StringplEPN3x104lang6StringE(x10_string *, x10_string *);
// static operator+(String, String)
X10_EXTERN x10_string *_ZN3x104lang6StringplEPN3x104lang6StringEPN3x104lang6StringE(x10_string *, x10_string *);


#endif // X10_STRING_H_

