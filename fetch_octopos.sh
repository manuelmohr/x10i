#!/bin/bash
#
# Called by the ant build to fetch the required version of octopos and
# install/extract it.
set -eu

RELEASES=""
RELEASES="$RELEASES release.leon.4t-sf-chipit-w-iotile.2013-12-02.tar.bz2"
RELEASES="$RELEASES release.x86guest.multitile.2013-12-24.tar.bz2"
MD5SUMS="""8e4240dbe931e6af08824d3f61f1442c  release.leon.4t-sf-chipit-w-iotile.2013-12-02.tar.bz2
302cb56afc4342eabf2f8c8cb355100f  release.x86guest.multitile.2013-12-24.tar.bz2"""

DIST_DIR="octopos-dist"
OCTOPOS_APP_DIR="octopos-app"

# First check if the currently expanded octopos is already the version we want?
if test -r "$OCTOPOS_APP_DIR/md5sums"; then
	if echo "$MD5SUMS" | cmp -s "$OCTOPOS_APP_DIR/md5sums"; then
		echo "octopos-app is up-to-date"
		exit 0
	fi
fi

# make sure we are in the correct directory
if ! test -e fetch_octopos.sh; then
	echo "fetch_octopos.sh must be started from toplevel x10i dir"
	exit 1
fi

# first ensure that we have the release files available
mkdir -p "$DIST_DIR"
for release in $RELEASES; do
	if ! test -e "$DIST_DIR/$release"; then
		IPDDIR="/ben/local/octopos-releases"
		if test -r "$IPDDIR/$release"; then
			echo "Copying $release from $IPDDIR"
			cp -p "$IPDDIR/$release" "$DIST_DIR"
		else
			echo "Cannot find $DIST_DIR/$release, please download it"
			exit 1
		fi
	fi
done

# Check md5sum to be sure
pushd "$DIST_DIR" > /dev/null
echo "$MD5SUMS" | md5sum --quiet -c 
popd > /dev/null

# Extract the releases to their correct place
#
mkdir -p "$OCTOPOS_APP_DIR"
rm -rf "$OCTOPOS_APP_DIR/releases"
mkdir -p "$OCTOPOS_APP_DIR/releases"
for release in $RELEASES; do
	echo "Extracting $release"
	tar -xf "$DIST_DIR/$release" -C "$OCTOPOS_APP_DIR/releases"
done

# Remember what we extracted so the script doesn't need to do it again
echo "$MD5SUMS" > "$OCTOPOS_APP_DIR/md5sums"
