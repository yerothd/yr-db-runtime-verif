

CONFIG += debug
CONFIG += precompile_header 
CONFIG += qt
CONFIG += console
CONFIG += moc

CONFIG -= import_plugins

QT += widgets
QT += sql
QT += dbus
QT += network

VERSION = 3.0

QMAKE_CXXFLAGS_RELEASE -= -O2
#QMAKE_CXXFLAGS_RELEASE += --coverage
#QMAKE_CXXFLAGS_RELEASE += -Wunused-parameter

QMAKE_CFLAGS_RELEASE -= -O2

DESTDIR = bin

MOC_DIR  = moc

OBJECTS_DIR = obj

PRECOMPILED_HEADER  = src/include/yr-db-runtime-verif-precompiled-header.hpp
 
DBUS_ADAPTORS += yr.db-runtime.verif.xml


FORMS = ui/yr-db-runtime-verif-main-window.ui


HEADERS = src/windows/yr-db-runtime-verif-windows.hpp \
			src/windows/yr-db-runtime-verif-main-window.hpp \
			src/include/yr-db-runtime-verif-MONITOR.hpp \
			src/include/yr-db-runtime-verif-definition-oo-class-operators.hpp \
			src/utils/yr-db-runtime-verif-definition-format-date-time.hpp \
			src/include/yr-db-runtime-verif-software-text-configuration.hpp \
			src/DBUS/YR_DBUS_COMMON.hpp \
			src/utils/yr-db-runtime-verif-logger.hpp \
			src/utils/yr-db-runtime-verif-sqltable-model.hpp \
		  src/utils/yr-db-runtime-verif-utils.hpp \
			src/utils/yr-db-runtime-verif-database-table-column.hpp \
			src/yr-db-runtime-verif-main.hpp \
		  src/yr-db-runtime-verif-database.hpp \
		  src/yr-db-runtime-verif-config.hpp 
 
SOURCES = src/windows/yr-db-runtime-verif-windows.cpp \
			src/windows/yr-db-runtime-verif-main-window.cpp \
			src/include/yr-db-runtime-verif-MONITOR.cpp \
		  src/yr-db-runtime-verif.cpp \
			src/DBUS/YR_DBUS_COMMON.cpp \
			src/utils/yr-db-runtime-verif-logger.cpp \
			src/utils/yr-db-runtime-verif-sqltable-model.cpp \
			src/utils/yr-db-runtime-verif-utils.cpp \
			src/utils/yr-db-runtime-verif-database-table-column.cpp \
			src/yr-db-runtime-verif-main.cpp \
		  src/yr-db-runtime-verif-database.cpp \
		  src/yr-db-runtime-verif-config.cpp 


RESOURCES    = yr-db-runtime-verif.qrc


#link static libraries
LIBS += -L$$PWD/lib_SD -lyr_sd_runtime_verif


# install
target.path = yr-db-runtime-verif
sources.files = $$SOURCES $$HEADERS *.pro
sources.path = .
INSTALLS += target sources
