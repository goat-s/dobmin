#include <QGraphicsItem>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QBitmap>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QOpenGLWidget>
#include "basespace.h"
#include "preferences.h"
#include "QtAwesome/QtAwesome.h"
#include <cmath>
#include <QScrollBar>

struct BBoxM { double minX=1e9, minY=1e9, maxX=-1e9, maxY=-1e9; };
static BBoxM calcBBox(const getJson *js)
{
    BBoxM b;
    auto upd=[&](double x,double y){ b.minX=qMin(b.minX,x); b.maxX=qMax(b.maxX,x);
                                     b.minY=qMin(b.minY,y); b.maxY=qMax(b.maxY,y); };
    for (const Site   &s : js->Site_vector)       upd(s.start.x(), s.start.y());
    for (const QPointF&p : js->Barrier_vector)    upd(p.x(),       p.y());
    for (const Path   &p : js->paths){ upd(p.start.x(),p.start.y()); upd(p.end.x(),p.end.y()); }
    if (b.minX>1e8) b={0,0,1,1};      // 没数据时给 1×1
    return b;
}
// ---------- BaseSpace.h / cpp ----------
constexpr double MARGIN_M = 0.5;          // 0.5 m 白边
constexpr double DOT_R_M  = 0.08;         // 站点圆半径 0.08 m
constexpr double OBST_R_M = 0.02;         // 障碍散点半径 0.02 m
BaseSpace::BaseSpace(QWidget *parent):
    QGraphicsView(parent),
    m_scene(new BaseSpaceScene(this)),
    m_shiftLock(false)
{
    //this code will move to slots of useOpenGl
    QSurfaceFormat format = QSurfaceFormat::defaultFormat();
    format.setDepthBufferSize(0);   // No need for a depth buffer
    format.setSamples(10);           // Enable anti-aliasing   越大越丝滑
    m_json = new getJson;
    QOpenGLWidget *openGLWidget = new QOpenGLWidget(this);
    openGLWidget->setFormat(format);

    this->setViewport(openGLWidget);

    this->setMouseTracking(true);
    this->setObjectName("BaseSpace");
    this->setResizeAnchor(QGraphicsView::NoAnchor);

    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    // 1️⃣ 不让视口再自动把 sceneRect 居中
    // 启用 Qt 自带的“手抓拖拽”模式
//        setDragMode(QGraphicsView::ScrollHandDrag);
        // 视口不自动“重心对齐” sceneRect
        setAlignment(Qt::Alignment());                     // = 0
    this->viewport()->setBackgroundRole(QPalette::NoRole);
    this->setFrameShape(QFrame::NoFrame);
    this->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
    // ---- 删掉原来的 AlwaysOff，改成 AsNeeded ----
    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setVerticalScrollBarPolicy  (Qt::ScrollBarAsNeeded);
//    setSceneRect(QRectF());          // 清空视图对sceneRect的约束
    // === DBG_CONSTRUCT ===
//    qDebug() << "[DBG_CONSTRUCT]"
//             << "dragMode =" << dragMode()         // 0-NoDrag, 2-ScrollHandDrag
//             << "anchor =" << static_cast<int>(transformationAnchor());  // 0-NoAnchor, 1-UnderMouse...



}

BaseSpace::~BaseSpace()
{
    delete m_json;
}


// BaseSpace.cpp  --------------------------
void BaseSpace::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        /* ★ 无条件接管 —— 不让 scene / item 抢走事件 ★ */
        e->accept();                 // ① 标记已处理
        viewport()->setCursor(Qt::ClosedHandCursor);

        m_panning     = true;
        m_lastPanPos  = e->pos();

        // ② 取消锚点，避免 Qt 自动抵消平移
        m_savedAnchor = transformationAnchor();
        setTransformationAnchor(NoAnchor);
        return;                      // ③ 不再调用父类 —— item 收不到
    }
    /* 右键等其它按钮，走默认流程 */
    QGraphicsView::mousePressEvent(e);
}


