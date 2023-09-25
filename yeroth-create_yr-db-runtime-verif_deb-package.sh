#!/bin/bash
#email: yeroth.d@gmail.com
#author: DR.-ING.  DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU (YEROTH R&D)!


rm -f yr-db-runtime-verif.deb


cp YR-DB-RUNTIME-VERIF-GUI-ELEMENTS-SETUP/yr-db-runtime-verif.desktop \
	yr-db-runtime-verif/usr/share/applications


cp YR-DB-RUNTIME-VERIF-GUI-ELEMENTS-SETUP/LOGO-icon.png \
	yr-db-runtime-verif/usr/share/pixmaps


cp YR-DB-RUNTIME-VERIF-GUI-ELEMENTS-SETUP/yr-db-runtime-verif-database-connection.properties \
	yr-db-runtime-verif/opt/yr-db-runtime-verif


cp YR-DB-RUNTIME-VERIF-GUI-ELEMENTS-SETUP/yr-db-runtime-verif-BIN.SH \
	yr-db-runtime-verif/opt/yr-db-runtime-verif/bin


cp YR-DB-RUNTIME-VERIF-GUI-ELEMENTS-SETUP/YEROTH_QVGE_compendium.pdf \
	yr-db-runtime-verif/usr/share/doc/yr-db-runtime-verif


mkdir -p yr-db-runtime-verif/opt/yr-db-runtime-verif/bin

cp bin/yr-db-runtime-verif yr-db-runtime-verif/opt/yr-db-runtime-verif/bin

touch yr-db-runtime-verif/opt/yr-db-runtime-verif/yr-db-runtime-verif.log

chmod go+rw yr-db-runtime-verif/opt/yr-db-runtime-verif/yr-db-runtime-verif.log

chmod 755 yr-db-runtime-verif/DEBIAN/postinst

dpkg-deb --build yr-db-runtime-verif


cp yr.db-runtime.verif.xml ${YEROTH_ERP_3_0_HOME_FOLDER}/src/dbus/
