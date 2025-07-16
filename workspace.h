#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "basespace.h"
#include "graphicsitemtype.h"
#include <QGraphicsItem>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QGraphicsPixmapItem>
#include <QDragMoveEvent>
#include <QSet>

class RectElement;
class BaseElement;
//class Document;

class QtRuleBar;
class QtCornerBox;


//class WorkSheet : public QGraphicsItem
//{
//    QRectF m_geometry;
//    QBrush m_background;
//    Outline * m_outline;

//public:
//    enum { Type = UserType+ GRAPHICSITEM_TYPE_WORKSHEET };
//    int type() const
//    {
//        // Enable the use of qgraphicsitem_cast with this item.
//        return Type;
//    }

//public:
//    WorkSheet(QGraphicsItem * parent= Q_NULLPTR);
//    QRectF boundingRect() const override;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
//                     QWidget *widget) override;

//    void setSize(const QSizeF & value);
//    inline QSizeF size() const {return m_geometry.size();}
//    void setGeometry(qreal x,qreal y,qreal w,qreal h);
//    void setGeometry(const QRectF & value);
//    inline QRectF geometry() const {return m_geometry;}
//    inline void setBackground(const QBrush & value) {m_background = value;}
//    inline QBrush Background() const { return m_background;}
//    void clear();


//};



class Workspace: public BaseSpace
{
Q_OBJECT
    //Document * m_document;
    //WorkSheet * m_currentSheet;
    QtRuleBar * m_hruler;
    QtRuleBar * m_vruler;
    QtCornerBox * box;


public:

    explicit Workspace(QWidget* parent = nullptr);
    virtual ~Workspace();
    virtual void init() override;

public slots:
    void setToolMode(int mode);



private:
    bool m_drawCarMode = false;
    enum ToolMode { Select = 0, DrawCar = 1, Eraser = 2 /*, DrawLine, ...*/ };
    ToolMode m_toolMode = Select;
    bool m_erasing = false;
    QSet<QGraphicsItem*> m_erasedThisDrag;
    ToolMode toolMode() const { return m_toolMode; }

public:
    void setDrawCarMode(bool enable);
    bool isDrawCarMode() const { return m_drawCarMode; }


public slots:

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void scrollContentsBy(int dx, int dy) override;
    void wheelEvent(QWheelEvent *event) override;


private slots:
    void updateRuler();
    void eraseAt(const QPoint &viewPos);


};

#endif // WORKSPACE_H
