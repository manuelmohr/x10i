LIBNAME=x10std
VERSION=2.2.0
A_FILE=lib$(LIBNAME).a
SO_FILE=lib$(LIBNAME).so.$(VERSION)
ALL_C_FILES=$(shell ls *.c)
GEN_FIRM_NATIVE_SIZES=gen_firm_native_sizes.c
FIRM_NATIVE_TYPES_CONF=firmNativeTypes.conf
C_FILES=$(filter-out $(GEN_FIRM_NATIVE_SIZES).c, $(ALL_C_FILES))
O_FILES=$(C_FILES:%.c=%.o)
H_FILES=$(shell ls *.h) # too conservative!

all: $(A_FILE) $(SO_FILE) $(FIRM_NATIVE_TYPES_CONF)

$(A_FILE): $(O_FILES)
	ar rucs $@ $?

$(SO_FILE): $(O_FILES)
	gcc -shared -Wl,-soname,lib$(LIBNAME).so -o $@ $?

%.o: %.c $(H_FILES)
	gcc -D_GNU_SOURCE $< -O3 -fdollars-in-identifiers -Wall -W -pedantic -std=c99 -c -o $@

$(FIRM_NATIVE_TYPES_CONF): $(GEN_FIRM_NATIVE_SIZES) $(H_FILES)
	gcc -o gen_firm_native_sizes $<
	./gen_firm_native_sizes > $@
	rm -f gen_firm_native_sizes

.PHONY: clean
clean:
	rm -f $(O_FILES)
	rm -f $(FIRM_NATIVE_TYPES_CONF)
	rm -f $(A_FILE) $(SO_FILE)
