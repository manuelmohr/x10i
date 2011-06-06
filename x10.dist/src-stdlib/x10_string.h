#ifndef X10_STRING_H_
#define X10_STRING_H_

#include "x10.h"

struct x10_string {
	X10_OBJECT_HEADER
	size_t len;
	x10_char buf[1];
};

#define X10_STRING_LEN(s) 	((s)->len)
#define X10_STRING_LEN_BYTES(s) (X10_STRING_LEN(s) * sizeof(x10_char))
#define X10_STRING_BUF(s) 	((s)->buf)
#define X10_STRING_CHAR(s,i) 	X10_STRING_BUF((s))[(i)]

X10_EXTERN x10_string *x10_string_from_wide_chars(const x10_char *);

X10_EXTERN x10_string *x10_string_literal(size_t, x10_char *);

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

// operator+ functions
X10_EXTERN x10_string *_ZN3x104lang6StringplIN3x104lang6StringEEEN3x104lang6StringEPN3x104lang6StringEPN3x104lang6StringE(x10_string *, x10_string *);
X10_EXTERN x10_string *_ZN3x104lang6StringplIxEEN3x104lang6StringEx(x10_string *, x10_long);
X10_EXTERN x10_string *_ZN3x104lang6StringplIyEEN3x104lang6StringEy(x10_string *, x10_ulong);
X10_EXTERN x10_string *_ZN3x104lang6StringplIiEEN3x104lang6StringEi(x10_string *, x10_int);
X10_EXTERN x10_string *_ZN3x104lang6StringplIjEEN3x104lang6StringEj(x10_string *, x10_uint);
X10_EXTERN x10_string *_ZN3x104lang6StringplIsEEN3x104lang6StringEs(x10_string *, x10_short);
X10_EXTERN x10_string *_ZN3x104lang6StringplItEEN3x104lang6StringEt(x10_string *, x10_ushort);
X10_EXTERN x10_string *_ZN3x104lang6StringplIaEEN3x104lang6StringEa(x10_string *, x10_byte);
X10_EXTERN x10_string *_ZN3x104lang6StringplIhEEN3x104lang6StringEh(x10_string *, x10_ubyte);
X10_EXTERN x10_string *_ZN3x104lang6StringplIDiEEN3x104lang6StringEDi(x10_string *, x10_char);
X10_EXTERN x10_string *_ZN3x104lang6StringplIfEEN3x104lang6StringEf(x10_string *, x10_float);
X10_EXTERN x10_string *_ZN3x104lang6StringplIdEEN3x104lang6StringEd(x10_string *, x10_double);
X10_EXTERN x10_string *_ZN3x104lang6StringplIbEEN3x104lang6StringEb(x10_string *, x10_boolean);


#endif // X10_STRING_H_
