#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

struct x10_lang_String {
	unsigned length;
	const unsigned* content;
};

typedef struct x10_lang_String *String;

String _Z18x10_string_literalEJPN6StringEP6JArrayIjE(unsigned length, const unsigned *wchars) {
	// TODO memory management/garbage collection
	// FIXME assumes that buf is const
	String str = malloc(sizeof(struct x10_lang_String));
	assert (str != NULL); // TODO out of memory exception?!
	str->length = length;
	str->content = wchars;
	return str;
}

void _ZN7Printer7printlnEJvPN3AnyE(void* owner_obj, void *any_ptr) {
	// FIXME Any is not String in general!
	String str = (String) any_ptr;
	for (int i=0; i < str->length; i++) {
		putchar(str->content[i]);
	}
	putchar('\n');
}
