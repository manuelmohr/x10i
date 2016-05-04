#!/bin/sh

set -e

mydir="`dirname "$0"`"
top="`cd "$mydir"/../../.. && pwd`"
cdir="`pwd`"
[ "$cdir" = "/" ] && cdir="$cdir."
cd "$top"

# Build x10i for all available targets.
# NOTE: We assume that the working copy is clean.
./setup.sh -DVARIANT=optimize -DTARGET=i686-invasic-octopos
./setup.sh -DVARIANT=optimize -DTARGET=i686-invasic-irtss
./setup.sh -DVARIANT=optimize -DTARGET=i686-linux-gnu
./setup.sh -DVARIANT=optimize -DTARGET=sparc-invasic-octopos
./setup.sh -DVARIANT=optimize -DTARGET=sparc-invasic-irtss
./setup.sh -DVARIANT=optimize -DTARGET=x86_64-invasic-octopos
./setup.sh -DVARIANT=optimize -DTARGET=x86_64-invasic-irtss
./setup.sh -DVARIANT=optimize -DTARGET=x86_64-linux-gnu

# Pack everything together.
tar czf "$cdir/$mydir/x10i.tar.gz" --files-from="$cdir/$mydir/distfiles.txt" \
    --transform='flags=S;s,^,x10i/,'
