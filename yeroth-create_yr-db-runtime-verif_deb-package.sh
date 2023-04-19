#!/bin/bash
#email: yeroth.d@gmail.com
#author: DR.-ING.  DR.-ING. DIPL.-INF. XAVIER NOUMBISSI NOUNDOU (YEROTH R&D)!

mkdir -p yr-db-runtime-verif/opt/yr-db-runtime-verif/bin

cp bin/yr-db-runtime-verif yr-db-runtime-verif/opt/yr-db-runtime-verif/bin

touch yr-db-runtime-verif/opt/yr-db-runtime-verif/yr-db-runtime-verif.log

chmod go+rw yr-db-runtime-verif/opt/yr-db-runtime-verif/yr-db-runtime-verif.log

chmod 755 yr-db-runtime-verif/DEBIAN/postinst

dpkg-deb --build yr-db-runtime-verif
