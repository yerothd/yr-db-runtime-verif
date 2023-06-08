#!/bin/bash
#@AUTEUR: DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU

# SHOWS THIS Makefile FILE COMMAND STRING IN THE
# CONSOLE AS THEY ARE EXECUTED.
set -x

yr_compile_j4.sh

rm -f yr-db-runtime-verif.deb


cp YR-DB-RUNTIME-VERIF-GUI-ELEMENTS-SETUP/yr-db-runtime-verif.desktop \
	yr-db-runtime-verif/usr/share/applications


cp YR-DB-RUNTIME-VERIF-GUI-ELEMENTS-SETUP/LOGO-icon.png \
	yr-db-runtime-verif/usr/share/pixmaps


cp YR-DB-RUNTIME-VERIF-GUI-ELEMENTS-SETUP/yr-db-runtime-verif-BIN.SH \
	yr-db-runtime-verif/opt/yr-db-runtime-verif/bin


cp YR-DB-RUNTIME-VERIF-GUI-ELEMENTS-SETUP/YEROTH_QVGE.pdf \
	yr-db-runtime-verif/usr/share/doc/yr-db-runtime-verif


yeroth-create_yr-db-runtime-verif_deb-package.sh


cp yr.db-runtime.verif.xml ${YEROTH_ERP_3_0_HOME_FOLDER}/src/dbus/

