#ifndef PAINTERDEVICETEST_H
#define PAINTERDEVICETEST_H

#include <QWidget>

namespace Ui {
class PainterDeviceTest;
}

class PainterDeviceTest : public QWidget
{
    Q_OBJECT

public:
    explicit PainterDeviceTest(QWidget *parent = nullptr);
    ~PainterDeviceTest();
    void painterPixMapTest();
    void painterImageTest();
    void painterPictureTest();
    void paintEvent(QPaintEvent *);
private:
    Ui::PainterDeviceTest *ui;
    int posX;
};

#endif // PAINTERDEVICETEST_H
