#ifndef QTBARCODEREADER_H
#define QTBARCODEREADER_H

#include "qtbarcodereader_global.h"
#include <QPixmap>
#include <qzxing.h>
#include <QDecoder.h>
#include <capture.h>
#include <converter.h>
#include <QWidget>
#include <QDecoder.h>


class QTBARCODEREADERSHARED_EXPORT QtBarcodeReader: public QObject
{
 Q_OBJECT
public:
    QtBarcodeReader(QObject *parent = 0,QWidget *viewer=0);
    ~QtBarcodeReader();


private:
    Capture capture;
      Converter converter;
      QThread captureThread, converterThread;
protected:
    QBarcodeDecoder BarcodeDecoder;

private slots:

};

#endif // QTBARCODEREADER_H
