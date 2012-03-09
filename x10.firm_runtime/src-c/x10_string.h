#ifndef X10_STRING_H_
#define X10_STRING_H_

#include "x10.h"
#include "x10_object.h"

typedef struct {
	x10_object      base;
	x10_int         len;
	const x10_char *chars;
} x10_string;

/** Given a len and a constant character array, create string object.
 * The chars are not copied, the caller guarantees that the data stays valid as
 * long as the string object lives */
x10_string *x10_string_from_literal(x10_int len, const x10_char *chars);

/** Given a normal null-terminated character array (a normal string in C)
 * create a new string object. The data in the string is copied, so the
 * caller can free it safely even if the string object still lives. */
x10_string *x10_string_from_cstring(const char *string);

x10_string *x10_string_from_cstring_len(size_t len, const char *string);

/** Create an x10-string object from a C string-literal.
 * Warning: Passing in any other values than a C string literal will break,
 * (const char* gives no compile error unfortunately) */
#define X10_STRING_FROM_CLITERAL(literal)  x10_string_from_literal((x10_int)sizeof(literal)-1, literal)

#endif
