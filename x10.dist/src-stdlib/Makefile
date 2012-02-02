guessed_target := $(shell $(CC) -dumpmachine)
target         ?= $(guessed_target)

BUILDDIR=build
STDLIB_BUILDDIR=$(BUILDDIR)/$(target)

LIBNAME=x10std
VERSION=2.2.0
A_FILE=$(STDLIB_BUILDDIR)/lib$(LIBNAME).a
SO_FILE=$(STDLIB_BUILDDIR)/lib$(LIBNAME).so.$(VERSION)
ALL_C_FILES=$(shell ls *.c)
GEN_FIRM_NATIVE_SIZES=gen_firm_native_sizes.c
FIRM_NATIVE_TYPES_CONF=$(STDLIB_BUILDDIR)/firmNativeTypes.conf
C_FILES=$(filter-out $(GEN_FIRM_NATIVE_SIZES), $(ALL_C_FILES))
O_FILES=$(C_FILES:%.c=%.o)
H_FILES=$(shell ls *.h) # too conservative!
CFLAGS=-O3 -Wall -W -pedantic -std=c99 -fdollars-in-identifiers -D_GNU_SOURCE
MASTER=$(STDLIB_BUILDDIR)/master.c
O_FILE=$(MASTER:%.c=%.o)
IR_FILE=$(STDLIB_BUILDDIR)/stdlib.ir

all: $(A_FILE) $(SO_FILE) $(FIRM_NATIVE_TYPES_CONF) $(IR_FILE)

$(A_FILE): $(O_FILE)
	ar rucs $@ $?

$(SO_FILE): $(O_FILE)
	$(CC) $(CFLAGS) -shared -Wl,-soname,lib$(LIBNAME).so -o $@ $?

$(FIRM_NATIVE_TYPES_CONF): $(GEN_FIRM_NATIVE_SIZES) $(H_FILES)
	$(CC) -static -o gen_firm_native_sizes $<
	./gen_firm_native_sizes > $@
	rm -f gen_firm_native_sizes

$(MASTER): $(C_FILES) $(H_FILES) Makefile
	mkdir -p $(STDLIB_BUILDDIR)
	echo "$(foreach file,$(H_FILES),#include \"../../$(file)\"\n)"  >$(MASTER)
	echo "$(foreach file,$(C_FILES),#include \"../../$(file)\"\n)" >>$(MASTER)

$(O_FILE): $(MASTER)
	$(CC) $(CFLAGS) $< -c -o $@

$(IR_FILE): $(MASTER)
	cparser $(CFLAGS) -mtarget=$(target) -w $< --export-ir -o $@

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)
	rm -f $(O_FILES)
	rm -f $(FIRM_NATIVE_TYPES_CONF)
	rm -f $(A_FILE) $(SO_FILE) $(IR_FILE)
