require u-boot-espressobin.inc

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://README;md5=8ff0837b355cf37b6b956f316d010d0c"

SRCREV = "c9aa92ce70d16b3d6c6291c6be69f42783a4ebc0"
SRCBRANCH = "u-boot-2018.03-armada-18.12"

FILESEXTRAPATHS_prepend := "${THISDIR}/patches:"
FILESEXTRAPATHS_prepend_espressobin-v7 := "${THISDIR}/patches-v7:"

SRC_URI_append = "\
    file://0001-Swapped-sdhci0-and-sdhci1-to-reflect-linux-device-tr.patch \
    file://0002-Add-target-to-generate-initial-environment.patch \
"

SRC_URI_append_espressobin-v7 = "\
    file://0001-git-add-some-temporary-files-into-git-ignore-list.patch \
    file://0002-mtd-add-gigadevice-gd25lq32d-spi-flash-support.patch \
"
