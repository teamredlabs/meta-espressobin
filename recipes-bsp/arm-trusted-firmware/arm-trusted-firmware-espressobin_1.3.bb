require arm-trusted-firmware-espressobin.inc

LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://license.md;md5=829bdeb34c1d9044f393d5a16c068371"

FILESEXTRAPATHS_prepend := "${THISDIR}/patches:"

SRCREV_atf = "${AUTOREV}"
SRCBRANCH_atf = "atf-v1.3-armada-17.10"
SRC_URI += "git://github.com/MarvellEmbeddedProcessors/atf-marvell.git;protocol=https;branch=${SRCBRANCH_atf};name=atf;destsuffix=atf"
SRC_URI += "file://atf_0001-Use-BUILD_CC-to-compile-native-parts.patch"

SRCREV_mv-ddr = "${AUTOREV}"
SRCBRANCH_mv-ddr = "mv_ddr-armada-17.10"
SRC_URI += "git://github.com/MarvellEmbeddedProcessors/mv-ddr-marvell.git;protocol=https;branch=${SRCBRANCH_mv-ddr};name=mv-ddr;destsuffix=mv-ddr"
SRC_URI += "file://a3700-utils_0001-Provided-include-directory-to-wtmi_ddr-Makefile.patch"
SRC_URI += "file://a3700-utils_0002-parser-add-preset_ddr_conf-field-for-preset-ddr-sett.patch"
SRC_URI += "file://a3700-utils_0003-ddr-update-ddr-topology-for-ddr3-2gbytes.patch"

SRCREV_A3700-utils = "${AUTOREV}"
SRCBRANCH_A3700-utils = "A3700_utils-armada-17.10"
SRC_URI += "git://github.com/MarvellEmbeddedProcessors/A3700-utils-marvell.git;protocol=https;branch=${SRCBRANCH_A3700-utils};name=A3700-utils;destsuffix=A3700-utils"

do_patch () {
    cd ${WORKDIR}/atf
    git am ../atf_0001-Use-BUILD_CC-to-compile-native-parts.patch
    cd ${WORKDIR}/A3700-utils
    git am ../a3700-utils_0001-Provided-include-directory-to-wtmi_ddr-Makefile.patch
    git am ../a3700-utils_0002-parser-add-preset_ddr_conf-field-for-preset-ddr-sett.patch
    git am ../a3700-utils_0003-ddr-update-ddr-topology-for-ddr3-2gbytes.patch
    cd ${WORKDIR}
}
