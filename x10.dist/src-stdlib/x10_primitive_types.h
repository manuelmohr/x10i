#include "x10.h"

#define DEF_WRAPPER(t,t2) \
	struct t##_w { \
		X10_OBJECT_HEADER \
		t val;	\
	};	\
	X10_EXTERN t##_w *t##_w##_from_##t(t val) { \
		t##_w *obj = X10_ALLOC_OBJECT(t##_w); \
		X10_INIT_OBJECT(obj,t2); \
		X10_WRAP_VAL(obj) = val; \
		return obj; \
	}

#define X10_WRAP_VAL(o) ((o)->val)

DEF_WRAPPER(x10_int, 	 T_INT)
DEF_WRAPPER(x10_uint, 	 T_UINT)
DEF_WRAPPER(x10_long, 	 T_LONG)
DEF_WRAPPER(x10_ulong,	 T_ULONG)
DEF_WRAPPER(x10_short, 	 T_SHORT)
DEF_WRAPPER(x10_ushort,  T_USHORT)
DEF_WRAPPER(x10_byte, 	 T_BYTE)
DEF_WRAPPER(x10_ubyte, 	 T_UBYTE)
DEF_WRAPPER(x10_char, 	 T_CHAR)
DEF_WRAPPER(x10_float, 	 T_FLOAT)
DEF_WRAPPER(x10_double,  T_DOUBLE)
DEF_WRAPPER(x10_boolean, T_BOOLEAN)

