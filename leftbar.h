#ifndef LEFTBAR_H
#define LEFTBAR_H

#include <QWidget>
#include "carbutton.h"//实现小车拖拽

namespace Ui {
class leftbar;
}

class leftbar : public QWidget
{
    Q_OBJECT

public:
    explicit leftbar(QWidget *parent = nullptr);
    ~leftbar();

private:
    Ui::leftbar *ui;
};

#endif // LEFTBAR_H
