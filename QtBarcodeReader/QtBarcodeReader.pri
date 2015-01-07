
QT       += multimedia

QT       -= gui

##TARGET = QtBarcodeReader
#TEMPLATE = lib

DEFINES += QTBARCODEREADER_LIBRARY

SOURCES += $$PWD/qtbarcodereader.cpp \
           $$PWD/QDecoder.cpp

HEADERS += $$PWD/qtbarcodereader.h\
        $$PWD/QDecoder.h \
        $$PWD/qtbarcodereader_global.h

INCLUDEPATH  += $$PWD

include(C:/Users/automacao/Downloads/QZXing_sourceV2.3/QZXing.pri)
unix {
    target.path = /usr/lib
    INSTALLS += target
}
