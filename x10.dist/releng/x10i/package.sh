#!/bin/sh

set -e

mydir="`dirname "$0"`"
top="`cd "$mydir"/../../.. && pwd`"
cdir="`pwd`"
[ "$cdir" = "/" ] && cdir="$cdir."
cd "$top"

# Initialize the submodules.
git submodule update --init

# Make sure that the working copy is clean.
cd x10.dist
ant distclean
cd ..

# Build x10i for all available targets.
./setup.sh
cd x10.dist
ant dist-firm $@ -DVARIANT=optimize -DTARGET=i686-invasic-octopos
ant dist-firm $@ -DVARIANT=optimize -DTARGET=i686-invasic-irtss
ant dist-firm $@ -DVARIANT=optimize -DTARGET=i686-linux-gnu
ant dist-firm $@ -DVARIANT=optimize -DTARGET=sparc-invasic-octopos
ant dist-firm $@ -DVARIANT=optimize -DTARGET=sparc-invasic-irtss
ant dist-firm $@ -DVARIANT=optimize -DTARGET=x86_64-invasic-octopos
ant dist-firm $@ -DVARIANT=optimize -DTARGET=x86_64-invasic-irtss
ant dist-firm $@ -DVARIANT=optimize -DTARGET=x86_64-linux-gnu
cd ..

# Pack everything together.
tar czf "$cdir/$mydir/x10i.tar.gz" --files-from="$cdir/$mydir/distfiles.txt" \
    --transform='s,^,x10i/,S'
