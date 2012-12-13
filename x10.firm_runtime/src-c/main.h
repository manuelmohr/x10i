#ifndef MAIN_H
#define MAIN_H

#include "x10.h"

/* main function as defined by x10 code. The runtime should make sure
 * it is called. */
extern void x10_main(x10_object *args);

/* declaration for Array constructor in X10
 * x10.array.Array.makeStringArray(data: Pointer, n: Int): Array[String] */
extern x10_object *_ZN3x105array5Array15makeStringArrayEPvi(x10_pointer ptr, x10_int n);

#endif
