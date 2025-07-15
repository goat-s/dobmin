#include "leftbar.h"
#include "ui_leftbar.h"

leftbar::leftbar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::leftbar)
{
    ui->setupUi(this);
}

leftbar::~leftbar()
{
    delete ui;
}
