#ifndef MYLABEL_H
#define MYLABEL_H
/*
1.新建一个c++class类，命名为MyLabel,基类选择QWidget
2.MyLabe.h #include <QLabel>改为#include <QWidget>，public QWidget改为public QLabel
  MyLabe.cpp构造函数:QWidget(parent)改为QLabel(parent)
3.在ui界面拖动一个QLabel控件，右击-》提升为->基类选QLabel，提升的类名为MyLabel(如果类名错误，提升不成功)->添加->提升不成功
*/
#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    bool event(QEvent *e) override;



signals:

public slots:
};

#endif // MYLABEL_H
