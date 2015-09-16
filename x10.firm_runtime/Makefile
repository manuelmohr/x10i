-include config.mak

guessed_target := $(shell $(CC) -dumpmachine)
TARGET         ?= $(guessed_target)
CC              = $(TARGET)-gcc
variant        ?= debug

CPARSER_TARGET ?= -mtarget=$(TARGET)
CFLAGS         ?= -g3 -O2
CPPFLAGS       ?=
CPPFLAGS       += -I../bdwgc/include

APP_CFLAGS     ?=
PLATFORM       ?= posix

CPARSER_BASE   ?= ../cparser
CPARSER         = $(CPARSER_BASE)/build/$(variant)/cparser
BUILDDIR       ?= build/$(TARGET)
SRCDIR          = src-c
GENERATORSDIR   = generators
LIBOO_BASE     ?= ../liboo

# The ugly part... Collection of hacks for certain architectures
ifeq ($(findstring sparc, $(TARGET)), sparc)
	APP_CFLAGS += -static
	CFLAGS += -DDOUBLE_IS_32BIT
	GENERATOR_FLAGS = --avoid-doubleregs
	DOUBLEREG_LIB = $(BUILDDIR)/libdoublereg.a
endif
ifeq ($(findstring darwin, $(TARGET)), darwin)
	CPARSER_TARGET=
endif
ifeq ($(findstring darwin11, $(TARGET)), darwin11)
	CFLAGS += -m32
	LFLAGS += -m32
	APP_CFLAGS += -m32
endif
ifeq ($(findstring x86_64, $(guessed_target)), x86_64)
ifeq ($(findstring i686, $(TARGET)), i686)
	CFLAGS += -m32
	LFLAGS += -m32
	APP_CFLAGS += -m32
endif
endif
ifeq ($(findstring invasic, $(TARGET)), invasic)
	PLATFORM = octopos
	GCC_INCLUDE:=$(shell $(CC) --print-file-name=include)
	CFLAGS += -fno-stack-protector -ffreestanding
	CPPFLAGS += -nostdinc
	# This is NOT unix/linux...
	CPPFLAGS += -Ulinux -U__linux -U__linux__ -U__gnu_linux__ -Uunix -U__unix -U__unix__
	# ...it is OctoPOS
	CPPFLAGS += -D__OCTOPOS__
	CPPFLAGS += -I $(OCTOPOS_BASE)/include
endif
ifeq ($(findstring i686-invasic, $(TARGET)), i686-invasic)
	OCTOPOS_BASE=../octopos-app/releases/current/x86guest/default
	CFLAGS += -m32 -mfpmath=sse -msse2
	APP_CFLAGS += -m32 -mfpmath=sse -msse2
	CPPFLAGS += -I $(GCC_INCLUDE)
	LFLAGS += -m32 -nostdlib -Wl,-T,$(OCTOPOS_BASE)/lib/sections.x $(OCTOPOS_BASE)/lib/liboctopos.a $(OCTOPOS_BASE)/lib/libcsubset.a
endif
ifeq ($(findstring x86_64-invasic, $(TARGET)), x86_64-invasic)
	OCTOPOS_BASE=../octopos-app/releases/current/x64native/default
	CPPFLAGS += -I $(GCC_INCLUDE) -DNO_GARBAGE_COLLECTION
	LFLAGS += -nostdlib -Wl,-T,$(OCTOPOS_BASE)/lib/sections.x $(OCTOPOS_BASE)/lib/liboctopos.a $(OCTOPOS_BASE)/lib/libcsubset.a $(OCTOPOS_BASE)/lib/lotail.a
endif
ifeq ($(findstring invasic-irtss, $(TARGET)), invasic-irtss)
	CPPFLAGS += -DUSE_AGENTSYSTEM
endif
ifeq ($(findstring sparc-invasic, $(TARGET)), sparc-invasic)
	OCTOPOS_BASE=../octopos-app/releases/current/leon/default
	CPPFLAGS += -D__leon__ -isystem $(GCC_INCLUDE)
	# Enable for i-Core support (needs libicore)
#	CPPFLAGS += -DHAVE_ICORE -I../libicore/include
endif
ifeq ($(findstring linux, $(TARGET)), linux)
	CFLAGS += -D_XOPEN_SOURCE=500 -D_SVID_SOURCE -pthread
