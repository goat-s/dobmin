#include "zoomadjust.h"
#include "ui_zoomadjust.h"
#include "QtAwesome.h"          //这是一个流行的Qt图标库

ZoomAdjust::ZoomAdjust(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZoomAdjust),
    m_factor(150)
{
    ui->setupUi(this);//取消滑动条
    ui->btnZoomIn->setIcon(QTAWESOME->icon(fa::minus));
    ui->btnZoomOut->setIcon(QTAWESOME->icon(fa::plus));
    ui->btnFit->setIcon(QTAWESOME->icon(fa::fittocanvas)); //设置图片

    connect(ui->slider,&QSlider::valueChanged,this,[this](int v){ setFactor(v, /*emitSignal=*/true); });

    connect(ui->btnZoomOut,&QPushButton::clicked,this,[this](bool){
       ui->slider->setValue(ui->slider->value()-1);
    });

    connect(ui->btnZoomIn,&QPushButton::clicked,this,[this](bool){
       ui->slider->setValue(ui->slider->value()+1);
    });

    connect(ui->btnFit,     &QPushButton::clicked,   this, &ZoomAdjust::zoomToFit);

    connect(ui->editFactor, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int v){ setFactor(v, /*emitSignal=*/true); });

}

ZoomAdjust::~ZoomAdjust()
{
    delete ui;
}

// zoomadjust.h (或 .cpp)
static const int SLIDER_MIN =   1;     // 1  %
static const int SLIDER_MAX = 2400;    // 新增：最大放到2400 %

void ZoomAdjust::setFactor(int percent, bool emitSignal)
{
    percent = qBound(SLIDER_MIN, percent, SLIDER_MAX);

    /* ① 先更新成员，再判断是否需要发信号 */
    bool changed = (m_factor != percent);
    m_factor = percent;

    ui->slider->blockSignals(true);
    ui->editFactor->blockSignals(true);
    ui->slider->setRange(SLIDER_MIN, SLIDER_MAX);
    ui->slider->setValue(percent);
    ui->editFactor->setValue(percent);
    ui->slider->blockSignals(false);
    ui->editFactor->blockSignals(false);

    /* ② 只要来源不是“回写”，就发信号 */
    if (emitSignal && changed)
        emit factorChanged(percent);
}
