/********************************************************************************
** Form generated from reading UI file 'zoomadjust.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZOOMADJUST_H
#define UI_ZOOMADJUST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZoomAdjust
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *btnZoomOut;
    QSlider *slider;
    QPushButton *btnZoomIn;
    QSpinBox *editFactor;
    QPushButton *btnFit;

    void setupUi(QWidget *ZoomAdjust)
    {
        if (ZoomAdjust->objectName().isEmpty())
            ZoomAdjust->setObjectName(QString::fromUtf8("ZoomAdjust"));
        ZoomAdjust->resize(200, 20);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ZoomAdjust->sizePolicy().hasHeightForWidth());
        ZoomAdjust->setSizePolicy(sizePolicy);
        ZoomAdjust->setMinimumSize(QSize(200, 20));
        ZoomAdjust->setMaximumSize(QSize(200, 24));
        ZoomAdjust->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton  {\n"
"  background::transparent;\n"
"  border:none;\n"
"  color:#95A5A6;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  border:1px solid #f5ba9d;\n"
"  background: #fce4dc;\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(ZoomAdjust);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnZoomOut = new QPushButton(ZoomAdjust);
        btnZoomOut->setObjectName(QString::fromUtf8("btnZoomOut"));
        btnZoomOut->setMinimumSize(QSize(18, 18));
        btnZoomOut->setMaximumSize(QSize(18, 18));
        btnZoomOut->setIconSize(QSize(12, 12));

        horizontalLayout->addWidget(btnZoomOut);

        slider = new QSlider(ZoomAdjust);
        slider->setObjectName(QString::fromUtf8("slider"));
        slider->setMinimumSize(QSize(100, 12));
        slider->setMaximumSize(QSize(100, 12));
        slider->setMinimum(1);
        slider->setMaximum(200);
        slider->setValue(100);
        slider->setOrientation(Qt::Horizontal);
        slider->setTickPosition(QSlider::NoTicks);

        horizontalLayout->addWidget(slider);

        btnZoomIn = new QPushButton(ZoomAdjust);
        btnZoomIn->setObjectName(QString::fromUtf8("btnZoomIn"));
        btnZoomIn->setMinimumSize(QSize(18, 18));
        btnZoomIn->setMaximumSize(QSize(18, 18));
        btnZoomIn->setIconSize(QSize(12, 12));

        horizontalLayout->addWidget(btnZoomIn);

        editFactor = new QSpinBox(ZoomAdjust);
        editFactor->setObjectName(QString::fromUtf8("editFactor"));
        editFactor->setMinimumSize(QSize(46, 0));
        editFactor->setMaximumSize(QSize(46, 16777215));
        editFactor->setButtonSymbols(QAbstractSpinBox::NoButtons);
        editFactor->setMaximum(2400);
        editFactor->setValue(100);

        horizontalLayout->addWidget(editFactor);

        btnFit = new QPushButton(ZoomAdjust);
        btnFit->setObjectName(QString::fromUtf8("btnFit"));
        btnFit->setMinimumSize(QSize(18, 18));
        btnFit->setMaximumSize(QSize(18, 18));
        btnFit->setIconSize(QSize(12, 12));

        horizontalLayout->addWidget(btnFit);


        retranslateUi(ZoomAdjust);

        QMetaObject::connectSlotsByName(ZoomAdjust);
    } // setupUi

    void retranslateUi(QWidget *ZoomAdjust)
    {
        ZoomAdjust->setWindowTitle(QCoreApplication::translate("ZoomAdjust", "Form", nullptr));
        btnZoomOut->setText(QString());
        btnZoomIn->setText(QString());
        editFactor->setSuffix(QCoreApplication::translate("ZoomAdjust", "%", nullptr));
        btnFit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ZoomAdjust: public Ui_ZoomAdjust {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZOOMADJUST_H
