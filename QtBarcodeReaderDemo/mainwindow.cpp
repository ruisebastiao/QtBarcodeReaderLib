#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cameraimageviewer.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    barcodereader=new QtBarcodeReader(this,ui->widget);
    connect(ui->start_bt,SIGNAL(clicked()),barcodereader,SLOT(StartCapture()));
    connect(ui->stop_bt,SIGNAL(clicked()),barcodereader,SLOT(StopCapture()));
    connect(barcodereader,SIGNAL(BarcodeDecodeStatus(BARCODESTATUS,QString)),this,SLOT(BarcodeDecodeStatus(BARCODESTATUS,QString)));
    noreadcount=0;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete barcodereader;
}


void MainWindow::BarcodeDecodeStatus(BARCODESTATUS Status,QString BarcodeReaded)
{
        switch (Status) {
        case BARCODEREADED:
             ui->lineEdit->setText(BarcodeReaded);
            break;
        default:
            if(noreadcount>10){
                noreadcount=0;
                ui->lineEdit->setText("NO READ");
            }
            noreadcount++;

            break;
        }

}

