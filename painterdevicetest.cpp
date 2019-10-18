#include "painterdevicetest.h"
#include "ui_painterdevicetest.h"
#include <QPainter>
#include <QPicture>
#include <QPushButton>
#include <QTimer>

PainterDeviceTest::PainterDeviceTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PainterDeviceTest)
{
    ui->setupUi(this);
    posX = 10;
    //painterPixMapTest();
    //painterImageTest();
    //painterPictureTest();

    //点击按钮实现图片移动
//    connect(ui->moveBtn, &QPushButton::clicked, [=](){
//        posX += 20;
//        update();
//    });

    //利用定时器自动移动图片
    QTimer *timer = new QTimer(this);
    timer->start(100);
    connect(timer, &QTimer::timeout, [=](){
        posX += 20;
        update();   //手动调用paintEvent绘图事件
    });
}

PainterDeviceTest::~PainterDeviceTest()
{
    delete ui;
}

void PainterDeviceTest::painterPixMapTest(){
    //QPixmap做绘图设备
    //对不同平台做显示优化
    QPixmap pix(300, 300);
    pix.fill(Qt::white);    //填充背景色
    QPainter painter(&pix);
    painter.setPen(QPen(Qt::red));
    painter.drawEllipse(150, 150, 100, 100);
    //保存
    pix.save("D:\\pix.png");
}

void PainterDeviceTest::painterImageTest(){
    //QImage做绘图设备
    //可以对像素进行访问
    QImage img(300, 300, QImage::Format_RGB32);
    img.fill(Qt::white);

    QPainter painter(&img);
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(150, 150, 100, 100);
    img.save("D:\\imag.png");
}
void PainterDeviceTest::painterPictureTest(){
    //QPicture坐绘图设备
    //可以额记录和重现QPainter的各条指令
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(QPen(Qt::blue));
    painter.drawEllipse(150, 150, 100, 100);
    painter.end();
    pic.save("D:\\pic.zyp");
}

void PainterDeviceTest::paintEvent(QPaintEvent *){

    //测试对image中像素点读写
//    QImage img;
//    img.load(":/images/leida.png");
//    QPainter painter(this);
//    for(int i = 50; i < 100; i++){
//        for(int j = 50; j < 100; j++){
//            QRgb value = qRgb(255, 0, 0);
//            img.setPixel(i, j, value);
//        }
//    }
//    painter.drawImage(0, 0, img);

    //测试QPicture重现指令
    //重现 QPicture的绘图指令
//    QPainter painter(this);
//    QPicture pic;
//    pic.load("D:\\pic.zyp");
//    painter.drawPicture(0, 0, pic);
    QPainter painter(this);
    if(posX > this->width())
        posX = 10;
    painter.drawPixmap(posX, 100, QPixmap(":/images/save.png"));

}
