#!/bin/bash
RELEASE_DATE="2017-03-22"
DEFAULT_X86GUEST="4t-w-iotile"
DEFAULT_LEON="4t5c-chipit-w-iotile"
RELEASES=""
RELEASES="$RELEASES release.leon.${DEFAULT_LEON}.${RELEASE_DATE}.tar.bz2"
RELEASES="$RELEASES release.x86guest.${DEFAULT_X86GUEST}.${RELEASE_DATE}.tar.bz2"
RELEASES="$RELEASES release.x64native.generic.${RELEASE_DATE}.tar.bz2"
MD5SUMS="""
53f24235eef36202b097d6dde280c3c0  release.leon.4t5c-chipit-w-iotile.2017-03-22.tar.bz2
371f4d3c594ddee0d99e3c12d0b08f4e  release.x64native.generic.2017-03-22.tar.bz2
c33c422e6dd4a009b44ebe7d0cc90a14  release.x86guest.4t-w-iotile.2017-03-22.tar.bz2
"""

DIST_DIR="octopos-dist"
OCTOPOS_APP_DIR="octopos-app"
