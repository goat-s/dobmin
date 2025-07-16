#include "leftbar.h"
#include "ui_leftbar.h"
#include "carbutton.h"
#include <QFile>
#include <QDebug>

leftbar::leftbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::leftbar)
{
    ui->setupUi(this);

}

void leftbar::on_curserButton_clicked()
{
    emit toolChanged(Tool_Select);
}

void leftbar::on_carButton_clicked()
{
    emit toolChanged(Tool_DrawCar);
}

void leftbar::on_eraserButton_clicked()
{
    emit toolChanged(Tool_Eraser);
}

leftbar::~leftbar()
{
    delete ui;
}

