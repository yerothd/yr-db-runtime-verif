#!/bin/bash
# @AUTHOR: Dr.-Ing. XAVIER NOUMBISSI NOUNDOU
# @EMAIL: yeroth.d@gmail.com


#yr_compile_LIB_FOR_YEROTH_ERP_3_0_j4.sh

#cp lib/libyr-db-runtime-verif_FOR_YEROTH_ERP.a "${YEROTH_ERP_3_0_HOME_FOLDER}/lib"
#echo "cp lib/libyr-db-runtime-verif_FOR_YEROTH_ERP.a '${YEROTH_ERP_3_0_HOME_FOLDER}/lib'"


MYFILE=YR_DB_RUNTIME_VERIF_HEADERS_FOR_yeroth_erp.TXT

echo "processing files within '${MYFILE}'"

echo "cp yr.db-runtime.verif.xml /home/yer/yeroth-erp-3-0/src/dbus/yr.db-runtime.verif.xml "
cp yr.db-runtime.verif.xml /home/yer/yeroth-erp-3-0/src/dbus/yr.db-runtime.verif.xml 

n=1
while read LINE; do
	CUR_YR_DEV_FILE=`find src -name "${LINE}"`

	FILE_TO_REPLACE="${YEROTH_ERP_3_0_HOME_FOLDER}/src/${LINE}"

	echo "cp "${CUR_YR_DEV_FILE}" "${FILE_TO_REPLACE}""

	cp "${CUR_YR_DEV_FILE}" "${FILE_TO_REPLACE}"

	n=$((n+1))
done < "$MYFILE"