void BaseSpace::mouseMoveEvent(QMouseEvent *e)
{
    /*--------------------------------------------------------------
     * 1. 若正在拖拽（左键已按下且被我们接管）
     *------------------------------------------------------------*/
    if (m_panning)
    {
        /* --- ① 计算拖动的位移（场景坐标系） --- */
        QPointF deltaScene = mapToScene(e->pos()) - mapToScene(m_lastPanPos);

        /* --- ② 把视图整体平移 --- */
        translate(deltaScene.x(), deltaScene.y());

        /* --- ③ 记录当前位置，用于下一帧计算 delta --- */
        m_lastPanPos = e->pos();

        /*----------------------------------------------------------
         * ④ 若视口已经拖到 sceneRect 边缘，就把 sceneRect 再向外扩张
         *    这样可无限拖动背景，而不会被“边界”卡住
         *--------------------------------------------------------*/
        const QRectF viewRectScene = mapToScene(viewport()->rect()).boundingRect();
        QRectF       sceneBox      = sceneRect();
        constexpr double GROW = 2000.0;        // 一次向外扩多少（scene 单位：米）

        bool needExpand = false;

        if (viewRectScene.left()   < sceneBox.left()   ) { sceneBox.adjust(-GROW, 0,     0,     0); needExpand = true; }
        if (viewRectScene.right()  > sceneBox.right()  ) { sceneBox.adjust( 0,     0,  GROW,     0); needExpand = true; }
        if (viewRectScene.top()    < sceneBox.top()    ) { sceneBox.adjust( 0,  -GROW, 0,        0); needExpand = true; }
        if (viewRectScene.bottom() > sceneBox.bottom() ) { sceneBox.adjust( 0,     0,  0,   GROW); needExpand = true; }

//        if (needExpand)
//            scene()->setSceneRect(sceneBox);

        /* --- ⑤ 如需让标尺同步刷新，可继续发信号 --- */
        emit scaled();

        /* --- ⑥ 事件到此完全由我们处理 --- */
        e->accept();
        return;
    }

    /*--------------------------------------------------------------
     * 2. 非拖拽状态下，走默认行为
     *------------------------------------------------------------*/
    QGraphicsView::mouseMoveEvent(e);
}


void BaseSpace::mouseReleaseEvent(QMouseEvent *e)
{
    qDebug() << "[DBG_RELEASE]"
             << "anchor =" << transformationAnchor();
    if (m_panning && e->button() == Qt::LeftButton) {
        m_panning = false;
        setTransformationAnchor(m_savedAnchor);
        viewport()->setCursor(Qt::OpenHandCursor);
        e->accept();
        return;
    }
    QGraphicsView::mouseReleaseEvent(e);
}

//bool BaseSpace::loadMap(const QString &file)
//{
//    if (!m_json) m_json = new getJson;
//    m_json->reviseAddress(file);
//    m_json->getAll();
//    // BaseSpace ctor 末尾或 loadMap() 最前面加一句
//    if (transform().m22() > 0) {          // 只做一次，别反复取反
//        QTransform flipY(1, 0, 0, -1, 0, 0);
//        setTransform(flipY * transform());
//    }

//    auto *sc = static_cast<BaseSpaceScene*>(scene());
//    sc->clear();                     // 清旧图

//    sc->renderSites   (m_json->Site_vector);
//    sc->renderBarriers(m_json->Barrier_vector);

//    // 1️⃣ 计算“纸张”包围盒（米）
//    auto bb = calcBBox(m_json);
//       QRectF paper(
//         bb.minX - MARGIN_M,
//         bb.minY - MARGIN_M,
//         (bb.maxX - bb.minX) + 2*MARGIN_M,
//         (bb.maxY - bb.minY) + 2*MARGIN_M
//       );

//       // 1️⃣ 先放入视口并居中，仅针对 paper
//       fitInView(paper, Qt::KeepAspectRatio);
//       centerOn(paper.center());

//       // 2️⃣ 拿到此时的缩放倍数（px / scene-unit）
//       qreal s = transform().m11();

//       // 3️⃣ 计算视口在 scene 单位里的尺寸
//       QSizeF vpScene = QSizeF(viewport()->size()) / s;

//       // 4️⃣ 让 sceneRect 比 paper 四周各多留一整个视口的空间
//       constexpr double PAD = 5000.0;                 // 想拖多远就设多大 (scene 单位：米)
//       QRectF fullRect = paper.adjusted(-PAD, -PAD, PAD, PAD);
//       scene()->setSceneRect(fullRect);

//       // 把纸张矩形交给 BaseSpaceScene 记下来
//       static_cast<BaseSpaceScene*>(scene())->setPaperRect(paper);
//       // 5️⃣ 保存 baseScale 以便 slider 调整用
//       m_base      = transform();
//       m_baseScale = m_base.m11();

