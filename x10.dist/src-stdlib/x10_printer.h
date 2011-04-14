#ifndef X10_PRINTER_H_
#define X10_PRINTER_H_

#include "x10.h"

struct x10_printer {
	X10_OBJECT_HEADER
	FILE *target;
};

X10_EXTERN void _ZN3x102io7Printer7printlnEPN3x104lang3AnyE(x10_printer *, x10_any *);

#endif // X10_PRINTER_H_
