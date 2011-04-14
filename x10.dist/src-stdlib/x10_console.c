#include "x10_console.h"
#include "x10_printer.h"

x10_printer *_ZN3x102io7Console3OUTE;
x10_printer *_ZN3x102io7Console3ERRE;

#define OUT_OBJECT _ZN3x102io7Console3OUTE
#define ERR_OBJECT _ZN3x102io7Console3ERRE

static int out_initialized = 0;
static int err_initialized = 0;

static x10_printer *lazy_init_printer(x10_printer **printer, int *initialized,
                                      FILE *target)
{
	// TODO:  This probably needs to be thread-safe.
	if (*initialized == 0) {
		*printer = malloc(sizeof(x10_printer));
		memset(*printer, 0, sizeof(x10_printer));
		(*printer)->target = target;
		*initialized = 1;
	}

	return *printer;
}

x10_printer *_ZN3x102io7Console8OUT__getEv(void)
{
	return lazy_init_printer(&OUT_OBJECT, &out_initialized, stdout);
}

x10_printer *_ZN3x102io7Console8ERR__getEv(void)
{
	return lazy_init_printer(&ERR_OBJECT, &err_initialized, stderr);
}
