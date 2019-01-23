TUNEVALID[neon] = "Enable Neon SIMD accelerator unit."
TUNE_CCARGS_MFPU .= "${@bb.utils.contains('TUNE_FEATURES', 'neon', ' neon', '', d)}"

TUNEVALID[vfpv3d16] = "Enable Vector Floating Point Version 3 with 16 registers (vfpv3-d16) unit."
TUNE_CCARGS_MFPU .= "${@bb.utils.contains('TUNE_FEATURES', 'vfpv3d16', ' vfpv3d16', '', d)}"

TUNEVALID[vfpv3] = "Enable Vector Floating Point Version 3 with 32 registers (vfpv3) unit."
TUNE_CCARGS_MFPU .= "${@bb.utils.contains('TUNE_FEATURES', 'vfpv3', ' vfpv3', '' , d)}"

TUNEVALID[vfpv4] = "Enable Vector Floating Point Version 4 (vfpv4) unit."
TUNE_CCARGS_MFPU .= "${@bb.utils.contains('TUNE_FEATURES', 'vfpv4', ' vfpv4', '', d)}"
TUNE_CCARGS_MFPU .= "${@bb.utils.contains('TUNE_FEATURES', [ 'vfpv4', 'neon' ], ' neon-vfpv4', '', d)}"
