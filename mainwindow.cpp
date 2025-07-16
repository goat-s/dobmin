#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "svgdocument.h"
#include "workspace.h"
#include "zoomadjust.h"
#include "map.h"
//#include <private/qsvggraphics_p.h>
//#include <private/qsvgstructure_p.h>
#include <qtmaterialdrawer.h>
#include <QTextDocument>
#include <QTimer>
#include "leftbar.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)// 创建UI对象
{
    ui->setupUi(this); // 设置UI界面

    this->setWindowTitle("WorkXP"); // 设置窗口标题

    leftbar* m_leftbar = new leftbar(this);
    ui->leftBar->addWidget(m_leftbar);
//    ui->verticalLayout_2->addWidget(m_leftbar);

    // 只需连接一次信号，解耦具体按钮
    connect(m_leftbar, &leftbar::toolChanged, ui->workspace, &Workspace::setToolMode);

    // 连接 carButton 点击进入画小车模式
    connect(m_leftbar->findChild<QToolButton*>("carButton"), &QToolButton::clicked, this, [=]() {
        ui->workspace->setDrawCarMode(true);
    });
    // 连接 curserButton 点击退出画小车模式
    connect(m_leftbar->findChild<QToolButton*>("curserButton"), &QToolButton::clicked, this, [=]() {
        ui->workspace->setDrawCarMode(false);
    });

    connect(ui->zoomPart, &ZoomAdjust::factorChanged,
            ui->workspace, [w = ui->workspace](int p){ w->setZoomPercent(p); });
    // 连接缩放调整部件的缩放到适合大小信号
    connect(ui->zoomPart, &ZoomAdjust::zoomToFit, ui->workspace, &Workspace::zoomToFit);

    // 连接工作区的缩放改变信号
    connect(ui->workspace, &Workspace::scaled,
            this, [=](){
                double cur   = ui->workspace->transform().m11();
                int    pct   = qRound(100 * cur / ui->workspace->baseScale());
                ui->zoomPart->setFactor(pct, /*emitSignal=*/false);
    });
//    ui->workspace->setDragMode(QGraphicsView::NoDrag);
    // QTimer::singleShot(0, this, [this]{         //手动设置初始比例为150%，取消自适应
    //        ui->workspace->zoomToFit();        // ← 第一次真正按窗口大小自适应
    //    });
    //ui->workspace->zoomToFit(); // 工作区缩放到适合大小
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
   ui->workspace->init();
   qDebug() << "dragMode =" << ui->workspace->dragMode();


}

