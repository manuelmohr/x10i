#!/bin/bash
set -ev
VARIANT=generic
TARGET_DIR=$(pwd)/octopos-app/releases/

export IRTSSBASE=$(readlink -e $1)
echo "IRTSSBASE = ${IRTSSBASE}"
export PATH=${IRTSSBASE}/tools/bin:/opt/aspectc++:$PATH

# build iRTSS
cd ${IRTSSBASE}
platform/generateVariants.sh
build4platform.pl platform/release.x86guest.${VARIANT}.pm

# install here
DATE=$(date "+%Y-%m-%d")
install() {
	mkdir -p "$1/${DATE}"
	echo "install release.x86guest.${VARIANT} to $1"
	cp -r releases/git/x86guest "$1/${DATE}"
	pushd "$1"
	echo "in $(pwd): current -> ${DATE}"
	rm -f current
	ln -s ${DATE} current
	cd current/x86guest/
	echo "in $(pwd): default -> ${VARIANT}"
	rm -f default
	ln -s ${VARIANT} default
	popd
}

install ${TARGET_DIR}
