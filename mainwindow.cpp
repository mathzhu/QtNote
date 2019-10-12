#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

#include <QDialog>
#include <QDebug>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
}

MainWindow::~MainWindow()
{

}

void MainWindow::init(){
    this->resize(600, 400);
    this->setWindowTitle("欢迎来到工具测试界面");
    this->setStyleSheet("MainWindow{background-color: rgb(53, 53, 53);color: rgb(255, 255, 255);}");

    //菜单栏只有一个
    QMenuBar * bar = new QMenuBar();
    //将菜单栏设置到窗口中
    setMenuBar(bar);

    //添加菜单
    QMenu * fileMenu = bar->addMenu("文件");
    QMenu * editMenu = bar->addMenu("编辑");
    //添加菜单项
    QAction *newAction = fileMenu->addAction("新建");
    newAction->setIcon(QIcon(":/images/about.png"));
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("打开");

    //工具栏 可以有多个
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar);

    //只允许上下停靠
    //toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置浮动
    //toolBar->setFloatable(false);
    //设置移动(总开关)
    //toolBar->setMovable(false);


    //工具栏中添加小空间
    QPushButton * btn = new QPushButton("按钮", this);
    toolBar->addWidget(btn);

    //工具栏中添加菜单项
    toolBar->addAction(newAction);
    //添加分割线
    toolBar->addSeparator();
    toolBar->addAction(openAction);



    //状态栏 只有一个
    QStatusBar *status = statusBar();
    //将状态栏放入到窗口中
    setStatusBar(status);
    //放入标签
    QLabel *label = new QLabel("左侧信息", this);
    status->addWidget(label);
    QLabel *label2 = new QLabel("右侧信息", this);
    status->addPermanentWidget(label2);

    //铆接部件 浮动窗口 可以有多个
    QDockWidget *dock = new QDockWidget("浮动窗口", this);
    addDockWidget(Qt::BottomDockWidgetArea, dock);
    //设置停靠范围，位置是相对核心部件的位置
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    //核心部件 只能有一个
    QTextEdit  *edit = new QTextEdit(this);
    setCentralWidget(edit);

    connect(newAction, &QAction::triggered, [=](){
        //模态对话框 不可对其他窗口进行操作
//        QDialog dlg(this);
//        dlg.exec();     //阻塞，关闭后才会往下执行
//        qDebug() << "模态对话框";
        //非模态对话框 可以对其他窗口进行操作
        //QDialog dlg2(this);  //栈上对象结束会自动释放，所以一闪而过，需要堆上new出来
        QDialog *dlg2 = new QDialog(this);      //只是添加到了对象树上，点击关闭后并不会释放，只有程序结束才会释放对象树上的对象，所以一直开关会导致内存泄露
        dlg2->show();
        dlg2->setAttribute(Qt::WA_DeleteOnClose);   //55号，设置点击关闭后释放对象
    });


    //QMessageBox对话框测试
    connect(openAction, &QAction::triggered, [=](){
        int ret = QMessageBox::information(nullptr, "信息", "端口有误，请从新输入",QMessageBox::Save | QMessageBox::Cancel);
        if(ret == QMessageBox::Save)
            qDebug() << "you choose save";
        if(ret == QMessageBox::Cancel)
            qDebug() << "you choose cancel";
        qDebug() << "ret:" << ret;
    });

}
