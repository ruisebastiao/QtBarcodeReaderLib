#-------------------------------------------------
#
# Project created by QtCreator 2015-01-06T17:02:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimediawidgets

TARGET = QtbarcodeReaderDemo
TEMPLATE = app



unix {
    LIBS += -L$$PWD/F:/OpenCV/VS2013/install/x86/vc12/bin/ -lopencv_core300
    target.path = /usr/lib
    INSTALLS += target
    include($HOME/Github/QtBarcodeReaderLib/QtBarcodeReader/QtBarcodeReader.pri)
}

win32-msvc*{
include(C:/Users/automacao/Documents/GitHub/QtBarcodeReaderLib/QtBarcodeReader/QtBarcodeReader.pri)

}


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui



