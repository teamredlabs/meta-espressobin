require linux-espressobin.inc

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

SRC_URI += "\
    file://0001-Added-v5-distinction-to-ESPRESSObin-v5-device-trees.patch \
"

FILES_kernel-base += "${nonarch_base_libdir}/modules/${KERNEL_VERSION}/modules.builtin.modinfo"

addtask shared_workdir_module_symvers_hack after do_kernel_link_images before do_shared_workdir

do_shared_workdir_module_symvers_hack () {
    touch ${B}/Module.symvers
}
