#ifndef CAPTURE_H
#define CAPTURE_H

#include <QObject>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QBasicTimer>
#include <QTimerEvent>
#include "qtbarcodereader_global.h"
using namespace std;
using namespace cv;



class QTBARCODEREADERSHARED_EXPORT Capture : public QObject
{
    Q_OBJECT
    static void matDeleter(void* mat) { delete static_cast<cv::Mat*>(mat); }
public:
    explicit Capture(QObject *parent = 0);
    ~Capture();


private:
    QBasicTimer m_timer;
    QScopedPointer<cv::VideoCapture> m_videoCapture;

signals:
    void image_ready(const QImage &);
    void started();
    void matReady(const cv::Mat &);
public slots:
    void start(int cam=0);
    void stop();

    // QObject interface
protected:


    // QObject interface
protected:
    void timerEvent(QTimerEvent *);
};

#endif // CAPTURE_H
