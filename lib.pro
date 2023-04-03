
TEMPLATE = lib

CONFIG += static
CONFIG += precompile_header 
CONFIG += qt
CONFIG += moc

CONFIG(debug, debug|release){
        DESTDIR = $$OUT_PWD/lib.debug
}
else{
        DESTDIR = $$OUT_PWD/lib
}

TARGET = yr-db-runtime-verif_FOR_YEROTH_ERP

QT += core
QT += gui
QT += widgets
QT += sql
QT += dbus
QT += network

MOC_DIR  = moc

OBJECTS_DIR = obj

PRECOMPILED_HEADER  = src/include/yr-db-runtime-verif-precompiled-header.hpp
 
HEADERS = src/utils/yr-db-runtime-verif-definition-format-date-time.hpp \
			src/DBUS/yr-db-runtime-verif-DBUS-CLIENT-ADAPTOR.h \
			src/yr-db-runtime-verif-interface.h \
			src/utils/yr-db-runtime-verif-logger.hpp \
			src/utils/yr-db-runtime-verif-sqltable-model.hpp \
		  src/utils/yr-db-runtime-verif-utils.hpp \
			src/utils/yr-db-runtime-verif-database-table-column.hpp

SOURCES = src/utils/yr-db-runtime-verif-definition-format-date-time.hpp \
			src/DBUS/yr-db-runtime-verif-DBUS-CLIENT-ADAPTOR.cpp \
			src/yr-db-runtime-verif-interface.cpp \
			src/utils/yr-db-runtime-verif-logger.cpp \
			src/utils/yr-db-runtime-verif-sqltable-model.cpp \
		  src/utils/yr-db-runtime-verif-utils.cpp \
			src/utils/yr-db-runtime-verif-database-table-column.cpp

