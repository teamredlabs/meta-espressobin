require u-boot-espressobin.inc

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://README;md5=089c6275df97d40f52f08aee128a2ad3"

FILESEXTRAPATHS_prepend := "${THISDIR}/patches:"
FILESEXTRAPATHS_prepend_espressobin-v7 := "${THISDIR}/patches-v7:"

SRCREV = "${AUTOREV}"
SRCBRANCH = "u-boot-2017.03-armada-17.10"

SRC_URI_append = "\
    git://github.com/MarvellEmbeddedProcessors/u-boot-marvell.git;protocol=https;branch=${SRCBRANCH} \
    file://0001-Added-override-directive-to-env-Makefile.patch \
    file://0002-Change-system_info.h-import-in-global_data.h-to-forc.patch \
    file://0003-Added-mx25u3235f-SPI-flash-ID-to-spi_flash_ids.c.patch \
    file://0004-DTS-espressobin-add-emmc-device-support.patch \
    file://0005-Swapped-sdhci0-and-sdhci1-to-reflect-linux-device-tr.patch \
"

SRC_URI_append_espressobin-v7 = "\
    file://0001-git-add-some-temporary-files-into-git-ignore-list.patch \
    file://0002-mtd-add-issi-is25wp032d-spi-flash-support.patch \
    file://0003-mtd-add-gigadevice-gd25lq32d-spi-flash-support.patch \
"

S = "${WORKDIR}/git"
