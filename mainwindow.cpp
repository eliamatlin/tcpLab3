#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   load();

QObject::connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(Negative()));
QObject::connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(Greyscale()));
QObject::connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(Sepia()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load()
{

    pix.load("/Users/ilyakulguskin/Documents/Education/Session 4/Materials/TCP/lab3/landscape.jpg");
    ui->label->setPixmap(pix.scaled(500, 500 , Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::ImageData()
{
    *image = pix.toImage();
    shirina = image->width();
    visota = image->height();
}

void MainWindow::Negative()//Negative
{
    ImageData();
    for (int x=0; x<shirina; x++) {
        for(int y=0; y<visota; y++)
        {
            QRgb a = image->pixel(x,y);
            image->setPixel(x,y,qRgb(255-qRed(a),255-qGreen(a),255-qBlue(a)));
        }
    }
    pix.convertFromImage(*image, 0);
    ui->label->setPixmap(pix.scaled(500, 500 , Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::Greyscale()
{
    ImageData();
    for (int x=0; x<shirina; x++) {
        for(int y=0; y<visota; y++)
        {
            QRgb a = image->pixel(x,y);
            QRgb color = (qRed(a)+qGreen(a)+qBlue(a))/3;
            image->setPixel(x,y,qRgb(color,color,color));
        }
    }
    pix.convertFromImage(*image, 0);
    ui->label->setPixmap(pix.scaled(500, 500 , Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::Sepia()
{
    ImageData();
    for (int x=0; x<shirina; x++) {
        for(int y=0; y<visota; y++)
        {
            QRgb a = image->pixel(x,y);
            QRgb tr = 0.393*qRed(a) + 0.769*qGreen(a) + 0.189*qBlue(a);
            QRgb tg = 0.349*qRed(a) + 0.686*qGreen(a) + 0.168*qBlue(a);
            QRgb tb = 0.272*qRed(a) + 0.534*qGreen(a) + 0.131*qBlue(a);

            if (tr>255) tr = 255;
            if (tg>255) tg = 255;
            if (tb>255) tb = 255;

            image->setPixel(x,y,qRgb(tr, tg, tb));
        }
    }
    pix.convertFromImage(*image, 0);
    ui->label->setPixmap(pix.scaled(500, 500 , Qt::KeepAspectRatio, Qt::SmoothTransformation));
}
