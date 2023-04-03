
QMAKE_CXXFLAGS += -Wno-unused-variable -Wno-unused-parameter -Wno-misleading-indentation
QMAKE_CXXFLAGS += -isystem


# common config
QT += core gui widgets xml opengl network printsupport svg


# output
CONFIG(debug, debug|release){
    LIBS += -L$$OUT_PWD/../lib.debug
}
else{
    LIBS += -L$$OUT_PWD/../lib
}

# temp dirs (unix)
unix{
    MOC_DIR = $$OUT_PWD/_generated
    OBJECTS_DIR = $$OUT_PWD/_generated
    UI_DIR = $$OUT_PWD/_generated
    RCC_DIR = $$OUT_PWD/_generated
}
