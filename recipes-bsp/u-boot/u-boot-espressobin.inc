SUMMARY = "U-Boot for Globalscale Marvell ESPRESSObin"
DESCRIPTION = "U-Boot for Globalscale Marvell ESPRESSObin"
HOMEPAGE = "http://www.denx.de/wiki/U-Boot"
SECTION = "bootloaders"

DEPENDS_append = " bc-native dtc-native"
EXTRA_OEMAKE_append = " DEVICE_TREE=${UBOOT_DEVICE_TREE}"

require recipes-bsp/u-boot/u-boot.inc

PROVIDES += "u-boot"
RPROVIDES_${PN} += "u-boot"

BB_GIT_SHALLOW = "1"
BB_GIT_SHALLOW_DEPTH = "1"
SRC_URI = "git://github.com/MarvellEmbeddedProcessors/u-boot-marvell.git;protocol=https;branch=${SRCBRANCH}"

S = "${WORKDIR}/git"
B = "${WORKDIR}/build"

COMPATIBLE_MACHINE = "(espressobin-v5|espressobin-v7)"
