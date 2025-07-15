#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include <QScrollBar>


namespace Ui {
class Map;
}

class Map : public QMainWindow
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

    enum{point = 0,line,eraser,normal,dele,NONE};
    int cusormode = NONE;

private slots:
    void on_action_editmap_triggered();

private:
    Ui::Map *ui;


    //void on_action_editmap_triggered(); //切换地图编辑模式，显示 / 隐藏快捷工具栏
};

#endif // MAP_H
