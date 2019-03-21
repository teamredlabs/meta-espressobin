SUMMARY = "ARM Trusted Firmware for Globalscale Marvell ESPRESSObin"
DESCRIPTION = "ARM Trusted Firmware for Globalscale Marvell ESPRESSObin"
HOMEPAGE = "https://github.com/ARM-software/arm-trusted-firmware"

PROVIDES += "\
    arm-trusted-firmware \
    virtual/firmware \
"

DEPENDS_append = " \
    coreutils-native \
    lib32-gcc-cross-arm \
    openssl-native \
    unzip-native \
"

inherit deploy

S = "${WORKDIR}/atf"
SRCREV_FORMAT = "atf"

export CROSS_COMPILE="${TARGET_PREFIX}"
CFLAGS[unexport] = "1"
LDFLAGS[unexport] = "1"
AS[unexport] = "1"
LD[unexport] = "1"
do_configure[noexec] = "1"

TARGET_VENDOR_CM3 = "${TARGET_VENDOR_virtclass-multilib-lib32}"
TARGET_ARCH_CM3 = "${TUNE_ARCH_32}"
TARGET_OS_CM3 = "${TARGET_OS}-gnueabi"
MACHINE_ARCH_CM3 = "${MACHINE_ARCH}"

TARGET_SYS_CM3 = "${TARGET_ARCH_CM3}"
TARGET_SYS_CM3_append = "${TARGET_VENDOR_CM3}"
TARGET_SYS_CM3_append = "-${TARGET_OS_CM3}"

MULTIMACH_TARGET_SYS_CM3 = "${MACHINE_ARCH_CM3}"
MULTIMACH_TARGET_SYS_CM3_append = "${TARGET_VENDOR_CM3}"
MULTIMACH_TARGET_SYS_CM3_append = "-${TARGET_OS_CM3}"

WORKDIR_CM3 = "${BASE_WORKDIR}/"
WORKDIR_CM3_append = "${MULTIMACH_TARGET_SYS_CM3}/"
WORKDIR_CM3_append = "${PN}/${PV}-${PR}"

STAGING_DIR_TARGET_CM3 = "${WORKDIR_CM3}/lib32-recipe-sysroot"
STAGING_INCDIR_CM3 = "${STAGING_DIR_TARGET_CM3}/usr/include"

export CROSS_CM3 = "${STAGING_BINDIR_NATIVE}/${TARGET_SYS_CM3}/${TARGET_SYS_CM3}-"
export INCLUDE_CM3 = "${STAGING_INCDIR_CM3}"

EXTRA_OEMAKE += " \
    BL33=${DEPLOY_DIR_IMAGE}/u-boot.bin \
    PLAT=${ATF_PLATFORM} \
    DDR_TOPOLOGY=${ATF_DDR_TOPOLOGY} \
    CLOCKSPRESET=${ATF_CLOCKSPRESET} \
    BOOTDEV=${ATF_BOOT_DEV} \
    PARTNUM=${ATF_BOOT_PART} \
    MV_DDR_PATH="${WORKDIR}/mv-ddr" \
    WTP="${SRCDIR_a3700-utils}" \
    USE_COHERENT_MEM=0 \
    LOG_LEVEL=20 \
    DEBUG=0 \
    SECURE=1 \
"

do_compile[depends] = "virtual/bootloader:do_deploy"

do_compile () {
    oe_runmake all fip
}

do_install[noexec] = "1"

ATF_DEPLOYDIR  = "${S}/build/${ATF_PLATFORM}/release"

do_deploy () {
    install -d ${DEPLOYDIR}
    
    install -m 0644 ${ATF_DEPLOYDIR}/flash-image.bin ${DEPLOYDIR}/flash-image-${MACHINE}-${PV}-${PR}.bin
    ln -sf flash-image-${MACHINE}-${PV}-${PR}.bin ${DEPLOYDIR}/flash-image-${MACHINE}.bin
    ln -sf flash-image-${MACHINE}-${PV}-${PR}.bin ${DEPLOYDIR}/flash-image.bin

    install -m 0644 ${ATF_DEPLOYDIR}/uart-images.tgz ${DEPLOYDIR}/uart-images-${MACHINE}-${PV}-${PR}.tgz
    ln -sf uart-images-${MACHINE}-${PV}-${PR}.tgz ${DEPLOYDIR}/uart-images-${MACHINE}.tgz
    ln -sf uart-images-${MACHINE}-${PV}-${PR}.tgz ${DEPLOYDIR}/uart-images.tgz
}

addtask deploy before do_build after do_compile

PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "(espressobin-v5|espressobin-v7)"
