#-------------------------------------------------
#
# Project created by QtCreator 2015-01-06T15:17:41
#
#-------------------------------------------------

QT       += multimedia

QT       -= gui

TARGET = QtBarcodeReader
TEMPLATE = lib

DEFINES += QTBARCODEREADER_LIBRARY

SOURCES += qtbarcodereader.cpp

HEADERS += qtbarcodereader.h\
        qtbarcodereader_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
