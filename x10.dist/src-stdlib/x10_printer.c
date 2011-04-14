#include "x10_printer.h"
#include "x10_string.h"

#include <wchar.h>

void _ZN3x102io7Printer7printlnEPN3x104lang3AnyE(x10_printer *printer, x10_any *any)
{
	UNUSED(printer);

	// TODO:  Do this right.
	x10_string *message = (x10_string *) any;
	wprintf(L"%ls\n", X10_STRING_BUF(message));
}
