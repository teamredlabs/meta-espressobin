require conf/machine/include/espressobin-base.inc

MACHINEOVERRIDES =. "espressobin-v5:"

ATF_PLATFORM = "a3700"
ATF_DDR_TOPOLOGY = "2"
ATF_CLOCKSPRESET = "CPU_1000_DDR_800"
ATF_BOOT_DEV = "SPINOR"
ATF_BOOT_PART = "0"

UBOOT_MACHINE = "mvebu_espressobin-88f3720_defconfig"
UBOOT_DEVICE_TREE = "armada-3720-espressobin"

KERNEL_DEVICETREE = "marvell/armada-3720-espressobin.dtb"
IMAGE_BOOT_FILES_append = " Image-armada-3720-espressobin.dtb;fdt.dtb"
