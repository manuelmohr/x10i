#!/bin/bash
#
# Simple and stupid setup. This should set things up in a way suitable for
# the IPD boxes.
# This shouldn't do anything special and you should be easily able to live
# without it...

# Check consistency of the java installation and set JAVA_HOME
if [ -z "$JAVA_HOME" ] ; then
	export JAVA_HOME="$(readlink -f $(dirname $(readlink -f /usr/bin/java))/../..)"
	echo "** WARNING: JAVA_HOME not set, using the ant files manually will not work"
	echo "Setting JAVA_HOME='$JAVA_HOME'"
	echo ""
	echo ""
fi
JAVA_HOME_STUFF="bin/java bin/javac bin/jar lib/tools.jar include/linux/ include/jni.h"
JAVA_INSTALL_OK=1
for file in $JAVA_HOME_STUFF; do
	if ! [ -e "$JAVA_HOME/$file" ]; then
		echo "JAVA_HOME/$file does not exist ($JAVA_HOME/$file)"
		JAVA_INSTALL_OK=0
	fi
done
# Abort here now, the X10 build will fail anyway if this stuff isn't there
if [ "$JAVA_INSTALL_OK" == "0" ]; then
	echo "JAVA_HOME: $JAVA_HOME (might be autodetected)"
	echo "Error: Your Java installation is not consistent"
	exit 1
fi

# Fetch submodules
git submodule update --init

# If /data1/user exists use that to place some build results into
DATA1DIR="/data1/`whoami`"
if test -w $DATA1DIR; then
	BUILDBASE="$DATA1DIR/builds/x10i"
	mkdir -p "$BUILDBASE/libfirm"
	ln -s "$BUILDBASE/libfirm" libfirm/build

	# This would be nice, but the antfiles usually revert this
	#NEEDS_JAVA_CLASSES="x10.common x10.compiler x10.constraints x10.runtime jFirm x10.firm"
	#for d in $NEEDS_JAVA_CLASSES; do
	#	mkdir -p "$BUILDBASE/$d"
	#	ln -s "$BUILDBASE/$d" $d/classes
	#done
fi

# Place a config.mak into libfirm directory, so we can get ccache benefits
rm -f libfirm/config.mak
rm -f liboo/config.mak
echo "FIRM_HOME        = ../libfirm" >> liboo/config.mak
echo "LIBFIRM_CPPFLAGS = -I\$(FIRM_HOME)/include" >> liboo/config.mak
echo "LIBFIRM_LFLAGS   = -L\$(FIRM_HOME)/build/debug -lfirm" >> liboo/config.mak
# Use ccache if you have it installed...
if which ccache > /dev/null; then
	echo "CC = ccache gcc" >> libfirm/config.mak
	echo "CC = ccache gcc" >> liboo/config.mak
fi
if [ "`uname -s`" = "Darwin" ]; then
	echo "DLLEXT = .dylib" >> libfirm/config.mak
	echo "DLLEXT = .dylib" >> liboo/config.mak
fi

# Run "ant dist" once so we have all the required stuff
pushd x10.dist > /dev/null
ant dist
popd
