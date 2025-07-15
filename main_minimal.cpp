#include "mainwindow.h"
#include "preferences.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//创建QApplication应用程序对象
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);//Qt 配置  开启高清图像支持，提升视觉体验
    Preferences::instance();//初始化全局配置系统（Preferences单例）
    MainWindow w;//创建主窗口对象
    w.showMaximized();//最大化显示主窗口
    w.init();//调用主窗口初始化方法
    return a.exec();//进入事件循环
}
