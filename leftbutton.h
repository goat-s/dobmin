#ifndef LEFTBUTTON_H
#define LEFTBUTTON_H

#include <QWidget>

namespace Ui {
class leftButton;
}

class leftButton : public QWidget
{
    Q_OBJECT

public:
    explicit leftButton(QWidget *parent = nullptr);
    ~leftButton();

private:
    Ui::leftButton *ui;
};

#endif // LEFTBUTTON_H
