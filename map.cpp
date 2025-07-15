#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);

//    ui->editBar->setVisible(false); //开始时默认隐藏编辑栏

    connect(ui->action_editmap, &QAction::toggled, this, &Map::on_action_editmap_triggered);

}

Map::~Map()
{
    delete ui;
}




//一旦启动编辑地图按钮，侧边工具栏自动弹出 地图成为“可编辑状态”
void Map::on_action_editmap_triggered()  //切换地图编辑模式，显示 / 隐藏快捷工具栏
{
    if(ui->action_editmap->text() == "启动编辑")
    {
        ui->action_editmap->setText("退出编辑");
        ui->editBar->setVisible(true);
        cusormode = normal;
    }
    else
    {
        ui->action_editmap->setText("启动编辑");
        ui->editBar->setVisible(false);
        //ui->Mapwidget->setCursor(Qt::ArrowCursor);//设置 Qt 界面中 Mapwidget 控件的鼠标光标样式为标准箭头形状。
        cusormode = NONE;
    }
}
