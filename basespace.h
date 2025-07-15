#ifndef BASEGRAPHICSVIEW_H
#define BASEGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "preferences.h"
//#include "utilities.h"
#include "commondef.h"
#include "getjson.h"
class BaseSpace;
class BaseElement;
//class GroupPickerElement;


class BaseSpaceScene : public QGraphicsScene
{
Q_OBJECT
    bool m_drawing;
    bool m_picking;
    BaseElement * m_drawingElement;
    BaseElement * m_activeElement;
    BaseSpace * m_space;

    Q_PROPERTY(PhysicalSize physicalSize READ physicalSize WRITE setPhysicalSize NOTIFY physicalSizeChanged)

    PhysicalSize m_physicalSize;
    QSize m_actualPxSize;

    //GroupPickerElement * m_groupPicker;


public:

    explicit BaseSpaceScene(BaseSpace *parent);
    void setDrawing(bool arg1);
    QSize actualPxSize();

    inline PhysicalSize physicalSize() const
    {
        return m_physicalSize;
    }

    qreal scaleFactor();

    void setPicking(bool);
    bool picking() const { return m_picking ;}
    void renderSites(const QVector<Site>& sites);



    void renderBarriers(const QVector<QPointF> &pts);
         void setPaperRect(const QRectF& r) { m_paperRect = r; }
public slots:
    void setPhysicalSize(PhysicalSize physicalSize);

signals:
    void physicalSizeChanged(PhysicalSize physicalSize);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) Q_DECL_OVERRIDE;
    void mousePressEvent(QGraphicsSceneMouseEvent *e) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
//    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
    virtual void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
private:
    /* ★ 新增：专给地图用的分组，可整体缩放 */
      QGraphicsItemGroup *mapLayer_ = nullptr;
     friend class BaseSpace;
        QRectF m_paperRect;          // 纸张范围
};


class BaseSpace : public QGraphicsView
{
Q_OBJECT
    BaseSpaceScene * m_scene;
    bool m_shiftLock;//shift key is pressed during resize or move


public:
    explicit BaseSpace(QWidget *parent = Q_NULLPTR);
    ~BaseSpace();

    void setDrawing(bool arg1);

    virtual void init();

    void setPicking(bool);
    bool picking() const;
    double baseScale() const { return m_baseScale; }

    inline BaseSpaceScene * baseScene() {return m_scene;}
    bool loadMap(const QString& smapFile);
    void fitViewNoEnlarge(const QRectF &target);
    void setZoomPercent(int percent);

private:
    getJson*      m_json = nullptr;    // 地图解析器
    QVector<QGraphicsItem*> m_siteItems; // 方便日后清理/刷新
    QTransform m_base;        // 适配视口时的矩阵
      double     m_baseScale;   // = m_base.m11()
      bool                           m_panning      = false;
          QPoint                         m_lastPanPos;          // 视口坐标
          ViewportAnchor                 m_savedAnchor  = AnchorUnderMouse;
protected:
    QRectF    m_mapBox; // 新增：保存地图内容包围盒

protected:
         void mousePressEvent  (QMouseEvent *ev) override;
         void mouseMoveEvent   (QMouseEvent *ev) override;
         void mouseReleaseEvent(QMouseEvent *ev) override;

    void resizeEvent(QResizeEvent *event) override;

    void scrollContentsBy(int dx, int dy) override;

public slots:
    void zoom(qreal factor);
    void zoomToFit();



signals:
    void scaled();
    void elementCreated(BaseElement * element);
    void originalSizeChanged(QSize originalSize);
    /* 点击站点时对外广播，方便上位机同步高亮等 */
     void siteClicked(const QString& name, double x, double y);
};



#endif // BASEGRAPHICSVIEW_H
