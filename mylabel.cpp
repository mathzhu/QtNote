#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
#include <QEvent>
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标状态追踪
    this->setMouseTracking(true);
}
void MyLabel::mouseMoveEvent(QMouseEvent *ev){
    //鼠标左键按下移动才触发，移动是个过程，所以需要用&
//    if(ev->buttons() & Qt::LeftButton){
//        QString string = QString("x:%1 y:%2").arg(ev->x()).arg(ev->y());
//        qDebug() << "in move" << string;
//    }

    QString string = QString("x:%1 y:%2").arg(ev->x()).arg(ev->y());
    qDebug() << "in move" << string;


}
void MyLabel::mousePressEvent(QMouseEvent *ev){
    //按下时瞬间，用==判断
    if(ev->button() == Qt::LeftButton){
        QString string = QString("x:%1 y:%2").arg(ev->x()).arg(ev->y());
        qDebug() << "in press" << string;
    }



}
void MyLabel::mouseReleaseEvent(QMouseEvent *ev){
    QString string = QString("x:%1 y:%2").arg(ev->x()).arg(ev->y());
    qDebug() << "in release" << string;
}

//如果是用户想在事件分发前捕获事件，不向下分发，可以return true代表自己定义处理
bool MyLabel::event(QEvent *e){
    if(e->type() == QEvent::MouseButtonPress){
        QMouseEvent *ev = static_cast<QMouseEvent*>(e);
        QString string = QString("x:%1 y:%2").arg(ev->x()).arg(ev->y());
        qDebug() << "in event" << string;
        return true; //代表如果是鼠标按下，用户自己处理
    }
    //其他时间交个父类 默认处理
    return QLabel::event(e);
}
