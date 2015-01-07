#include "qtbarcodereader.h"
#include <QCameraInfo>

#include <QMediaService>
#include <QMediaRecorder>
#include <QCameraViewfinder>
#include <QCameraInfo>
#include <QMediaMetaData>


Q_DECLARE_METATYPE(QCameraInfo)

QtBarcodeReader::QtBarcodeReader(QObject *parent) :
    QObject(parent),
    camera(0),
    imageCapture(0),
    isCapturingImage(false)
{
    BarcodeDecoder= new QBarcodeDecoder(this);
 setCamera(QCameraInfo::defaultCamera());

}



QtBarcodeReader::~QtBarcodeReader()
{
    delete BarcodeDecoder;
    delete imageCapture;
    delete camera;
}

void QtBarcodeReader::configureImageSettings()
{

    imageSettings=imageCapture->encodingSettings();
    imageSettings.setCodec("image/bmp");
    imageSettings.setResolution(640,480);
    imageSettings.setQuality(QMultimedia::HighQuality);

    //QSize res=imageSettings.resolution();
    //QCameraImageCapture::se
    imageCapture->setEncodingSettings(imageSettings);

    imageSettings=imageCapture->encodingSettings();
    qDebug() << imageSettings.resolution();
    //imageCapture->set

}



void QtBarcodeReader::setCamera(const QCameraInfo &cameraInfo)
{
    delete imageCapture;

    delete camera;

    camera = new QCamera(cameraInfo);

    connect(camera, SIGNAL(stateChanged(QCamera::State)), this, SLOT(updateCameraState(QCamera::State)));
    connect(camera, SIGNAL(error(QCamera::Error)), this, SLOT(displayCameraError()));

   viewFinder = new QCameraViewfinder();
    //viewFinder->set
    camera->setViewfinder(viewFinder);

    imageCapture = new QCameraImageCapture(camera);


    updateCameraState(camera->state());


    connect(imageCapture, SIGNAL(readyForCaptureChanged(bool)), this, SLOT(readyForCapture(bool)));
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(processCapturedImage(int,QImage)));
    connect(imageCapture, SIGNAL(imageSaved(int,QString)), this, SLOT(imageSaved(int,QString)));
    connect(imageCapture, SIGNAL(error(int,QCameraImageCapture::Error,QString)), this,
            SLOT(displayCaptureError(int,QCameraImageCapture::Error,QString)));

//    connect(camera, SIGNAL(lockStatusChanged(QCamera::LockStatus,QCamera::LockChangeReason)),
//            this, SLOT(updateLockStatus(QCamera::LockStatus,QCamera::LockChangeReason)));

    //ui->captureWidget->setTabEnabled(0, (camera->isCaptureModeSupported(QCamera::CaptureStillImage)));
    //ui->captureWidget->setTabEnabled(1, (camera->isCaptureModeSupported(QCamera::CaptureVideo)));

    updateCaptureMode();
    configureImageSettings();

    viewFinder->show();
    camera->start();
}

void QtBarcodeReader::imageSaved(int id, const QString &fileName)
{
    Q_UNUSED(id);
    Q_UNUSED(fileName);

    isCapturingImage = false;

}

void QtBarcodeReader::getImage(){
    takeImage();
}

void QtBarcodeReader::processCapturedImage(int requestId, const QImage& img)
{
    Q_UNUSED(requestId);

//QTimer::singleShot(4000, this, SLOT(displayViewfinder()));
    BarcodeDecoder->decodeImage(img);
//    QImage scaledImage = img.scaled(ui->viewfinder->size(),
//                                    Qt::KeepAspectRatio,
//                                    Qt::SmoothTransformation);

//    ui->lastImagePreviewLabel->setPixmap(QPixmap::fromImage(scaledImage));

//    // Display captured image for 4 seconds.
//    displayCapturedImage();
//    QTimer::singleShot(4000, this, SLOT(displayViewfinder()));
}