//       emit scaled();
//       return true;
//}
bool BaseSpace::loadMap(const QString& file)
{
    /* ---------- 读取数据 ---------- */
    if (!m_json) m_json = new getJson;
    m_json->reviseAddress(file);
    m_json->getAll();

    /* ---------- 首次 Y 反转（Qt-y 向下 → 地图-y 向上） ---------- */
    if (transform().m22() > 0)                     // 只做一次
    {
        QTransform flipY(1, 0, 0,
                         0,-1, 0,
                         0, 0, 1);
        setTransform( flipY * transform() );
    }

    /* ---------- 把地图元素画进场景 ---------- */
    auto* sc = static_cast<BaseSpaceScene*>(scene());
    sc->clear();                                  // 清旧图
    sc->renderSites   (m_json->Site_vector);
    sc->renderBarriers(m_json->Barrier_vector);

    /* ============================================================
     * 1) 计算包围盒
     *    mapBox  : 纯有效地图；后续 fit/center 用它
     *    paper   : mapBox 外再留 0.5 m 白边，仅视觉用途
     * ========================================================== */
    BBoxM bb = calcBBox(m_json);

    QRectF mapBox(bb.minX,
                  bb.minY,
                  bb.maxX - bb.minX,
                  bb.maxY - bb.minY);

    m_mapBox = mapBox; // 新增：保存地图内容包围盒

    constexpr double MARGIN_M = 0.5;              // 0.5 m 白边
    QRectF paper = mapBox.adjusted(-MARGIN_M, -MARGIN_M,
                                    MARGIN_M,  MARGIN_M);

    /* ---------- 2) sceneRect：一次性撑到巨大的灰板 ---------- */
    // constexpr double PAD = 5000.0;                // 随便够大的值
    constexpr double PAD = 1.0;      // 新增：方便居中的幕布
    scene()->setSceneRect( paper.adjusted(-16*PAD, -9*PAD, 16*PAD, 9*PAD) );

    /* ---------- 3) 把纸张矩形交给 Scene，用来刷白 ---------- */
    sc->setPaperRect(paper);

    /* ---------- 4) 初始缩放 / 居中，都用 mapBox ---------- */
    fitInView(mapBox, Qt::KeepAspectRatio);
    centerOn (mapBox.center());

    /* ---------- 5) 记录基准变换，供缩放滑块使用 ---------- */
    m_base      = transform();
    m_baseScale = m_base.m11();

    emit scaled();
    return true;
}

// BaseSpace.cpp
void BaseSpace::setZoomPercent(int percent)   // 1‒10000
{
    percent = qBound(1, percent, 10000);
    double target = m_baseScale * (percent / 100.0);   // 关键公式
    zoom(target);                                      // ← 仍用你的 zoom()
}

void BaseSpace::setDrawing(bool arg1)
{

    m_scene->setDrawing(arg1);

}


void BaseSpace::init()
{

    PhysicalSize psize;
    psize.size = Preferences::instance()->defaultPageSize();
    psize.unit = (int)UNIT_TYPE_MM;

    qobject_cast<BaseSpaceScene *>(this->scene())->setPhysicalSize(psize);

    this->fitInView(this->sceneRect().adjusted(8,8,8,8),Qt::KeepAspectRatio);

}

void BaseSpace::setPicking(bool arg1)
{
    m_scene->setPicking(arg1);
}

bool BaseSpace::picking() const
{
    return m_scene->picking();
}
void BaseSpace::fitViewNoEnlarge(const QRectF &target)
{
    if (target.isEmpty()) return;

    QSizeF vp = viewport()->size();
    if (vp.isEmpty())      return;

    double sx = vp.width()  / target.width();
    double sy = vp.height() / target.height();
    double s  = qMin(sx, sy);

    if (s > 1.0) s = 1.0;              // 关键：禁止放大

    QTransform t;
    t.scale(s, s);
    setTransform(t);
    centerOn(target.center());
}



void BaseSpace::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    emit scaled();
}


void BaseSpace::scrollContentsBy(int dx, int dy)
{
    qDebug() << "[DBG_SCROLL]"
             << "dx =" << dx << "dy =" << dy;
    QGraphicsView::scrollContentsBy(dx,dy);
    emit scaled();
}


void BaseSpace::zoomToFit()
{

    this->fitInView(this->sceneRect(),Qt::KeepAspectRatio);
    emit scaled();
}

void BaseSpace::zoom(qreal targetScale)          // 绝对倍率
{
    qreal cur = transform().m11();               // 当前倍率
    if (qFuzzyCompare(cur, targetScale)) return;

    qreal ratio = targetScale / cur;             // 需要乘的因子
    scale(ratio, ratio);                         // ☆ 关键：相对缩放
    emit scaled();
}

