#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qtbarcodereader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void BarcodeDecodeStatus(BARCODESTATUS,QString);

private:
    int noreadcount;
    Ui::MainWindow *ui;
    QtBarcodeReader *barcodereader;
};

#endif // MAINWINDOW_H
