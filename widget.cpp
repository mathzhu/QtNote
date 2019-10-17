#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>

#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //利用时间过滤器 给label做高级时间拦截
    //步骤1.给label安装时间过滤器
    //步骤2.重写eventFilter时间
    ui->label->installEventFilter(this);

    //启动定时器
    id1 = startTimer(1000);//单位毫秒
    id2 = startTimer(2000);//每个两秒开启新的定时器


    //利用QTimerd定时器类 实现定时功能
    QTimer *timer = new QTimer(this);
    //启动定时器 单位毫秒
    timer->start(500);
    connect(timer, &QTimer::timeout, [=](){
        static int num = 1;
        ui->label_2->setText(QString::number(num++));
    });
    //点击暂停按钮停止计时
    connect(ui->stopBtn, &QPushButton::clicked, [=](){
        timer->stop();
    });


}

//利用定时器实现计时
void Widget::timerEvent(QTimerEvent *e){
    if(e->timerId() == id1){
        static int num1 = 1;
        ui->label_3->setText(QString::number(num1++));
    }
    if(e->timerId() == id2){
        static int num2 = 1;
        ui->label_4->setText(QString::number(num2++));
    }
}

Widget::~Widget()
{
    delete ui;
}

//事件过滤器
bool Widget::eventFilter(QObject *obj, QEvent *e){
    if(e->type() == QEvent::MouseButtonRelease){
        QMouseEvent *ev = static_cast<QMouseEvent*>(e);
        QString string = QString("x:%1 y:%2").arg(ev->x()).arg(ev->y());
        qDebug() << "in eventFilter" << string;
        return true; //代表如果是鼠标按下，用户自己处理
    }

    //默认处理
    return QWidget::eventFilter(obj, e);
}

void Widget::paintEvent(QPaintEvent *e){
    QPainter *painter = new QPainter(this);
    //画线
    painter->drawLine(0, 0, 100, 100);

    //画矩形
    painter->drawRect(100, 100, 30, 20);
    //画圆和椭圆
    painter->drawEllipse(QPoint(100, 100), 50, 50);
    //绘制文字
    painter->drawText(QRect(100, 200, 60, 80), "好好练剑");
    //设置画笔颜色
    painter->setPen(Qt::blue);
    //设置肢体格式
    painter->setFont(QFont("Arial", 30));
    painter->drawText(rect(), Qt::AlignCenter, "Qt");
}
