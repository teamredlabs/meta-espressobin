require linux-espressobin.inc

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

FILESEXTRAPATHS_prepend := "${THISDIR}/configs:"

SRCREV = "${AUTOREV}"
SRCBRANCH = "linux-4.19.y"
SRC_URI += "git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git;protocol=https;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"
