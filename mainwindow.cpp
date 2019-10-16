#include "mainwindow.h"
#include "smartwidget.h"

#include <iostream>
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

#include <QListWidget>
#include <QTreeWidget>

#include <QLabel>
#include <QMovie>
#include <QImage>
#include <QPixmap>

#include <QPainter>
#include <QPoint>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    init();
    testSmartWidget();
}

MainWindow::~MainWindow()
{

}
void MainWindow::testSmartWidget(){
   //测试自己封装的控件
    SmartWidget *smartWidget = new SmartWidget(this);
    //smartWidget->move(100, 100);
}
void MainWindow::init(){
    this->resize(800, 600);
    this->setWindowTitle("欢迎来到工具测试界面");
    this->setStyleSheet("MainWindow{background-color: rgb(53, 53, 53);color: rgb(255, 255, 255);}");

    if(false){
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

    //QListWidget用法
    if(false){
        QListWidget *listWidget = new QListWidget(this);
        listWidget->resize(100, 100);
        //单个加item
        QListWidgetItem * item = new QListWidgetItem("锄禾日当午");
        item->setTextAlignment(Qt::AlignHCenter);
        listWidget->addItem(item);

        //同时加多个item
        QStringList list;
        list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" << "粒粒皆辛苦";
        listWidget->addItems(list);
    }

    //QTreeWidget用法
    if(false){
        QTreeWidget *treeWidget = new QTreeWidget(this);
        treeWidget->resize(400, 400);
        treeWidget->move(10, 150);
        treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍");
        //QTreeWidget中每个项目成为QTreeWidgetItem
        QTreeWidgetItem * Litem = new QTreeWidgetItem(QStringList() << "力量");
        QTreeWidgetItem * Mitem = new QTreeWidgetItem(QStringList() << "敏捷");
        QTreeWidgetItem * Zitem = new QTreeWidgetItem(QStringList() << "智力");
        //添加根节点
        treeWidget->addTopLevelItem(Litem);
        treeWidget->addTopLevelItem(Mitem);
        treeWidget->addTopLevelItem(Zitem);
        QStringList heroL1;
        QStringList heroL2;
        QStringList heroL3;
        heroL1 << "刚被猪" << "前排坦克,鼻涕技能减速并造成魔法伤害";
        heroL2 << "船长" << "释放的幽灵船对直线上的英雄造成真实伤害";
        heroL3 << "沉默术士" << "全图英雄3秒内不能释放技能";
        //添加子节点
        QTreeWidgetItem *L1 = new QTreeWidgetItem(heroL1);
        Litem->addChild(L1);
        QTreeWidgetItem *L2 = new QTreeWidgetItem(heroL2);
        Mitem->addChild(L2);
        QTreeWidgetItem *L3 = new QTreeWidgetItem(heroL2);
        Zitem->addChild(L3);
    }
    if(false){
        //用label显示图片
        QLabel *pictureLabel = new QLabel(this);
        pictureLabel->resize(200, 200);
        pictureLabel->setFrameShape(QFrame::Box);       // 设置边框
        pictureLabel->setPixmap(QPixmap(":/images/User.png"));      //显示图片

        //用label显示动态图
        QLabel *gifLabe = new QLabel(this);
        gifLabe->resize(400, 400);
        gifLabe->move(10, 210);
        QMovie *movie = new QMovie(":/images/1.gif");
        gifLabe->setMovie(movie);
        movie->start();   //默认不播放，需要启动
    }

    if(true){

        std::vector<uchar> data;
        QImage *image = new QImage;
        image->load(":/images/carto_map.pgm");
        uchar * pData = image->bits();
        for(int i = 0; i < image->height(); ++i){
            for(int j = 0; j < image->width(); ++j){

                //qDebug()<< pData[i * image->height() + j];
                data.push_back(pData[i * image->height() + j]);
            }
            //qDebug() << "\n";
        }
        qDebug() << "width: " << image->width() << "height: " << image->height();
        QString sdata;
        for(int h = 0; h < image->height(); ++h){
            for(int w = 0; w < image->width(); ++w){
                sdata = sdata + " " + QString::number(data.at(h * image->height()  +w),10);
            }
            qDebug() << sdata.toUtf8().data();
        }
        QImage showImage = QImage(pData, image->width(), image->height(), QImage::Format_Indexed8);
        QLabel *showImageLabel = new QLabel(this);
        showImageLabel->setFrameShape(QFrame::Box);
        showImageLabel->resize(600, 400);
        showImageLabel->setPixmap(QPixmap::fromImage(showImage));
    }


}
