SUMMARY = "Cryptodev-linux is a Linux-kernel device that allows user-space access to hardware cryptographic accelerators"
DESCRIPTION = "\
This is a /dev/crypto device driver, equivalent to those in OpenBSD or \
FreeBSD. The main idea is to access of existing ciphers in kernel space \
from userspace, thus enabling the re-use of a hardware implementation of a \
cipher."
HOMEPAGE = "http://cryptodev-linux.org/"

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263"

BB_GIT_SHALLOW = "1"
BB_GIT_SHALLOW_DEPTH = "1"
SRC_URI = "git://github.com/cryptodev-linux/cryptodev-linux;protocol=https;tag=cryptodev-linux-${PV};nobranch=1"

S = "${WORKDIR}/git"

CLEANBROKEN = "1"