void QtBarcodeReader::configureCaptureSettings()
{
//    switch (camera->captureMode()) {
//    case QCamera::CaptureStillImage:
//        configureImageSettings();
//        break;
//    case QCamera::CaptureVideo:
//        configureVideoSettings();
//        break;
//    default:
//        break;
//    }
}



void QtBarcodeReader::toggleLock()
{
    switch (camera->lockStatus()) {
    case QCamera::Searching:
    case QCamera::Locked:
        camera->unlock();
        break;
    case QCamera::Unlocked:
        camera->searchAndLock();
    }
}

//void QtBarcodeReader::updateLockStatus(QCamera::LockStatus status, QCamera::LockChangeReason reason)
//{
//    QColor indicationColor = Qt::black;

//    switch (status) {
//    case QCamera::Searching:
//        indicationColor = Qt::yellow;
//        ui->statusbar->showMessage(tr("Focusing..."));
//        ui->lockButton->setText(tr("Focusing..."));
//        break;
//    case QCamera::Locked:
//        indicationColor = Qt::darkGreen;
//        ui->lockButton->setText(tr("Unlock"));
//        ui->statusbar->showMessage(tr("Focused"), 2000);
//        break;
//    case QCamera::Unlocked:
//        indicationColor = reason == QCamera::LockFailed ? Qt::red : Qt::black;
//        ui->lockButton->setText(tr("Focus"));
//        if (reason == QCamera::LockFailed)
//            ui->statusbar->showMessage(tr("Focus Failed"), 2000);
//    }

//    QPalette palette = ui->lockButton->palette();
//    palette.setColor(QPalette::ButtonText, indicationColor);
//    ui->lockButton->setPalette(palette);
//}

void QtBarcodeReader::takeImage()
{
    isCapturingImage = true;
   // if (imageCapture->isReadyForCapture()) {
        imageCapture->capture("e:\\img.bmp");

   // }

}

void QtBarcodeReader::displayCaptureError(int id, const QCameraImageCapture::Error error, const QString &errorString)
{
    Q_UNUSED(id);
    Q_UNUSED(error);
    //QMessageBox::warning(this, tr("Image Capture Error"), errorString);
    isCapturingImage = false;
}

void QtBarcodeReader::startCamera()
{
    camera->start();
}

void QtBarcodeReader::stopCamera()
{
    camera->stop();
}

void QtBarcodeReader::updateCaptureMode()
{
//    int tabIndex = ui->captureWidget->currentIndex();
    QCamera::CaptureModes captureMode = QCamera::CaptureStillImage;

    if (camera->isCaptureModeSupported(captureMode))
        camera->setCaptureMode(captureMode);
}

void QtBarcodeReader::updateCameraState(QCamera::State state)
{
//    switch (state) {
//    case QCamera::ActiveState:
//        ui->actionStartCamera->setEnabled(false);
//        ui->actionStopCamera->setEnabled(true);
//        ui->captureWidget->setEnabled(true);
//        ui->actionSettings->setEnabled(true);
//        break;
//    case QCamera::UnloadedState:
//    case QCamera::LoadedState:
//        ui->actionStartCamera->setEnabled(true);
//        ui->actionStopCamera->setEnabled(false);
//        ui->captureWidget->setEnabled(false);
//        ui->actionSettings->setEnabled(false);
//    }
}


//void QtBarcodeReader::setExposureCompensation(int index)
//{
//    camera->exposure()->setExposureCompensation(index*0.5);
//}


void QtBarcodeReader::displayCameraError()
{
  //  QMessageBox::warning(this, tr("Camera error"), camera->errorString());
    if (true) {

    }
}

void QtBarcodeReader::updateCameraDevice(QAction *action)
{
  //  setCamera(qvariant_cast<QCameraInfo>(action->data()));
}


void QtBarcodeReader::readyForCapture(bool ready)
{
    //ui->takeImageButton->setEnabled(ready);
}


