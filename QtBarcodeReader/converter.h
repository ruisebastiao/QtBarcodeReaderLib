#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QBasicTimer>
#include <QDebug>
#include <QImage>
#include <QTimerEvent>
#include "qtbarcodereader_global.h"
using namespace std;
using namespace cv;

class QTBARCODEREADERSHARED_EXPORT Converter : public QObject
{
    Q_OBJECT
    static void matDeleter(void* mat) { delete static_cast<cv::Mat*>(mat); }

public:
    explicit Converter(QObject *parent = 0);
    ~Converter();
    void process(cv::Mat frame);
    void setProcessAll(bool all);
private:
    QBasicTimer m_timer;
    cv::Mat m_frame;
    bool m_processAll;
    void queue(const cv::Mat &frame);
    //    void timerEvent(QTimerEvent *ev);
    void timerEvent(QTimerEvent *ev);
signals:
    void imageReady(const QImage &);
public slots:
    void processFrame(const cv::Mat & frame);
};

#endif // CONVERTER_H
