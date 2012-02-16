-include config.mak

guessed_target := $(shell $(CC) -dumpmachine)
target         ?= $(guessed_target)

CPARSER_TARGET ?= -mtarget=$(target)
CFLAGS         ?=

SIMULATOR  ?=
APP_CFLAGS ?=

# The ugly part... Collection of hacks for certain architectures
ifeq ($(findstring x86_64, $(target)), x86_64)
	CFLAGS += -m32
	CPARSER_TARGET=
endif
ifeq ($(findstring sparc, $(target)), sparc)
	APP_CFLAGS += -static
endif
ifeq ($(findstring darwin, $(target)), darwin)
	CPARSER_TARGET=
endif
ifeq ($(findstring darwin11, $(target)), darwin11)
	CFLAGS += -m32
	LFLAGS += -m32
endif

PLATFORM=posix
ifeq ($(findstring octopos, $(target)), octopos)
	PLATFORM=octopos
endif

BUILDDIR=build
STDLIB_BUILDDIR=$(BUILDDIR)/$(target)
SRCDIR=src-c
PLATFORMDIR=$(SRCDIR)/$(PLATFORM)

LIBNAME=x10
A_FILE=$(STDLIB_BUILDDIR)/lib$(LIBNAME).a
ALL_C_FILES=$(wildcard $(SRCDIR)/*.c) $(wildcard $(PLATFORMDIR)/*.c)
GEN_FIRM_NATIVE_SIZES=$(PLATFORMDIR)/gen_firm_native_sizes.c
FIRM_NATIVE_TYPES_CONF=$(STDLIB_BUILDDIR)/firmNativeTypes.conf
C_FILES=$(filter-out $(GEN_FIRM_NATIVE_SIZES), $(ALL_C_FILES))
O_FILES=$(addprefix $(BUILDDIR), $(basename $(C_FILES:%.c=%.o)))
H_FILES=$(wildcard $(SRCDIR)/*.h)
CFLAGS += -Wall -W -pedantic -std=c99 -fdollars-in-identifiers
MASTER=$(STDLIB_BUILDDIR)/master.c
O_FILE=$(MASTER:%.c=%.o)
IR_FILE=$(STDLIB_BUILDDIR)/$(LIBNAME).ir

all: $(A_FILE) $(FIRM_NATIVE_TYPES_CONF) $(IR_FILE)

$(A_FILE): $(O_FILE)
	ar rucs $@ $?

$(FIRM_NATIVE_TYPES_CONF): $(GEN_FIRM_NATIVE_SIZES) $(wildcard $(PLATFORMDIR)/*.h)
	$(CC) $(APP_CFLAGS) -o gen_firm_native_sizes $<
	$(SIMULATOR) ./gen_firm_native_sizes > $@
	rm -f gen_firm_native_sizes

$(MASTER): $(C_FILES) $(H_FILES) Makefile
	mkdir -p $(STDLIB_BUILDDIR)
	echo "$(foreach file,$(H_FILES),#include \"../../$(file)\"\n)"  >$(MASTER)
	echo "$(foreach file,$(C_FILES),#include \"../../$(file)\"\n)" >>$(MASTER)

$(O_FILE): $(MASTER)
	$(CC) $(CFLAGS) $< -c -o $@

$(IR_FILE): $(MASTER)
	cparser $(CFLAGS) $(CPARSER_TARGET) -w $< --export-ir -o $@

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)
