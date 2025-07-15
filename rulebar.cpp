#include "rulebar.h"
#include <QGraphicsView>

#define MINIMUM_INCR   5

typedef struct
{
  double ruler_scale[16]; // 标尺刻度数组
  int    subdivide[5]; // 细分数组
}SPRulerMetric;

// 通用标尺度量
static SPRulerMetric const ruler_metric_general = {
    { 1, 2, 5, 10, 25, 50, 100, 250, 500, 1000, 2500, 5000, 10000, 25000, 50000, 100000 },
    { 1, 5, 10, 50, 100 }
  };
  
// 英寸标尺度量
static SPRulerMetric const ruler_metric_inches = {
    { 1, 2, 4,  8, 16, 32,  64, 128, 256,  512, 1024, 2048, 4096, 8192, 16384, 32768 },
    { 1, 2,  4,  8,  16 }
  };

/**
* @brief   标尺控件构造函数
* @param   direction 标尺方向（水平或垂直）
* @param   view 关联的图形视图
* @param   parent 父控件指针
* @note    初始化标尺控件的基本属性
*/
QtRuleBar::QtRuleBar(Qt::Orientation direction, QGraphicsView * view, QWidget *parent)
    :QWidget(parent),
    m_view(view)
{
    m_lower = m_upper = m_maxsize = 0; // 初始化范围和最大尺寸为0
    m_lastPos = QPoint(0,0); // 初始化最后位置为原点
    m_direction = direction; // 设置标尺方向
    QFont f(font()); // 获取当前字体
    f.setBold(false); // 设置非粗体
    f.setPixelSize(10); // 设置字体像素大小为10
    setFont(f); // 应用字体设置
}

/**
* @brief   设置标尺范围
* @param   lower 下限值
* @param   upper 上限值
* @param   max_size 最大尺寸
* @note    更新标尺的显示范围和最大尺寸
*/
void QtRuleBar::setRange(double lower, double upper, double max_size)
{
    m_lower = lower; // 设置下限值
    m_upper = upper; // 设置上限值
    m_maxsize = max_size; // 设置最大尺寸
}

/**
* @brief   更新位置指示器
* @param   pos 新的位置
* @note    根据传入的位置更新标尺指示器并触发重绘
*/
void QtRuleBar::updatePosition(const QPoint &pos)
{
    m_lastPos = pos; // 更新最后位置
    update(); // 触发重绘
}//显示当前鼠标或操作点在标尺上对应的位置

/**
* @brief   绘制事件处理函数
* @param   event 绘制事件指针
* @note    处理标尺的绘制，包括背景、边框、刻度和位置指示器
*/
void QtRuleBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event); // 未使用的参数
    QPalette palette = qApp->palette(); // 获取应用程序调色板
    QPainter painter(this); // 创建绘图器
    QRect rulerRect = rect(); // 获取标尺矩形区域
    painter.fillRect(rulerRect, palette.window().color()); // 填充背景色

    QPen pen(palette.windowText().color()); // 创建画笔
    painter.setPen(pen); // 设置画笔

    // 根据方向绘制边框线
    if (m_direction == Qt::Horizontal) {
        painter.drawLine(rulerRect.bottomLeft(), rulerRect.bottomRight()); // 水平标尺绘制底边线
    }
    else {
        painter.drawLine(rulerRect.topRight(), rulerRect.bottomRight()); // 垂直标尺绘制右边线
    }

    drawTicker(&painter); // 绘制刻度
    drawPos(&painter); // 绘制位置指示器
}