endif
ifeq ($(findstring i686-linux, $(TARGET)), i686-linux)
	OCTOPOS_EXTRAS=../octopos-app/releases/current/extras/libethcomm
	CPPFLAGS += -I $(OCTOPOS_EXTRAS)
	# Choose if you want big-endian serialization or not
	# (Needed for host place mode on CHIPit)
#	CPPFLAGS += -DBIG_ENDIAN_SERIALIZATION
endif


PLATFORMDIR=$(SRCDIR)/$(PLATFORM)
LIBNAME=x10
A_FILE=$(BUILDDIR)/lib$(LIBNAME).a
ALL_C_FILES=$(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/adt/*.c) $(wildcard $(PLATFORMDIR)/*.c)
GEN_FIRM_NATIVE_SIZES=$(SRCDIR)/gen_firm_native_sizes.c $(PLATFORMDIR)/platform_native_sizes.c
GEN_PRIMITIVE_TYPES=$(BUILDDIR)/x10_primitive_types.c
FIRM_NATIVE_TYPES_CONF=$(BUILDDIR)/firmNativeTypes.conf
C_FILES=$(filter-out $(GEN_FIRM_NATIVE_SIZES), $(ALL_C_FILES)) $(GEN_PRIMITIVE_TYPES)
O_FILES=$(addprefix $(BUILDDIR), $(basename $(C_FILES:%.c=%.o)))
H_FILES=$(wildcard $(SRCDIR)/*.h) $(wildcard $(SRCDIR)/adt/*.h) $(wildcard $(PLATFORMDIR)/*.h)
IRTSS_HEADER=$(wildcard ../octopos-app/releases/current/x86guest/default/include/*.h)
CPPFLAGS += -I $(SRCDIR) -I $(SRCDIR)/$(PLATFORM) -I $(LIBOO_BASE)/include
CFLAGS += -Wall -W -std=c99
APP_CFLAGS += -std=c99
MASTER=$(BUILDDIR)/master.c
O_FILE=$(MASTER:%.c=%.o)
IR_FILE=$(BUILDDIR)/$(LIBNAME).ir

all: $(A_FILE) $(FIRM_NATIVE_TYPES_CONF) $(IR_FILE) $(DOUBLEREG_LIB)

$(A_FILE): $(O_FILE)
	ar rucs $@ $?

$(FIRM_NATIVE_TYPES_CONF): $(GEN_FIRM_NATIVE_SIZES) $(wildcard $(PLATFORMDIR)/*.h) $(wildcard $(SRCDIR)/*.h) $(CPARSER) $(IRTSS_HEADER)
	$(CPARSER) --print-compound-sizes $(CPARSER_TARGET) $(CPPFLAGS) $(APP_CFLAGS) -I $(SRCDIR)/$(PLATFORM)/include-workaround -o $@ $(SRCDIR)/gen_firm_native_sizes.c

$(GEN_PRIMITIVE_TYPES): $(GENERATORSDIR)/create_types.py
	mkdir -p $(BUILDDIR)
	$< $(GENERATOR_FLAGS) > $@

$(MASTER): $(GENERATORSDIR)/mkincludes.py $(C_FILES) $(H_FILES) Makefile
	mkdir -p $(BUILDDIR)
	$< ../../ $(C_FILES) > $(MASTER)

$(O_FILE): $(MASTER)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -c -o $@

$(DOUBLEREG_LIB): $(SRCDIR)/doublereg/convert.c $(SRCDIR)/doublereg/to_string.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SRCDIR)/doublereg/convert.c -c -o $(BUILDDIR)/convert.o
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SRCDIR)/doublereg/to_string.c -c -o $(BUILDDIR)/to_string.o
	ar rucs $@ $(BUILDDIR)/convert.o $(BUILDDIR)/to_string.o

Makefile: cparser_subdir
cparser_subdir:
	$(MAKE) -C $(CPARSER_BASE) FIRM_HOME=../libfirm
.PHONY: cparser_subdir

$(IR_FILE): $(MASTER) $(CPARSER)
	$(CPARSER) $(CPPFLAGS) $(CFLAGS) -I $(SRCDIR)/$(PLATFORM)/include-workaround $(CPARSER_TARGET) -w $< --export-ir -o $@

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)
