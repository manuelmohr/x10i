
LIBNAME=x10std
VERSION=2.2.0
A_FILE=lib${LIBNAME}.a
SO_FILE=lib${LIBNAME}.so.${VERSION}
ALL_C_FILES=$(shell ls *.c)
GEN_FIRM_NATIVE_SIZES=gen_firm_native_sizes
FIRM_NATIVE_TYPES_CONF=firmNativeTypes.conf
C_FILES=$(filter-out ${GEN_FIRM_NATIVE_SIZES}.c, ${ALL_C_FILES})
O_FILES=${C_FILES:%.c=%.o}
H_FILES=$(shell ls *.h) # too conservative!

all: ${A_FILE} ${SO_FILE}

${A_FILE}: ${O_FILES} firmNativeTypes
	ar rucs lib${LIBNAME}.a ${O_FILES}

${SO_FILE}: ${O_FILES} firmNativeTypes
	gcc -shared -Wl,-soname,lib${LIBNAME}.so -o lib${LIBNAME}.so.${VERSION} ${O_FILES}

%.o: %.c ${H_FILES} 
	gcc $< -O3 -fdollars-in-identifiers -Wall -W -pedantic -std=c99 -c -o $@

firmNativeTypes:
	gcc -o ${GEN_FIRM_NATIVE_SIZES} ${GEN_FIRM_NATIVE_SIZES}.c
	./${GEN_FIRM_NATIVE_SIZES}
	cp firmNativeTypes.conf ../

.PHONY: clean distclean
clean:
	rm -f ${O_FILES}
	rm -f ${GEN_FIRM_NATIVE_SIZES}

distclean: clean
	rm -f lib${LIBNAME}.so.${VERSION}
	rm -f lib${LIBNAME}.a
