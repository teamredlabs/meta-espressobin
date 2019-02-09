require conf/machine/include/arm/espressobin-arch-arm64.inc

MACHINEOVERRIDES =. "espressobin:"
MACHINE_ENDIANNESS ?= "le"
MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "kernel-image kernel-devicetree"
MACHINE_EXTRA_RRECOMMENDS += "kernel-modules"
MACHINE_FEATURES = "ext2 ipsec nfs pci smbfs usbgadget usbhost vfat"
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc qemu-usermode"

require conf/multilib.conf

MULTILIBS = "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 = "armv8a-neon"
DEFAULTTUNE ?= "${@bb.utils.contains("MACHINE_ENDIANNESS", "le", "aarch64", "aarch64_be", d)}"

PREFERRED_PROVIDER_virtual/kernel ?= "linux-espressobin"
PREFERRED_PROVIDER_virtual/bootloader ?= "u-boot-espressobin"

PREFERRED_PROVIDER_linux ?= "linux-espressobin"
PREFERRED_PROVIDER_u-boot ?= "u-boot-espressobin"
PREFERRED_PROVIDER_u-boot-fw-utils ?= "u-boot-espressobin-fw-utils"
PREFERRED_PROVIDER_arm-trusted-firmware ?= "arm-trusted-firmware-espressobin"

IMAGE_FSTYPES += "tar.bz2"
IMAGE_BOOT_FILES = "Image;Image"

KERNEL_IMAGETYPE = "Image"

SERIAL_CONSOLE = "115200 ttyMV0"
