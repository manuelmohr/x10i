#!/bin/bash
RELEASE_DATE="2016-12-16"
DEFAULT_X86GUEST="4t-w-iotile"
DEFAULT_LEON="4t5c-chipit-w-iotile"
RELEASES=""
RELEASES="$RELEASES release.leon.${DEFAULT_LEON}.${RELEASE_DATE}.tar.bz2"
RELEASES="$RELEASES release.x86guest.${DEFAULT_X86GUEST}.${RELEASE_DATE}.tar.bz2"
RELEASES="$RELEASES release.x64native.generic.${RELEASE_DATE}.tar.bz2"
MD5SUMS="""f3d215187ee64a238bb1f32bd14fc9c3  release.leon.${DEFAULT_LEON}.${RELEASE_DATE}.tar.bz2
7cea75e05b87cd520ee936956b72e205  release.x64native.generic.${RELEASE_DATE}.tar.bz2
c6cf39ca9cff6982706361459541cd66  release.x86guest.${DEFAULT_X86GUEST}.${RELEASE_DATE}.tar.bz2"""

DIST_DIR="octopos-dist"
OCTOPOS_APP_DIR="octopos-app"
