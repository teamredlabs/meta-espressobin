require linux-espressobin.inc

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

SRC_URI += "\
    file://0001-Copied-ESPRESSObin-device-trees-from-linux-marvell.patch \
    file://0002-Created-separate-device-trees-for-ESPRESSObin-V5-and.patch \
"