/**
* @brief   绘制刻度
* @param   painter 绘图器指针
* @note    根据标尺范围和方向绘制刻度线和刻度值
*/
void QtRuleBar::drawTicker(QPainter *painter)
{
    int i; // 循环变量
    int width, height; // 宽度和高度
    int length, ideal_length; // 刻度长度和理想长度
    double lower = m_lower, upper = m_upper; // 上下限值
    double increment; // 每单位像素数
    uint scale; // 每主单位的单位数
    double start, end, cur; // 开始、结束和当前位置
    char unit_str[32]; // 单位字符串
    char digit_str[2] = { '\0', '\0' }; // 数字字符串
    int digit_height; // 数字高度
    int digit_offset; // 数字偏移
    int text_size; // 文本大小
    int pos; // 位置
    double max_size = m_maxsize; // 最大尺寸
    SPRulerMetric ruler_metric = ruler_metric_general; // 使用通用度量
    QRect allocation = this->rect(); // 获取分配区域
    QFontMetrics fm(font()); // 获取字体度量
    digit_height = fm.height(); // 获取数字高度
    digit_offset = 0; // 初始化数字偏移
    
    // 根据方向确定宽度和高度
    if (m_direction == Qt::Horizontal) {
        width = allocation.width(); // 水平方向宽度
        height = allocation.height(); // 水平方向高度
    } else {
        width = allocation.height(); // 垂直方向宽度
        height = allocation.width(); // 垂直方向高度
    }
    
    if ((upper - lower) == 0) return; // 如果范围为0则返回
    increment = (double)width / (upper - lower); // 计算增量

    scale = ceil(max_size); // 计算刻度
    sprintf(unit_str, "%d", scale); // 格式化单位字符串
    text_size = strlen(unit_str) * digit_height + 1; // 计算文本大小
    
    // 选择合适的刻度
    for (scale = 0; scale < sizeof(ruler_metric.ruler_scale) /
         sizeof(ruler_metric.ruler_scale[0]); scale++)
        if (ruler_metric.ruler_scale[scale] * fabs(increment) > 2 * text_size)
            break;
    if (scale == sizeof(ruler_metric.ruler_scale))
        scale = sizeof(ruler_metric.ruler_scale) - 1; // 防止越界
    length = 0; // 初始化长度

    // 绘制刻度线
    for (i = sizeof(ruler_metric.subdivide) /
         sizeof(ruler_metric.subdivide[0]) - 1; i >= 0; i--) {
        double subd_incr; // 细分增量
        if (scale == 1 && i == 1)
            subd_incr = 1.0; // 特殊情况处理
        else
            subd_incr = ((double)ruler_metric.ruler_scale[scale] /
                         (double)ruler_metric.subdivide[i]); // 计算细分增量
        if (subd_incr * fabs(increment) <= MINIMUM_INCR)
            continue; // 如果增量太小则跳过

        ideal_length = height / (i + 1) - 1;

        if (ideal_length > ++length)
            length = ideal_length; // 更新长度
            
        // 计算开始和结束位置
        if (lower < upper) {
            start = floor(lower / subd_incr) * subd_incr; // 计算开始位置
            end = ceil(upper / subd_incr) * subd_incr; // 计算结束位置
        } else {
            start = floor(upper / subd_incr) * subd_incr; // 计算开始位置
            end = ceil(lower / subd_incr) * subd_incr; // 计算结束位置
        }
        
        int tick_index = 0; // 刻度索引
        // 绘制每个刻度
        for (cur = start; cur <= end; cur += subd_incr) {
            pos = int(qRound((cur - lower) * increment + 1e-12)); // 计算位置
            
            // 根据方向绘制刻度线
            if (m_direction == Qt::Horizontal) {
                QRect rt(pos, height - length, 1, length); // 创建矩形
                painter->drawLine(rt.topLeft(), rt.bottomLeft()); // 绘制线
            } else {
                QRect rt(height - length, pos, length, 1); // 创建矩形
                painter->drawLine(rt.topLeft(), rt.topRight()); // 绘制线
            }
            
            // 计算标签间距
            double label_spacing_px = fabs(increment * (double)ruler_metric.ruler_scale[scale] / ruler_metric.subdivide[i]);
            
            // 绘制刻度标签
            if (i == 0 &&
                    (label_spacing_px > 6 * digit_height || tick_index % 2 == 0 || cur == 0) &&
                    (label_spacing_px > 3 * digit_height || tick_index % 4 == 0 || cur == 0))
            {
                // 格式化标签文本
                if (qAbs((int)cur) >= 2000 && (((int)cur) / 1000) * 1000 == ((int)cur))
                    sprintf(unit_str, "%dk", ((int)cur) / 1000); // 千位显示为k
                else
                    sprintf(unit_str, "%d", (int)cur); // 正常显示
                    
                // 根据方向绘制文本
                if (m_direction == Qt::Horizontal) {
                    int w = fm.width(unit_str); // 获取文本宽度
                    painter->drawText(pos + 2,
                                     allocation.top(),
                                     w,
                                     RULER_SIZE,
                                     Qt::AlignLeft | Qt::AlignTop, unit_str); // 绘制水平文本
                } else {
#if 0
                    int w = fm.width("u") + 2; // 获取文本宽度
                    int start = cur < 0 ? 1 : 0; // 确定起始位置
                    if (start == 1) {
                        QRect textRect(-w / 2, -digit_height / 2, w, digit_height); // 创建文本矩形
                        painter->save(); // 保存状态
                        painter->translate(4, pos + w / 2 + 2); // 平移
                        painter->rotate(90); // 旋转90度
                        painter->drawText(textRect,
                                         Qt::AlignRight, QString(unit_str[0])); // 绘制文本
                        painter->restore(); // 恢复状态
                    }
                    for (int j = start; j < (int)strlen(unit_str); j++) {
                        digit_str[0] = unit_str[j]; // 获取单个数字
                        painter->drawText(1,
                                         pos + digit_height * j,
                                         w,
                                         digit_height,
                                         Qt::AlignLeft | Qt::AlignTop, QString(digit_str[0])); // 绘制单个数字
                    }
#else
                    int w = fm.width(unit_str); // 获取文本宽度
                    QRect textRect(-w / 2, -RULER_SIZE / 2, w, RULER_SIZE); // 创建文本矩形
                    painter->save(); // 保存状态
                    painter->translate(4, pos + w / 2 + 2); // 平移
                    painter->rotate(90); // 旋转90度
                    painter->drawText(textRect, Qt::AlignRight, unit_str); // 绘制垂直文本
                    painter->restore(); // 恢复状态
#endif
                }
            }
            tick_index++; // 增加刻度索引
        }
    }
}

