#ifndef QTBARCODEREADER_H
#define QTBARCODEREADER_H

#include "qtbarcodereader_global.h"
#include <QCamera>
#include <QCameraImageCapture>
#include <QActionEvent>
#include <QCameraViewfinder>
#include <QPixmap>
#include <qzxing.h>
#include <QDecoder.h>
#include <QMediaRecorder>

class QTBARCODEREADERSHARED_EXPORT QtBarcodeReader: public QObject
{
 Q_OBJECT
public:
    QtBarcodeReader(QObject *parent = 0);
    ~QtBarcodeReader();
    void configureImageSettings();
    void toggleLock();

    void getImage();
    void configureVideoSettings();
private:
    QCamera *camera;
    QCameraImageCapture *imageCapture;

    QImageEncoderSettings imageSettings;
    QVideoEncoderSettings videoSettings;
    QString videoContainerFormat;
    bool isCapturingImage;
    QCameraViewfinder *viewFinder ;
    QBarcodeDecoder *BarcodeDecoder;



    QMediaRecorder* mediaRecorder;

private slots:
    void setCamera(const QCameraInfo &cameraInfo);

    void startCamera();
    void stopCamera();

    void takeImage();

    void displayCaptureError(int, QCameraImageCapture::Error, const QString &errorString);
    void configureCaptureSettings();

    void displayCameraError();

    void updateCameraDevice(QAction *action);

    void updateCameraState(QCamera::State);
    void updateCaptureMode();

   // void setExposureCompensation(int index);


    void processCapturedImage(int requestId, const QImage &img);
    //void updateLockStatus(QCamera::LockStatus, QCamera::LockChangeReason);

    void readyForCapture(bool ready);
    //    void imageSaved(int id, const QString &fileName);
    void imageSaved(int id, const QString &fileName);
};

#endif // QTBARCODEREADER_H
