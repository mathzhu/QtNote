#ifndef SMARTWIDGET_H
#define SMARTWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QSpinBox>

class SmartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SmartWidget(QWidget *parent = nullptr);
private:
    void initSmartWidget();
    QSpinBox *spinBox;
    QSlider *slider;
signals:

public slots:
    void setSlider(int);
    void setSpinBoxValue(int);
};

#endif // SMARTWIDGET_H