/**
* @brief   绘制位置指示器
* @param   painter 绘图器指针
* @note    根据当前位置绘制标尺上的位置指示线
*/
void QtRuleBar::drawPos(QPainter *painter)
{
   int x, y; // 坐标变量
   int width, height; // 宽度和高度
   int bs_width, bs_height; // 边框宽度和高度
   QRect allocation = this->rect(); // 获取控件矩形区域
   double position; // 位置变量
   double lower = m_lower; // 下限值
   double upper = m_upper; // 上限值
   
   // 根据方向计算尺寸和位置
   if (m_direction == Qt::Horizontal) { // 水平方向
       width = allocation.width(); // 获取宽度
       height = allocation.height(); // 获取高度
       bs_width = height / 2 + 2; // 计算边框宽度
       bs_width |= 1;  /* 确保是奇数 */
       bs_height = bs_width / 2 + 1; // 计算边框高度
       position = lower + (upper - lower) * m_lastPos.x() / allocation.width(); // 计算位置
   } else { // 垂直方向
       width = allocation.height(); // 获取宽度
       height = allocation.width(); // 获取高度
       bs_height = width / 2 + 2; // 计算边框高度
       bs_height |= 1;  /* 确保是奇数 */
       bs_width = bs_height / 2 + 1; // 计算边框宽度
       position = lower + (upper - lower) * m_lastPos.y() / allocation.height(); // 计算位置
   }
   
   // 如果边框尺寸有效则绘制指示器
   if ((bs_width > 0) && (bs_height > 0)) {
       double increment; // 增量
       if (m_direction == Qt::Horizontal) { // 水平方向
           increment = (double)width / (upper - lower); // 计算增量
           x = qRound((position - lower) * increment) + bs_width / 2 - 1; // 计算X坐标
           y = (height + bs_height) / 2; // 计算Y坐标
           // 保存当前画笔
           QPen oldPen = painter->pen();
           // 设置指示线颜色（例如绿色）
           QPen indicatorPen(QColor(0, 255, 0)); // 绿色指示线
           painter->setPen(indicatorPen);
           // 绘制指示线
           painter->drawLine(m_lastPos.x(), 0, m_lastPos.x(), height);
           // 恢复原来的画笔
           painter->setPen(oldPen);
       } else { // 垂直方向
           increment = (double)height / (upper - lower); // 计算增量
           x = (width + bs_width) / 2; // 计算X坐标
           y = qRound((position - lower) * increment) + (bs_height) / 2 - 1; // 计算Y坐标
           // 保存当前画笔
           QPen oldPen = painter->pen();
           // 设置指示线颜色（例如绿色）
           QPen indicatorPen(QColor(0, 255, 0)); // 绿色指示线
           painter->setPen(indicatorPen);
           // 绘制指示线
           painter->drawLine(0, m_lastPos.y(), width, m_lastPos.y());
           // 恢复原来的画笔
           painter->setPen(oldPen);
       }
   }
}

/**
* @brief   角落盒子构造函数
* @param   parent 父控件指针
* @note    初始化角落盒子控件
*/
QtCornerBox::QtCornerBox(QWidget *parent)
    :QWidget(parent)
{
    // 空实现
}

/**
* @brief   角落盒子绘制事件
* @param   e 绘制事件指针
* @note    绘制角落盒子的背景和中心十字线
*/
void QtCornerBox::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e); // 未使用参数
    QPainter painter(this); // 创建绘图器
    QPalette palette = qApp->palette(); // 获取应用程序调色板
    painter.fillRect(rect(), palette.window().color()); // 填充背景色

    QPen pen(palette.windowText().color()); // 创建画笔
    pen.setStyle(Qt::DashLine); // 设置虚线样式
    painter.setPen(pen); // 设置画笔
    
    // 绘制中心十字线
    painter.drawLine(rect().center().x(), rect().top(), rect().center().x(), rect().bottom()); // 绘制垂直中心线
    painter.drawLine(rect().left(), rect().center().y(), rect().right(), rect().center().y()); // 绘制水平中心线

    // 绘制边框线
    painter.drawLine(rect().topRight(), rect().bottomRight()); // 绘制右边框线
    painter.drawLine(rect().bottomLeft(), rect().bottomRight()); // 绘制底边框线
}
