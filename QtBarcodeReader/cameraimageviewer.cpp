#include "cameraimageviewer.h"
#include "QPainter"

CameraImageViewer::CameraImageViewer(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_OpaquePaintEvent);
}

CameraImageViewer::~CameraImageViewer()
{

}

void CameraImageViewer::setImage(const QImage & img) {
        if (!m_img.isNull()) qDebug() << "Viewer dropped frame!";
        m_img = img;
        if (m_img.size() != size()) setFixedSize(m_img.size());
        update();
    }

void CameraImageViewer::paintEvent(QPaintEvent *) {
        QPainter p(this);
        p.drawImage(0, 0, m_img);
        m_img = QImage();
}
