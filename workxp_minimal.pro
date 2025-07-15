#-------------------------------------------------
#
# Project created by QtCreator 2018-07-09T21:57:40
#
#-------------------------------------------------

QT       += core gui core-private gui-private svg-private

DESTDIR = $$PWD/bin #执行程序可执行目录
              $$PWD/libmodbus
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = workxp_minimal
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        getjson.cpp \
        leftbar.cpp \
        main_minimal.cpp \
        mainwindow.cpp \
        map.cpp \
        workspace.cpp \
        basespace.cpp \
        rulebar.cpp \
        wsplitter.cpp \
        zoomadjust.cpp \
        preferences.cpp

HEADERS += \
        getjson.h \
        leftbar.h \
        mainwindow.h \
        map.h \
        workspace.h \
        rulebar.h \
        basespace.h \
        wsplitter.h \
        zoomadjust.h \
        preferences.h \
        commondef.h

FORMS += \
        leftbar.ui \
        mainwindow.ui \
        map.ui \
        zoomadjust.ui

include(./QtAwesome/QtAwesome_minimal.pri)

# 只包含必要的QtMaterial组件
INCLUDEPATH += $$PWD/QtMaterialWidgets
SOURCES += \
    $$PWD/QtMaterialWidgets/lib/qtmaterialoverlaywidget.cpp \
    $$PWD/QtMaterialWidgets/qtmaterialdrawer.cpp \
    $$PWD/QtMaterialWidgets/qtmaterialdrawer_internal.cpp

HEADERS += \
    $$PWD/QtMaterialWidgets/lib/qtmaterialoverlaywidget.h \
    $$PWD/QtMaterialWidgets/qtmaterialdrawer.h \
    $$PWD/QtMaterialWidgets/qtmaterialdrawer_p.h \
    $$PWD/QtMaterialWidgets/qtmaterialdrawer_internal.h

RESOURCES += \
    res.qrc \
    resources.qrc \
    resources_minimal.qrc \
    style.qrc

TRANSLATIONS += translations/wxp_zh.ts

DISTFILES += \
    Icon/24gl-errorCircle.png \
    Icon/24gl-pauseCircle (1).png \
    Icon/2dmap.png \
    Icon/CancelNavi.png \
    Icon/FreeNavigation.png \
    Icon/PathNavi.png \
    Icon/PauseNavi.png \
    Icon/background.png \
    Icon/delete.png \
    Icon/edit.png \
    Icon/eraser.png \
    Icon/gis-nav (1).png \
    Icon/musiclist.png \
    Icon/next.png \
    Icon/open.png \
    Icon/order.png \
    Icon/pause.png \
    Icon/play.png \
    Icon/pointer.png \
    Icon/pot.png \
    Icon/revolve.png \
    Icon/route.png \
    Icon/setting.png \
    Icon/titleicon.png \
    Icon/地点定位_o (1).png \
    Icon/地点定位_o.png \
    Icon/导航 (1).png
