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



private:
    bool m_drawCarMode = false;

public:
    void setDrawCarMode(bool enable);
    bool isDrawCarMode() const { return m_drawCarMode; }


public slots:

protected:
    void mousePressEvent(QMouseEvent * event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent * event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    void scrollContentsBy(int dx, int dy) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;


private slots:
    void updateRuler();


};

#endif // WORKSPACE_H
