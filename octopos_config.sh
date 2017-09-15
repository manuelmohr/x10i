#!/bin/bash
RELEASE_DATE="2017-09-14"
DEFAULT_X86GUEST="generic"
DEFAULT_LEON="generic-w-iotile"
RELEASES=""
RELEASES="$RELEASES release.leon.${DEFAULT_LEON}.${RELEASE_DATE}.tar.bz2"
RELEASES="$RELEASES release.x86guest.${DEFAULT_X86GUEST}.${RELEASE_DATE}.tar.bz2"
RELEASES="$RELEASES release.x64native.generic.${RELEASE_DATE}.tar.bz2"
MD5SUMS="""
0dbf080cbc6556dec7643f41deb912b0  release.leon.generic-w-iotile.2017-09-14.tar.bz2
221e70d0693ff005f3cf875d9e2ca345  release.x64native.generic.2017-09-14.tar.bz2
8be02eafce51fa6a3347fbdc93b83d2e  release.x86guest.generic.2017-09-14.tar.bz2
"""

DIST_DIR="octopos-dist"
OCTOPOS_APP_DIR="octopos-app"
