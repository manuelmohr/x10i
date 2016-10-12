#!/bin/bash
RELEASE_DATE="2016-09-15"
DEFAULT_X86GUEST="4t-w-iotile"
DEFAULT_LEON="4t5c-chipit-w-iotile"
RELEASES=""
RELEASES="$RELEASES release.leon.${DEFAULT_LEON}.${RELEASE_DATE}.tar.bz2"
RELEASES="$RELEASES release.x86guest.${DEFAULT_X86GUEST}.${RELEASE_DATE}.tar.bz2"
RELEASES="$RELEASES release.x64native.generic.${RELEASE_DATE}.tar.bz2"
MD5SUMS="""ebcc4c40415c58056c0ae551e8d71bd1  release.leon.${DEFAULT_LEON}.${RELEASE_DATE}.tar.bz2
1e9cff0b774126cf76cd19d6c473c2ac  release.x64native.generic.${RELEASE_DATE}.tar.bz2
4b20ce6a2882f5f97132a6595768bbd4  release.x86guest.${DEFAULT_X86GUEST}.${RELEASE_DATE}.tar.bz2"""

DIST_DIR="octopos-dist"
OCTOPOS_APP_DIR="octopos-app"
