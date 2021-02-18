require arm-trusted-firmware-espressobin.inc

LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://license.rst;md5=e927e02bca647e14efd87e9e914b2443"

BB_GIT_SHALLOW = "1"
BB_GIT_SHALLOW_DEPTH = "1"

SRCROOT = "github.com/MarvellEmbeddedProcessors"

#######################################
# atf-marvell
#######################################

FILESEXTRAPATHS_prepend := "${THISDIR}/patches/atf:"
FILESEXTRAPATHS_prepend_espressobin-v7 := "${THISDIR}/patches-v7/atf:"

SRCREPO_atf = "${SRCROOT}/atf-marvell.git"
SRCREV_atf = "1f8ca7e01d4ac7023aea0eeb4c8a4b98dcf05760"
SRCBRANCH_atf = "atf-v1.5-armada-18.12"
SRCNAME_atf = "atf"
SRCDIR_atf = "${WORKDIR}/${SRCNAME_atf}"
SRCCFG_atf = "branch=${SRCBRANCH_atf};name=${SRCNAME_atf};destsuffix=${SRCNAME_atf}"
SRCURI_atf = "${SRCREPO_atf};${SRCCFG_atf}"

SRC_URI_append = " git://${SRCURI_atf};protocol=https"

SRC_URI_append = "\
    file://0001-Use-BUILD_CC-to-compile-native-parts.patch;patchdir=${SRCDIR_atf} \
"

SRC_URI_append_espressobin-v7 = "\
    file://0001-build-build-and-combine-primary-and-secondary-bootlo.patch;patchdir=${SRCDIR_atf} \
    file://0002-build-add-compile-option-to-build-secondary-boot-ima.patch;patchdir=${SRCDIR_atf} \
"

#######################################
# mv-ddr-marvell
#######################################

SRCREPO_mv-ddr = "${SRCROOT}/mv-ddr-marvell.git"
SRCREV_mv-ddr = "618dadd1491eb2f7b2fd74313c04f7accddae475"
SRCBRANCH_mv-ddr = "mv_ddr-armada-18.12"
SRCNAME_mv-ddr = "mv-ddr"
SRCDIR_mv-ddr = "${WORKDIR}/${SRCNAME_mv-ddr}"
SRCCFG_mv-ddr = "branch=${SRCBRANCH_mv-ddr};name=${SRCNAME_mv-ddr};destsuffix=${SRCNAME_mv-ddr}"
SRCURI_mv-ddr = "${SRCREPO_mv-ddr};${SRCCFG_mv-ddr}"

SRC_URI_append = " git://${SRCURI_mv-ddr};protocol=https"

#######################################
# a3700-utils-marvell
#######################################

FILESEXTRAPATHS_prepend := "${THISDIR}/patches/a3700-utils:"
FILESEXTRAPATHS_prepend_espressobin-v7 := "${THISDIR}/patches-v7/a3700-utils:"

SRCREPO_a3700-utils = "${SRCROOT}/A3700-utils-marvell.git"
SRCREV_a3700-utils = "1a13f2fe40f9a5405c92bb78a5eb60724b1d4a38"
SRCBRANCH_a3700-utils = "A3700_utils-armada-18.12-fixed"
SRCNAME_a3700-utils = "a3700-utils"
SRCDIR_a3700-utils = "${WORKDIR}/${SRCNAME_a3700-utils}"
SRCCFG_a3700-utils = "branch=${SRCBRANCH_a3700-utils};name=${SRCNAME_a3700-utils};destsuffix=${SRCNAME_a3700-utils}"
SRCURI_a3700-utils = "${SRCREPO_a3700-utils};${SRCCFG_a3700-utils}"

SRC_URI_append = " git://${SRCURI_a3700-utils};protocol=https"

SRC_URI_append = "\
    file://0001-Provided-include-directory-to-wtmi-Makefiles.patch;patchdir=${SRCDIR_a3700-utils} \
"

SRC_URI_append_espressobin-v7 = "\
    file://0001-Added-tim-img-files-to-build-the-secondary-image.patch;patchdir=${SRCDIR_a3700-utils} \
    file://0002-buildtim-add-argument-for-build-primary-or-secondary.patch;patchdir=${SRCDIR_a3700-utils} \
    file://0003-git-add-clocks_ddr.txt-to-git-ignore-list.patch;patchdir=${SRCDIR_a3700-utils} \
    file://0004-add-.d-files-to-gitignore.patch;patchdir=${SRCDIR_a3700-utils} \
"
