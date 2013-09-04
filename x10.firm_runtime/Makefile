-include config.mak

guessed_target := $(shell $(CC) -dumpmachine)
TARGET         ?= $(guessed_target)
CC              = $(TARGET)-gcc

CPARSER_TARGET ?= -mtarget=$(TARGET)
CFLAGS         ?= -g3
CPPFLAGS       ?=

APP_CFLAGS ?=
PLATFORM   ?= posix

# The ugly part... Collection of hacks for certain architectures
ifeq ($(findstring x86_64, $(TARGET)), x86_64)
	CFLAGS += -m32
	APP_CFLAGS += -m32
	CPARSER_TARGET=
endif
ifeq ($(findstring sparc, $(TARGET)), sparc)
	APP_CFLAGS += -static
	CFLAGS += -msoft-float
endif
ifeq ($(findstring darwin, $(TARGET)), darwin)
	CPARSER_TARGET=
endif
ifeq ($(findstring darwin11, $(TARGET)), darwin11)
	CFLAGS += -m32
	LFLAGS += -m32
	APP_CFLAGS += -m32
endif
ifeq ($(findstring invasic, $(TARGET)), invasic)
	PLATFORM = octopos
	GCC_INCLUDE:=$(shell $(CC) --print-file-name=include)
	CFLAGS += -fno-stack-protector
	CPPFLAGS += -nostdinc -I $(OCTOPOS_BASE)/include -DNO_GARBAGE_COLLECTION
endif
ifeq ($(findstring i686-invasic, $(TARGET)), i686-invasic)
	OCTOPOS_BASE=../octopos-app/releases/current/x86guest/multitile
	CFLAGS += -m32 -mfpmath=sse -msse2
	CPPFLAGS += -I $(GCC_INCLUDE)
	LFLAGS += -m32 -nostdlib -Wl,-T,$(OCTOPOS_BASE)/lib/sections.x $(OCTOPOS_BASE)/lib/liboctopos.a $(OCTOPOS_BASE)/lib/libcsubset.a
endif
ifeq ($(findstring invasic-irtss, $(TARGET)), invasic-irtss)
	CPPFLAGS += -DUSE_AGENTSYSTEM
endif
ifeq ($(findstring sparc-invasic, $(TARGET)), sparc-invasic)
	# For now, always build for soft float
	OCTOPOS_BASE=../octopos-app/releases/current/leon/4t-sf-chipit-w-iotile
	CPPFLAGS += -D__leon__ -isystem $(GCC_INCLUDE)
endif
ifeq ($(findstring linux, $(TARGET)), linux)
	CFLAGS += -D_XOPEN_SOURCE=500 -D_SVID_SOURCE -pthread
	CPPFLAGS += -I../bdwgc/include
endif

CPARSER_BASE ?= ../cparser
CPARSER = $(CPARSER_BASE)/build/debug/cparser
BUILDDIR?=build/$(TARGET)
SRCDIR=src-c
GENERATORSDIR=generators
PLATFORMDIR=$(SRCDIR)/$(PLATFORM)
LIBOO_BASE ?= ../liboo

LIBNAME=x10
A_FILE=$(BUILDDIR)/lib$(LIBNAME).a
ALL_C_FILES=$(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/adt/*.c) $(wildcard $(PLATFORMDIR)/*.c)
GEN_FIRM_NATIVE_SIZES=$(SRCDIR)/gen_firm_native_sizes.c $(PLATFORMDIR)/platform_native_sizes.c
GEN_PRIMITIVE_TYPES=$(BUILDDIR)/x10_primitive_types.c
FIRM_NATIVE_TYPES_CONF=$(BUILDDIR)/firmNativeTypes.conf
C_FILES=$(filter-out $(GEN_FIRM_NATIVE_SIZES), $(ALL_C_FILES)) $(GEN_PRIMITIVE_TYPES)
O_FILES=$(addprefix $(BUILDDIR), $(basename $(C_FILES:%.c=%.o)))
H_FILES=$(wildcard $(SRCDIR)/*.h) $(wildcard $(SRCDIR)/adt/*.h) $(wildcard $(PLATFORMDIR)/*.h)
CPPFLAGS += -I $(SRCDIR) -I $(SRCDIR)/$(PLATFORM) -I $(LIBOO_BASE)/include
CFLAGS += -Wall -W -std=c99
APP_CFLAGS += -std=c99
MASTER=$(BUILDDIR)/master.c
O_FILE=$(MASTER:%.c=%.o)
IR_FILE=$(BUILDDIR)/$(LIBNAME).ir

all: $(A_FILE) $(FIRM_NATIVE_TYPES_CONF) $(IR_FILE)

$(A_FILE): $(O_FILE)
	ar rucs $@ $?

$(FIRM_NATIVE_TYPES_CONF): $(GEN_FIRM_NATIVE_SIZES) $(wildcard $(PLATFORMDIR)/*.h) $(wildcard $(SRCDIR)/*.h) $(CPARSER)
	$(CPARSER) --no-external-pp --print-compound-sizes $(CPPFLAGS) $(APP_CFLAGS) -o $@ $(SRCDIR)/gen_firm_native_sizes.c

$(GEN_PRIMITIVE_TYPES): $(GENERATORSDIR)/create_types.py
	mkdir -p $(BUILDDIR)
	$< > $@

$(MASTER): $(GENERATORSDIR)/mkincludes.py $(C_FILES) $(H_FILES) Makefile
	mkdir -p $(BUILDDIR)
	$< ../../ $(C_FILES) > $(MASTER)

$(O_FILE): $(MASTER)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -c -o $@

Makefile: cparser_subdir
cparser_subdir:
	$(MAKE) -C $(CPARSER_BASE) FIRM_HOME=../libfirm
.PHONY: cparser_subdir

$(IR_FILE): $(MASTER) $(CPARSER)
	$(CPARSER) --no-external-pp $(CPPFLAGS) $(CFLAGS) $(CPARSER_TARGET) -w $< --export-ir -o $@

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)
