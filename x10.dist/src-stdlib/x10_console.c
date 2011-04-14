#include "x10_console.h"
#include "x10_printer.h"

x10_printer *_ZN3x102io7Console3OUTE;
x10_printer *_ZN3x102io7Console3ERRE;

static int initialized = 0;

x10_printer *_ZN3x102io7Console8OUT__getEv(void)
{
	// TODO:  Does this need to be thread-safe?
	if (initialized == 0) {
		_ZN3x102io7Console3OUTE = malloc(sizeof(x10_printer));
		memset(_ZN3x102io7Console3OUTE, 0, sizeof(x10_printer));
		initialized = 1;
	}

	return _ZN3x102io7Console3OUTE;
}
