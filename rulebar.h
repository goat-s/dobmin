#ifndef RULEBAR
#define RULEBAR

#include <QtWidgets>

QT_BEGIN_NAMESPACE
class QFrame;
class QPaintEvent;
class QPainter;
class QGraphicsView;
QT_END_NAMESPACE

#define RULER_SIZE    28

/**
* @brief   角落盒子控件类
* @note    用于显示在标尺交叉处的角落盒子
*/
class QtCornerBox : public QWidget
{
    Q_OBJECT
public:
    /**
    * @brief   构造函数
    * @param   parent 父控件指针
    */
    explicit QtCornerBox(QWidget * parent );
protected:
    /**
    * @brief   绘制事件处理函数
    * @param   QPaintEvent* 绘制事件指针
    */
    void paintEvent(QPaintEvent *);
};

/**
* @brief   标尺控件类
* @note    用于显示水平或垂直标尺
*/
class QtRuleBar : public QWidget
{
    Q_OBJECT
public:
    /**
    * @brief   构造函数
    * @param   direction 标尺方向（水平或垂直）
    * @param   view 关联的图形视图
    * @param   parent 父控件指针
    */
    explicit QtRuleBar(Qt::Orientation direction, QGraphicsView * view, QWidget * parent = 0  );
    
    /**
    * @brief   设置标尺范围
    * @param   lower 下限值
    * @param   upper 上限值
    * @param   max_size 最大尺寸
    */
    void setRange( double lower , double upper , double max_size );
    
    /**
    * @brief   更新位置指示器
    * @param   pos 新的位置
    */
    void updatePosition( const QPoint & pos );
protected:
    /**
    * @brief   绘制事件处理函数
    * @param   event 绘制事件指针
    */
    void paintEvent(QPaintEvent *event);
    
    /**
    * @brief   绘制刻度
    * @param   painter 绘图器指针
    */
    void drawTicker(QPainter * painter);
    
    /**
    * @brief   绘制位置指示器
    * @param   painter 绘图器指针
    */
    void drawPos(QPainter * painter) ;
    
    Qt::Orientation   m_direction; // 标尺方向
    QPoint m_lastPos; // 最后位置
    QGraphicsView * m_view; // 关联的图形视图

    double m_lower; // 下限值
    double m_upper; // 上限值
    double m_maxsize; // 最大尺寸
};

#endif // RULEBAR

