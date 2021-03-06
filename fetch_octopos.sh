#!/bin/bash
#
# Called by the ant build to fetch the required version of octopos and
# install/extract it.
#
# Note: octopos nightlies can be found at:
#    https://www4.cs.fau.de/invasic/octopos/
set -euv

source octopos_config.sh

SSH_HOSTNAME="ssh.info.uni-karlsruhe.de"

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
		echo "Trying to fetch $DIST_DIR/$release ..."
		IPDDIR="/ben/local/octopos-releases"
		if ! test -d "$IPDDIR"; then
			echo "You cannot access our AFS filesystem. Maybe ssh? Try:"
			echo scp -p "$SSH_HOSTNAME:$IPDDIR/$release" "$DIST_DIR"
			exit 1
		else if test -r "$IPDDIR/$release"; then
			echo "Copying $release from $IPDDIR"
			cp -p "$IPDDIR/$release" "$DIST_DIR"
		else
			echo "Cannot find $IPDDIR/$release, please download it from https://www4.cs.fau.de/invasic/octopos/"
			echo "Tip: There is a 'get.sh' script in /ben/local/octopos-releases"
			exit 1
		fi
		fi
	fi
done

# Check md5sum to be sure
pushd "$DIST_DIR" > /dev/null
echo "$MD5SUMS" | md5sum --quiet -c
popd > /dev/null

# Extract the releases to their correct place
mkdir -p "$OCTOPOS_APP_DIR/releases"
for release in $RELEASES; do
	echo "Extracting $release"
	tar -xf "$DIST_DIR/$release" -C "$OCTOPOS_APP_DIR/releases"
done

# Create default symlinks
pushd "$OCTOPOS_APP_DIR/releases/" > /dev/null
ln -sf "$RELEASE_DATE" "current"
popd > /dev/null
pushd "$OCTOPOS_APP_DIR/releases/current/x86guest" > /dev/null
ln -sf "$DEFAULT_X86GUEST" "default"
popd > /dev/null
pushd "$OCTOPOS_APP_DIR/releases/current/leon" > /dev/null
ln -sf "$DEFAULT_LEON" "default"
popd > /dev/null
pushd "$OCTOPOS_APP_DIR/releases/current/x64native" > /dev/null
ln -sf "generic" "default"
popd > /dev/null

# Remember what we extracted so the script doesn't need to do it again
echo "$MD5SUMS" > "$OCTOPOS_APP_DIR/md5sums"
