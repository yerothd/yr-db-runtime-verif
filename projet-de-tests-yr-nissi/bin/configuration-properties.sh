export YR_SD_MEALY_MACHINE_COMPILER_FULL_PATH=${HOME}/yr_sd_runtime_verif_lang/yr_sd_runtime_verif_lang_COMPILER__generation.sh
export YR_SD_MEALY_MACHINE_SPEC_FOLDER_FULL_PATH=${HOME}/yr-db-runtime-verif/projet-de-tests-yr-nissi/sd-mealy-machine-specs
export YR_DB_RUNTIME_VERIF_SRC_FULL_PATH=${HOME}/yr-db-runtime-verif/src

YR_CURRENT_PROJECT_DIRECTORY=${PWD}
YR_CURRENT_PROJECT_DIRECTORY_BASE=${YR_CURRENT_PROJECT_DIRECTORY%%/bin}

#echo "* ${YR_CURRENT_PROJECT_DIRECTORY_BASE}"

export COMPILER_GENERATED_OUTPUT_FOLDER_FULL_PATH=${YR_CURRENT_PROJECT_DIRECTORY_BASE}/runtime-monitor-cplusplus-classes-GENERATED

#echo "**** ${COMPILER_GENERATED_OUTPUT_FOLDER_FULL_PATH}"