namespace { constexpr double R = 0.01; }  // 点半径 (m)
BaseSpaceScene::BaseSpaceScene(BaseSpace *space):QGraphicsScene(space),
    m_drawing(false),
    m_picking(false),
    m_space(space),
    m_paperRect()
{
    Q_ASSERT(space!=0);
    space->setScene(this);

    setBackgroundBrush(Qt::transparent);
    /* ★★ 只添加 4 行 ★★ */
       mapLayer_ = new QGraphicsItemGroup;
       addItem(mapLayer_);
       mapLayer_->setHandlesChildEvents(false);   // 事件继续落到子项


}
void BaseSpaceScene::renderBarriers(const QVector<QPointF>& pts)
{
    const QPen   pen(Qt::darkGray, 0);     // 0 = 1px 细边
    const QBrush br (Qt::darkGray);

    for (const QPointF& p : pts)
    {
        auto *dot = addEllipse(p.x() - OBST_R_M,
                               p.y() - OBST_R_M,
                               2 * OBST_R_M,
                               2 * OBST_R_M,
                               pen, br);               // ← 已自动加入 scene

        dot->setParentItem(mapLayer_);                 // 放进图层组
//       dot->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    }
}


void BaseSpaceScene::renderSites(const QVector<Site>& sites)
{
    qDeleteAll(mapLayer_->childItems());               // 清空旧内容

    const QPen   pen(Qt::blue, 0);
    const QBrush br (Qt::blue);
    const QFont  font("Microsoft YaHei", 8, QFont::Bold);

    for (const Site& s : sites)
    {
        /* --- 圆点 --- */
        auto *dot = addEllipse(s.start.x() - DOT_R_M,
                               s.start.y() - DOT_R_M,
                               2 * DOT_R_M,
                               2 * DOT_R_M,
                               pen, br);

        dot->setParentItem(mapLayer_);
//        dot->setFlag(QGraphicsItem::ItemIgnoresTransformations);

        /* --- 名字 --- */
        auto *lbl = addSimpleText(s.Site_Name, font);
        lbl->setPos(s.start + QPointF(0.15, 0.15));    // 0.15 m 右上
        lbl->setParentItem(mapLayer_);
        lbl->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    }
}


void BaseSpaceScene::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsScene::mousePressEvent(e);        // 先让父类选中

    if (e->button()!=Qt::LeftButton) return;

    if (auto *it = itemAt(e->scenePos(), QTransform())) {
        QVariant v = it->data(0);
        if (v.isValid()) {
            QPointF pos = it->sceneBoundingRect().center();
            emit m_space->siteClicked(v.toString(), pos.x(), pos.y());
        }
    }
}

void BaseSpaceScene::setDrawing(bool arg1)
{
    m_drawingElement = 0;
    if (arg1){
        m_space->viewport()->setCursor(Qt::CrossCursor);

    }else{
        m_space->viewport()->setCursor(Qt::ArrowCursor);
    }
    m_drawing = arg1;

}

QSize BaseSpaceScene::actualPxSize()
{
    return m_actualPxSize;

}

qreal BaseSpaceScene::scaleFactor()
{
    return this->sceneRect().width()/this->actualPxSize().width();
}

void BaseSpaceScene::setPicking(bool arg1)
{
    m_picking=arg1;
}


void BaseSpaceScene::setPhysicalSize(PhysicalSize arg1)
{
    if ((m_physicalSize.size == arg1.size) && (m_physicalSize.unit == arg1.unit))
        return;
    m_physicalSize = arg1;

    m_actualPxSize = m_physicalSize.size * (m_physicalSize.unit?PX_PER_INCH:PX_PER_MM);
    this->setSceneRect(QRect(QPoint(0,0),m_actualPxSize));
    emit physicalSizeChanged(m_physicalSize);

}

void BaseSpaceScene::drawBackground(QPainter *p, const QRectF &rect)
{

    // 1) 整个 sceneRect 先铺深灰
       static const QColor kBg(30, 30, 30);     // 想要纯黑可改 0,0,0
       p->fillRect(sceneRect(), kBg);

       // 2) 再把“纸张”区域刷成白色
       //    m_paperRect 是 BaseSpace 在 loadMap() 时通过
       //    static_cast<BaseSpaceScene*>(scene())->setPaperRect(paper);
       //    传进来的，里边只保存一次，不用每帧算。
       if (!m_paperRect.isNull())
           p->fillRect(m_paperRect, Qt::white);
}

void BaseSpaceScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);

}

//void BaseSpaceScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    QGraphicsScene::mousePressEvent(event);

//}

void BaseSpaceScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);

}

void BaseSpaceScene::keyPressEvent(QKeyEvent *event)
{
    QGraphicsScene::keyPressEvent(event);

}

void BaseSpaceScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseDoubleClickEvent(event);

}


