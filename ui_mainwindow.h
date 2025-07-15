/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "workspace.h"
#include "wsplitter.h"
#include "zoomadjust.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *topbar;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer;
    ZoomAdjust *zoomPart;
    QWidget *widget;
    QWidget *centralContainer;
    QHBoxLayout *horizontalLayout;
    WSplitter *splitter;
    QWidget *leftPanel;
    QVBoxLayout *verticalLayout_2;
    QWidget *container;
    QVBoxLayout *verticalLayout_3;
    Workspace *workspace;
    QToolBar *leftBar;
    QDockWidget *bottomDock;
    QWidget *dockWidgetContents;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(592, 541);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topbar = new QWidget(centralWidget);
        topbar->setObjectName(QString::fromUtf8("topbar"));
        topbar->setMinimumSize(QSize(0, 32));
        topbar->setMaximumSize(QSize(16777215, 32));
        topbar->setStyleSheet(QString::fromUtf8("#topbar{\n"
"border: 1px solid none;\n"
"border-bottom-color:black;\n"
"}\n"
""));
        horizontalLayout_3 = new QHBoxLayout(topbar);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(topbar);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_3->addWidget(label_13, 0, Qt::AlignRight);

        horizontalSpacer = new QSpacerItem(285, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        zoomPart = new ZoomAdjust(topbar);
        zoomPart->setObjectName(QString::fromUtf8("zoomPart"));
        zoomPart->setMinimumSize(QSize(200, 0));
        zoomPart->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_3->addWidget(zoomPart);

        widget = new QWidget(topbar);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(12, 0));

        horizontalLayout_3->addWidget(widget);


        verticalLayout->addWidget(topbar);

        centralContainer = new QWidget(centralWidget);
        centralContainer->setObjectName(QString::fromUtf8("centralContainer"));
        horizontalLayout = new QHBoxLayout(centralContainer);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new WSplitter(centralContainer);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setLineWidth(0);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(true);
        splitter->setHandleWidth(1);
        leftPanel = new QWidget(splitter);
        leftPanel->setObjectName(QString::fromUtf8("leftPanel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftPanel->sizePolicy().hasHeightForWidth());
        leftPanel->setSizePolicy(sizePolicy);
        leftPanel->setMaximumSize(QSize(250, 16777215));
        leftPanel->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(leftPanel);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(leftPanel);
        container = new QWidget(splitter);
        container->setObjectName(QString::fromUtf8("container"));
        sizePolicy.setHeightForWidth(container->sizePolicy().hasHeightForWidth());
        container->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(container);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        workspace = new Workspace(container);
        workspace->setObjectName(QString::fromUtf8("workspace"));

        verticalLayout_3->addWidget(workspace);

        splitter->addWidget(container);

        horizontalLayout->addWidget(splitter);


        verticalLayout->addWidget(centralContainer);

        MainWindow->setCentralWidget(centralWidget);
        leftBar = new QToolBar(MainWindow);
        leftBar->setObjectName(QString::fromUtf8("leftBar"));
        leftBar->setMinimumSize(QSize(0, 0));
        leftBar->setMaximumSize(QSize(40, 16777215));
        leftBar->setBaseSize(QSize(0, 0));
        leftBar->setStyleSheet(QString::fromUtf8(""));
        leftBar->setMovable(false);
        leftBar->setAllowedAreas(Qt::LeftToolBarArea);
        leftBar->setOrientation(Qt::Vertical);
        leftBar->setIconSize(QSize(18, 18));
        leftBar->setFloatable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, leftBar);
        bottomDock = new QDockWidget(MainWindow);
        bottomDock->setObjectName(QString::fromUtf8("bottomDock"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        bottomDock->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::BottomDockWidgetArea, bottomDock);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        leftBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
