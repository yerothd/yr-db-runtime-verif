#!/bin/bash
#@AUTEUR: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU

# SHOWS THIS Makefile FILE COMMAND STRING IN THE
# CONSOLE AS THEY ARE EXECUTED.
set -x

# -------------------------------------------------------------- #
YR_DB_RUNTIME_VERIF_deb_folder=yr-db-runtime-verif
cp yr.db-runtime.verif.conf 		${YR_DB_RUNTIME_VERIF_deb_folder}/etc/dbus-1/system.d/yr.db-runtime.verif.conf
cp yr-db-runtime-verif.service 	${YR_DB_RUNTIME_VERIF_deb_folder}/lib/systemd/system/yr-db-runtime-verif.service
cp yr.db-runtime.verif.xml 			${YR_DB_RUNTIME_VERIF_deb_folder}/usr/share/dbus-1/interfaces/yr.db-runtime.verif.xml
cp yr.db-runtime.verif.service 	${YR_DB_RUNTIME_VERIF_deb_folder}/usr/share/dbus-1/system-services/yr.db-runtime.verif.service
# -------------------------------------------------------------- #


#qdbusxml2cpp -a src/YRruntimeverification_adaptor yr.db-runtime.verif.xml 


YR_ERRORS_LOG_FILE="yr_errors.log"


mkdir -p ${COMPILER_GENERATED_OUTPUT_FOLDER_FULL_PATH}


cp ${COMPILER_GENERATED_OUTPUT_FOLDER_FULL_PATH}/*.hpp src

cp ${COMPILER_GENERATED_OUTPUT_FOLDER_FULL_PATH}/*.cpp src


mkdir bin

clear && qmake -o Makefile yr-db-runtime-verif.pro

make clean

OUT_CMD_TIME=$(time make -j4 > /dev/null 2> "${YR_ERRORS_LOG_FILE}")

val=$(cat "${YR_ERRORS_LOG_FILE}" | grep -w "*** No rule to make target\|error\|ERROR\|Error" | wc -l)

if [ ${val} -eq 0 ]; then
	#rm -f "${YR_ERRORS_LOG_FILE}" 
	echo "[success compilation]"
	
	rm -f verif_adaptor.h
	rm -f verif_adaptor.cpp

else
	echo "[compilation avec des erreurs (${val})]"
fi


echo ${OUT_CMD_TIME}

