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


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)// 创建UI对象
{
    ui->setupUi(this); // 设置UI界面

    this->setWindowTitle("WorkXP"); // 设置窗口标题
    //加入地图页面
    Map* map = new Map();
    ui->leftBar->addWidget(map);

//    ui->QtableWidget->insertTab(0, map, "地图与控制");
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

