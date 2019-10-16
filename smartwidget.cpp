#include "smartwidget.h"
#include <QHBoxLayout>
#include <QDebug>
/*
 * 自定义封装控件:spinbox和slider增加减少，另一个控件相应跟着变化
 *
*/
SmartWidget::SmartWidget(QWidget *parent) : QWidget(parent)
{
    initSmartWidget();
}

void SmartWidget::initSmartWidget(){
    this->resize(395, 107);

    spinBox = new QSpinBox;
    spinBox->resize(46, 23);
    spinBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed); //设置水平和垂直策略
    slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);  //设置方向
    slider->resize(277, 15);
    slider->move(53, 5);
    slider->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    this->setLayout(layout);
    QObject::connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(setSlider(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setSpinBoxValue(int)));
}
void SmartWidget::setSlider(int value){
    qDebug() << "111111" << value;
    slider->setValue(value);
}
void SmartWidget::setSpinBoxValue(int value){
    spinBox->setValue(value);
}
