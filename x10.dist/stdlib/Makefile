
LIBNAME=x10std
VERSION=2.1.0
A_FILE=lib${LIBNAME}.a
SO_FILE=lib${LIBNAME}.so.${VERSION}
C_FILES=$(shell ls *.c)
O_FILES=${C_FILES:%.c=%.o}

all: ${A_FILE} ${SO_FILE}

${A_FILE}: ${O_FILES}
	ar rucs lib${LIBNAME}.a ${O_FILES}

${SO_FILE}: ${O_FILES}
	gcc -shared -Wl,-soname,lib${LIBNAME}.so -o lib${LIBNAME}.so.${VERSION} ${O_FILES}

%.o: %.c
	gcc $< -O3 -Wall -W -pedantic -std=c99 -c -o $@

.PHONY: clean distclean
clean:
	rm -f ${O_FILES}

distclean: clean
	rm -f lib${LIBNAME}.so.${VERSION}
	rm -f lib${LIBNAME}.a
