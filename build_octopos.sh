#!/bin/bash
set -ev
VARIANT=4t-w-iotile
TARGET_DIR=$(pwd)/octopos-app/releases/

export IRTSSBASE=$(readlink -e $1)
echo "IRTSSBASE = ${IRTSSBASE}"
export PATH=${IRTSSBASE}/tools/bin:$PATH

./fetch_octopos.sh # ensure fetch won't override us later

# build iRTSS
cd ${IRTSSBASE}
platform/generateVariants.sh
build4platform.pl platform/release.x86guest.${VARIANT}.pm

# install here
DATE=$(date "+%Y-%m-%d")
install() {
	echo "install release.x86guest.${VARIANT} to $1"
	cp -r release.x86guest.multitile_config/release/${DATE} "$1"
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
