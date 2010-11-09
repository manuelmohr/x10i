#!/bin/bash
#
# Simple and stupid setup. This should set things up in a way suitable for
# the IPD boxes.
# This shouldn't do anything special and you should be easily able to live
# without it...

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
echo "CC = ccache gcc" >> libfirm/config.mak

# Run "ant dist" once so we have all the required stuff
pushd x10.dist > /dev/null
# ant dist requires JAVA_HOME to be set, so do this now if it isn't already
[ -n "$JAVA_HOME" ] && export JAVA_HOME="$(readlink -f $(dirname $(readlink -f /usr/bin/java))/../..)"
ant dist
popd
