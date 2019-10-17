#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    bool eventFilter(QObject *obj, QEvent *e) override;
    void timerEvent(QTimerEvent *e) override;
    void paintEvent(QPaintEvent *) override;

private:
    Ui::Widget *ui;
    int id1;
    int id2;
};

#endif // WIDGET_H
