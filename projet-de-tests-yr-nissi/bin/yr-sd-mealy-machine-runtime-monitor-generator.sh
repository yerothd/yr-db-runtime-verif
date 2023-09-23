#!/bin/bash

. configuration-properties.sh

echo "YR_SD_MEALY_MACHINE_COMPILER_FULL_PATH: $YR_SD_MEALY_MACHINE_COMPILER_FULL_PATH"

for f in $(dir ${YR_SD_MEALY_MACHINE_SPEC_FOLDER_FULL_PATH});
do
	echo "compiling a C++ runtime monitor for input specification: '${YR_SD_MEALY_MACHINE_SPEC_FOLDER_FULL_PATH}/$f'"

	${YR_SD_MEALY_MACHINE_COMPILER_FULL_PATH} \
		-i "${YR_SD_MEALY_MACHINE_SPEC_FOLDER_FULL_PATH}/$f" \
		-d "${COMPILER_GENERATED_OUTPUT_FOLDER_FULL_PATH}"

	MEALY_MACHINE_NAME=$(cat outputted_SD_MEALY_MACHINE_NAME.txt)

	rm -f "${MEALY_MACHINE_NAME}"

done

sleep 0.3

rm -f ${COMPILER_GENERATED_OUTPUT_FOLDER_FULL_PATH}/*.orig

rm -f *.dot *.pdf

rm outputted_SD_MEALY_MACHINE_NAME.txt

