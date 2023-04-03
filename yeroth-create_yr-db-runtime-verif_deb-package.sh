#!/bin/bash
#email: yeroth.d@gmail.com
#author: Dr.-Ing. XAVIER NOUMBISSI NOUNDOU (YEROTH R&D)!

cp bin/yr-db-runtime-verif yr-db-runtime-verif/opt/yr-db-runtime-verif/bin

chmod go+rw yr-db-runtime-verif/opt/yr-db-runtime-verif/yr-db-runtime-verif.log

chmod 755 yr-db-runtime-verif/DEBIAN/postinst

dpkg-deb --build yr-db-runtime-verif
