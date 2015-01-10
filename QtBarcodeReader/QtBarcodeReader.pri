
#QT       += multimedia

QT       -= gui

##TARGET = QtBarcodeReader
#TEMPLATE = lib

DEFINES += QTBARCODEREADER_LIBRARY

SOURCES += $$PWD/qtbarcodereader.cpp \
           $$PWD/QDecoder.cpp \
    $$PWD/converter.cpp \
    $$PWD/cameraimageviewer.cpp \
    $$PWD/CVcapture.cpp

HEADERS += $$PWD/qtbarcodereader.h\
        $$PWD/QDecoder.h \
        $$PWD/qtbarcodereader_global.h \
    $$PWD/converter.h \
    $$PWD/cameraimageviewer.h \
    $$PWD/CVcapture.h

INCLUDEPATH  += $$PWD

include($$PWD/../QZXing/QZXing.pri)
unix {
    LIBS += -L$$PWD/F:/OpenCV/VS2013/install/x86/vc12/bin/ -lopencv_core300
    target.path = /usr/lib
    INSTALLS += target
}

win32-msvc*{


CONFIG(release, debug|release){
 LIBS += -LF:/OpenCV/VS2013/install/x86/vc12/lib/ \
    -lopencv_core300 \
    -lopencv_video300 \
    -lopencv_imgproc300 \
    -lopencv_highgui300 \
    -lopencv_videoio300 \
    -lopencv_imgcodecs300

}
CONFIG(debug, debug|release){
 LIBS += -LF:/OpenCV/VS2013/install/x86/vc12/lib/ \
    -lopencv_core300d \
    -lopencv_video300d \
    -lopencv_imgproc300d \
    -lopencv_highgui300d \
    -lopencv_videoio300d \
    -lopencv_imgcodecs300d
#    DEFINES += QT_NO_DEBUG_OUTPUT
  #  DEFINES += QT_NO_DEBUG_STREAM
}
INCLUDEPATH += F:/OpenCV/VS2013/install/include

}

