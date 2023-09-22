#!/bin/bash

. ../configuration-properties.sh

echo "YR_SD_MEALY_MACHINE_COMPILER_FULL_PATH: $YR_SD_MEALY_MACHINE_COMPILER_FULL_PATH"

for f in $(dir ${YR_SD_MEALY_MACHINE_SPEC_FOLDER_FULL_PATH});
do
	echo "compiling a C++ runtime monitor for input specification: '${YR_SD_MEALY_MACHINE_SPEC_FOLDER_FULL_PATH}/$f'"

	${YR_SD_MEALY_MACHINE_COMPILER_FULL_PATH} < "${YR_SD_MEALY_MACHINE_SPEC_FOLDER_FULL_PATH}/$f"

done
