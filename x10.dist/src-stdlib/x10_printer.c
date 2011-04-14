#include "x10_printer.h"
#include "x10_string.h"

#include <wchar.h>

void _ZN3x102io7Printer7printlnEPN3x104lang3AnyE(
	x10_printer *printer, x10_any *any)
{
	switch (X10_TYPE(any)) {
	case T_STRING:
		fwprintf(printer->target, L"%ls\n",
		         X10_STRING_BUF(((x10_string *) any)));
		break;
	
	case T_OBJECT:
	default:
		break;
	}
}
