#ifndef CAMERAIMAGEVIEWER_H
#define CAMERAIMAGEVIEWER_H

#include <QWidget>
#include <QDebug>
#include "qtbarcodereader_global.h"

class QTBARCODEREADERSHARED_EXPORT CameraImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit CameraImageViewer(QWidget *parent = 0);
    ~CameraImageViewer();

private:
    QImage m_img;
signals:

public slots:
    void setImage(const QImage &img);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);
};

#endif // CAMERAIMAGEVIEWER_H
