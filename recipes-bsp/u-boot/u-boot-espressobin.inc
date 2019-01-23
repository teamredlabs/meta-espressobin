SUMMARY = "U-Boot for Globalscale Marvell ESPRESSObin"
DESCRIPTION = "U-Boot for Globalscale Marvell ESPRESSObin"
HOMEPAGE = "http://www.denx.de/wiki/U-Boot"
SECTION = "bootloaders"

EXTRA_OEMAKE += "DEVICE_TREE=${UBOOT_DEVICE_TREE}"

COMPATIBLE_MACHINE = "(espressobin-v5)"
