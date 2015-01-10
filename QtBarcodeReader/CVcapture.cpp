#include "CVcapture.h"


Q_DECLARE_METATYPE(cv::Mat)

CVCapture::CVCapture(QObject *parent) : QObject(parent)
{
 //m_timer.
}

CVCapture::~CVCapture()
{

}
void CVCapture::stop() {
    m_timer.stop();
}

void CVCapture::timerEvent(QTimerEvent * ev) {
        if (ev->timerId() != m_timer.timerId()) return;
        cv::Mat frame;
        if (!m_videoCapture->read(frame)) { // Blocks until a new frame is ready
            m_timer.stop();
            return;
        }
        emit matReady(frame);
    }


void CVCapture::start(int cam) {
        if (!m_videoCapture)
            m_videoCapture.reset(new cv::VideoCapture(cam));


        m_videoCapture->set(CV_CAP_PROP_FRAME_WIDTH,640);
        m_videoCapture->set(CV_CAP_PROP_FRAME_HEIGHT,480);


        if (m_videoCapture->isOpened()) {
            m_timer.start(100, this);
            emit started();
        }
 }
