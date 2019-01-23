require u-boot-espressobin.inc

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://README;md5=089c6275df97d40f52f08aee128a2ad3"

FILESEXTRAPATHS_prepend := "${THISDIR}/patches:"

SRCREV = "${AUTOREV}"
SRCBRANCH = "u-boot-2017.03-armada-17.10"
SRC_URI += "git://github.com/MarvellEmbeddedProcessors/u-boot-marvell.git;protocol=https;branch=${SRCBRANCH}"
SRC_URI += "file://0001-Added-override-directive-to-env-Makefile.patch"
SRC_URI += "file://0002-Change-system_info.h-import-in-global_data.h-to-forc.patch"

S = "${WORKDIR}/git"
