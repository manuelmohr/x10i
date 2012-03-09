-include config.mak

guessed_target := $(shell $(CC) -dumpmachine)
TARGET         ?= $(guessed_target)

CPARSER_TARGET ?= -mtarget=$(TARGET)
CFLAGS         ?=

SIMULATOR  ?=
APP_CFLAGS ?=
PLATFORM   ?= posix

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
ifeq ($(TARGET), i686-invasic-octopos)
	OCTOPOS_BASE=../octopos-app
	GCC_INCLUDE:=$(shell $(CC) --print-file-name=include)
	CFLAGS += -m32 -fno-stack-protector -mfpmath=sse -msse2 -nostdinc -D__OCTOPOS__ -I $(GCC_INCLUDE) -I $(OCTOPOS_BASE)/include
	LFLAGS += -m32 -nostdlib -Wl,-T,$(OCTOPOS_BASE)/sections.x $(OCTOPOS_BASE)/liboctopos.a
	PLATFORM = octopos
	CPARSER_TARGET =
else
	CFLAGS += -D_POSIX_C_SOURCE=200809L
endif

BUILDDIR?=build/$(TARGET)
SRCDIR=src-c
GENERATORSDIR=generators
PLATFORMDIR=$(SRCDIR)/$(PLATFORM)

LIBNAME=x10
A_FILE=$(BUILDDIR)/lib$(LIBNAME).a
ALL_C_FILES=$(wildcard $(SRCDIR)/*.c) $(wildcard $(PLATFORMDIR)/*.c)
GEN_FIRM_NATIVE_SIZES=$(PLATFORMDIR)/gen_firm_native_sizes.c
GEN_PRIMITIVE_TYPES=$(BUILDDIR)/x10_primitive_types.c
FIRM_NATIVE_TYPES_CONF=$(BUILDDIR)/firmNativeTypes.conf
C_FILES=$(filter-out $(GEN_FIRM_NATIVE_SIZES), $(ALL_C_FILES)) $(GEN_PRIMITIVE_TYPES)
O_FILES=$(addprefix $(BUILDDIR), $(basename $(C_FILES:%.c=%.o)))
H_FILES=$(wildcard $(SRCDIR)/*.h)
CFLAGS += -I $(SRCDIR) -I $(SRCDIR)/$(PLATFORM) -Wall -W -std=c99
APP_CFLAGS += -I $(SRCDIR)
MASTER=$(BUILDDIR)/master.c
O_FILE=$(MASTER:%.c=%.o)
IR_FILE=$(BUILDDIR)/$(LIBNAME).ir

all: $(A_FILE) $(FIRM_NATIVE_TYPES_CONF) $(IR_FILE)

$(A_FILE): $(O_FILE)
	ar rucs $@ $?

$(FIRM_NATIVE_TYPES_CONF): $(GEN_FIRM_NATIVE_SIZES) $(wildcard $(PLATFORMDIR)/*.h)
	$(CC) $(APP_CFLAGS) -o $(BUILDDIR)/gen_firm_native_sizes $<
	$(SIMULATOR) $(BUILDDIR)/gen_firm_native_sizes > $@
	rm -f gen_firm_native_sizes

$(GEN_PRIMITIVE_TYPES): $(GENERATORSDIR)/create_types.py
	mkdir -p $(BUILDDIR)
	$< > $@

$(MASTER): $(C_FILES) $(H_FILES) Makefile
	mkdir -p $(BUILDDIR)
	echo "$(foreach file,$(H_FILES),#include \"../../$(file)\"\n)"  >$(MASTER)
	echo "$(foreach file,$(C_FILES),#include \"../../$(file)\"\n)" >>$(MASTER)

$(O_FILE): $(MASTER)
	$(CC) $(CFLAGS) $< -c -o $@

$(IR_FILE): $(MASTER)
	cparser $(CFLAGS) $(CPARSER_TARGET) -w $< --export-ir -o $@

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)
