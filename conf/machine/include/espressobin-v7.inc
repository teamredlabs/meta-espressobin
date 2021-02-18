require conf/machine/include/espressobin-base.inc

MACHINEOVERRIDES =. "espressobin-v7:"

ATF_PLATFORM = "a3700"
ATF_DDR_TOPOLOGY = "5"
ATF_CLOCKSPRESET = "CPU_1000_DDR_800"
ATF_BOOT_DEV = "SPINOR"
ATF_BOOT_PART = "0"

UBOOT_MACHINE = "mvebu_espressobin-88f3720_defconfig"
UBOOT_DEVICE_TREE = "armada-3720-espressobin-emmc"

KERNEL_DEVICETREE = "marvell/armada-3720-espressobin-v7-emmc.dtb"
IMAGE_BOOT_FILES_append = " armada-3720-espressobin-v7-emmc.dtb;fdt.dtb"
