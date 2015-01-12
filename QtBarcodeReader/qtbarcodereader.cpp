#include "qtbarcodereader.h"
#include <opencv2/objdetect/objdetect.hpp>


Q_DECLARE_METATYPE(cv::Mat)


QtBarcodeReader::QtBarcodeReader(QObject *parent,QWidget *viewer) :
    QObject(parent)
{
    qRegisterMetaType<cv::Mat>("cv::Mat");
    converter.setProcessAll(false);    
    cvcapture= new CVCapture();
    converter.connect(cvcapture, SIGNAL(matReady(cv::Mat)), SLOT(processFrame(cv::Mat)));
    BarcodeDecoder.connect(&converter, SIGNAL(imageReady(QImage)), SLOT(decodeImage(QImage)));
    connect(&BarcodeDecoder,SIGNAL(BarcodeDecodeStatus(BARCODESTATUS,QString)),this, SLOT(NewBarcodeDecodeStatus(BARCODESTATUS,QString)));

    if (viewer!=0) {
        viewer->connect(&converter, SIGNAL(imageReady(QImage)), SLOT(setImage(QImage)));
    }



}

void QtBarcodeReader::NewBarcodeDecodeStatus(BARCODESTATUS Status, QString Barcode){
    emit BarcodeDecodeStatus(Status,Barcode);
}

QtBarcodeReader::~QtBarcodeReader()
{

    StopCapture();

    delete cvcapture;
}


void QtBarcodeReader::StartCapture(){
    captureThread.start();
    converterThread.start();
    cvcapture->moveToThread(&captureThread);
    converter.moveToThread(&converterThread);
    QMetaObject::invokeMethod(cvcapture, "start");
}


void QtBarcodeReader::StopCapture(){
    captureThread.quit();
    converterThread.quit();
    captureThread.wait();
    converterThread.wait();
}
