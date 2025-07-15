#include "workspace.h"  // 包含Workspace类的头文件
#include <QCommonStyle>  // Qt通用样式类
#include <QScrollBar>     // Qt滚动条组件
#include "rulebar.h"       // 标尺栏类
#include <QDebug>         // Qt调试输出
#include <QWheelEvent>    // Qt滚轮事件
#include <QTimer>         //新增：当滚动条初始化后，居中到地图内容中心

// Workspace构造函数
Workspace::Workspace(QWidget *parent):
    BaseSpace(parent)   // 调用基类BaseSpace的构造函数
    //m_document(0)        // 初始化文档指针为nullptr
{
    // 创建水平标尺
    m_hruler = new QtRuleBar(Qt::Horizontal,this,this);
    // 创建垂直标尺
    m_vruler = new QtRuleBar(Qt::Vertical,this,this);
    // 创建角落盒子
    box = new QtCornerBox(this);
    // 连接缩放信号到更新标尺的槽函数
    connect(this,&BaseSpace::scaled,this,&Workspace::updateRuler);
}

// Workspace析构函数
Workspace::~Workspace()
{
    // 默认析构函数，自动释放成员变量
}

// 初始化函数
void Workspace::init()
{
//    BaseSpace::init();    // 调用基类的初始化
    BaseSpace::loadMap("./algorithm_map.smap");
    setZoomPercent(150);
    // 手动调整滚动条，确保地图内容真正居中
    QPointF center = m_mapBox.center();
    QPointF viewCenter = mapFromScene(center);
    int dx = viewCenter.x() - viewport()->width() / 2;
    int dy = viewCenter.y() - viewport()->height() / 2;
    horizontalScrollBar()->setValue(horizontalScrollBar()->value() + dx);
    verticalScrollBar()->setValue(verticalScrollBar()->value() + dy);
    this->updateRuler();
}


// 鼠标移动事件处理
void Workspace::mouseMoveEvent(QMouseEvent *event)
{
    QPoint eventPos = event->pos();  // 获取鼠标位置
    // 更新水平标尺位置
    m_hruler->updatePosition(eventPos);
    // 更新垂直标尺位置
    m_vruler->updatePosition(eventPos);
    // 调用基类的鼠标移动处理
    BaseSpace::mouseMoveEvent(event);
}

// 窗口大小改变事件处理    标尺在workspace上的实际布局位置
void Workspace::resizeEvent(QResizeEvent *event)
{
    BaseSpace::resizeEvent(event);  // 调用基类处理
    // 设置视口边距，为标尺留出空间
    this->setViewportMargins(RULER_SIZE-1,RULER_SIZE-1,0,0);
    // 调整水平标尺大小和位置
    m_hruler->resize(this->size().width()- RULER_SIZE - 1,RULER_SIZE);
    m_hruler->move(RULER_SIZE,0);
    // 调整垂直标尺大小和位置
    m_vruler->resize(RULER_SIZE,this->size().height() - RULER_SIZE - 1);
    m_vruler->move(0,RULER_SIZE);
    // 调整角落盒子大小和位置
    box->resize(RULER_SIZE,RULER_SIZE);
    box->move(0,0);
    // 更新标尺显示
    updateRuler();
//    zoomToFit();
}

// 滚动内容处理
void Workspace::scrollContentsBy(int dx, int dy)
{
    BaseSpace::scrollContentsBy(dx,dy);  // 调用基类处理
    updateRuler();  // 更新标尺显示
}

void Workspace::updateRuler()
{
    if (!scene()) return;

    //-------------------------------------------------------------
    // 1 scene-unit  =  1 m         ➜   标尺想显示「cm」
    //-------------------------------------------------------------
    constexpr double M2CM = 100.0;          // 1 m → 100 cm

    QRectF  viewbox = rect();                          // 视图像素框
    QPointF offset  = mapFromScene(scene()->sceneRect().topLeft());

    // 像素 → scene-unit（米）的比例：米/像素
    const double fac = 1.0 / transform().m11();

    /* ---------- 水平标尺 ---------- */
    double lx_m = fac*(viewbox.left()  - offset.x());          // m
    double ux_m = fac*(viewbox.right() - RULER_SIZE - offset.x());

    double lx_cm = lx_m*M2CM;         // ← 换成 cm
    double ux_cm = ux_m*M2CM;

    m_hruler->setRange(lx_cm, ux_cm, ux_cm-lx_cm);
    m_hruler->update();

    /* ---------- 垂直标尺 ---------- */
    double ly_m = -fac*(viewbox.top()    - offset.y());        // m
    double uy_m = -fac*(viewbox.bottom() - RULER_SIZE - offset.y());

    double ly_cm = ly_m*M2CM;
    double uy_cm = uy_m*M2CM;

    m_vruler->setRange(ly_cm, uy_cm, uy_cm-ly_cm);
    m_vruler->update();
}

// 鼠标滚轮事件处理 - 实现缩放功能
void Workspace::wheelEvent(QWheelEvent *event)
{
    qDebug() << "[DBG_WHEEL]" << "currentScale =" << transform().m11();

    // 获取滚轮滚动的角度增量
    QPoint numDegrees = event->angleDelta() / 8;
    
    if (!numDegrees.isNull()) {
        // 计算缩放因子
        qreal scaleFactor = 1.0;
        if (numDegrees.y() > 0) {
            // 向上滚动，放大
            scaleFactor = 1.15;
        } else {
            // 向下滚动，缩小
            scaleFactor = 1.0 / 1.15;
        }

        // 获取当前变换矩阵
        QTransform currentTransform = transform();
        qreal currentScale = currentTransform.m11();

        // 限制缩放范围，防止过度缩放
        qreal newScale = currentScale * scaleFactor;
        qDebug() << "newScale:" << newScale; // 输出调试信息
        if (newScale < 0.01 || newScale > 700) {//新增：调整缩放范围
            qDebug() << "newScale:";
            return; // 超出范围，不进行缩放

        }

        // 以鼠标位置为中心进行缩放
        QPointF mousePos = event->pos();
        
        // 保存鼠标在场景中的位置
        QPointF scenePos = mapToScene(mousePos.toPoint());
        
        // 应用缩放 - 使用zoom函数确保发出scaled信号
        zoom(newScale);
        
        // 重新计算鼠标在视图中的位置，保持鼠标指向的场景位置不变
        QPointF newViewPos = mapFromScene(scenePos);
        QPointF delta = newViewPos - mousePos;
        
        // 调整滚动条位置，使鼠标指向的内容保持在鼠标位置
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() + delta.x());
        verticalScrollBar()->setValue(verticalScrollBar()->value() + delta.y());
        
        // 更新标尺显示
//        updateRuler();
    }
    
    // 接受事件，防止传递给父类
    event->accept();
}



