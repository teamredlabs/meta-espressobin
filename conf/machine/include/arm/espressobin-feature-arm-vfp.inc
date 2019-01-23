TUNEVALID[vfp] = "Enable Vector Floating Point (vfp) unit."
TUNE_CCARGS_MFPU .= "${@bb.utils.contains('TUNE_FEATURES', 'vfp', ' vfp', '', d)}"

TUNE_CCARGS  .= "${@ (' -mfpu=%s ' % d.getVar('TUNE_CCARGS_MFPU', True).split()[-1]) if (d.getVar('TUNE_CCARGS_MFPU', True) != '') else ''}"
ARMPKGSFX_FPU = "${@ ('-%s'        % d.getVar('TUNE_CCARGS_MFPU', True).split()[-1]) if (d.getVar('TUNE_CCARGS_MFPU', True) != '') else ''}"

TUNEVALID[callconvention-hard] = "Enable EABI hard float call convention, requires VFP."
TUNE_CCARGS_MFLOAT = "${@ bb.utils.contains('TUNE_FEATURES', 'callconvention-hard', 'hard', 'softfp', d) if (d.getVar('TUNE_CCARGS_MFPU', True) != '') else '' }"
TUNE_CCARGS   .= "${@ ' -mfloat-abi=${TUNE_CCARGS_MFLOAT}' if (d.getVar('TUNE_CCARGS_MFLOAT', True) != '')     else ''}"
ARMPKGSFX_EABI = "${@ 'hf'                                 if (d.getVar('TUNE_CCARGS_MFLOAT', True) == 'hard') else ''}"
