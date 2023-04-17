#!/bin/bash
#AUTEUR: DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
#EMAIL: yeroth.d@gmail.com


# -------------------------------------------------------------- #
YR_DB_RUNTIME_VERIF_deb_folder=yr-db-runtime-verif
cp yr.db-runtime.verif.conf 		${YR_DB_RUNTIME_VERIF_deb_folder}/etc/dbus-1/system.d/yr.db-runtime.verif.conf
cp yr-db-runtime-verif.service 	${YR_DB_RUNTIME_VERIF_deb_folder}/lib/systemd/system/yr-db-runtime-verif.service
cp yr.db-runtime.verif.xml 			${YR_DB_RUNTIME_VERIF_deb_folder}/usr/share/dbus-1/interfaces/yr.db-runtime.verif.xml
cp yr.db-runtime.verif.service 	${YR_DB_RUNTIME_VERIF_deb_folder}/usr/share/dbus-1/system-services/yr.db-runtime.verif.service
# -------------------------------------------------------------- #


#qdbusxml2cpp -a src/YRruntimeverification_adaptor yr.db-runtime.verif.xml 


YR_ERRORS_LOG_FILE="yr_errors.log"

clear && qmake -o Makefile yr-db-runtime-verif.pro

make clean

OUT_CMD_TIME=$(time make -j4 > /dev/null 2> "${YR_ERRORS_LOG_FILE}")

val=$(cat "${YR_ERRORS_LOG_FILE}" | grep -w 'error\|ERROR\|Error' | wc -l)

if [ ${val} -eq 0 ]; then
	#rm -f "${YR_ERRORS_LOG_FILE}" 
	echo "[compilation avec succes]"
	
	rm -f verif_adaptor.h
	rm -f verif_adaptor.cpp
	
	rm -f yr-db-runtime-verif.deb
	
	yeroth-create_yr-db-runtime-verif_deb-package.sh
	
	cp yr.db-runtime.verif.xml ${YEROTH_ERP_3_0_HOME_FOLDER}/src/dbus/

else
	echo "[compilation avec des erreurs (${val})]"
fi


echo ${OUT_CMD_TIME}

