require u-boot-espressobin_${PV}.inc
require recipes-bsp/u-boot/u-boot.inc

DEPENDS += "dtc-native"

PROVIDES += "u-boot"
RPROVIDES_${PN} += "u-boot"
