#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int GetWidth(MainWindow window);
    int GetHeight(MainWindow window);

    int shirina;
    int visota;
    void load();
    QPixmap pix;
    void ImageData();

private slots:
        void Negative();
        void Greyscale();
        void Sepia();

private:
    Ui::MainWindow *ui;
    QImage *image = new QImage;
};

#endif // MAINWINDOW_H
