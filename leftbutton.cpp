#include "leftbutton.h"
#include "ui_leftbutton.h"

leftButton::leftButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::leftButton)
{
    ui->setupUi(this);

}

leftButton::~leftButton()
{
    delete ui;
}
