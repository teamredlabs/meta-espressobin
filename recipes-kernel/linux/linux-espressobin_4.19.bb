require linux-espressobin.inc

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

FILESEXTRAPATHS_prepend := "${THISDIR}/patches:"

SRCREV = "${AUTOREV}"
SRCBRANCH = "linux-4.19.y"

SRC_URI_append = "\
    git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git;protocol=https;branch=${SRCBRANCH} \
    file://0001-Copied-ESPRESSObin-device-trees-from-linux-marvell.patch \
    file://0002-Created-separate-device-trees-for-ESPRESSObin-V5-and.patch \
"

S = "${WORKDIR}/git"
