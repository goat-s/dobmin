#ifndef EASERBUTTON_H
#define EASERBUTTON_H

#include <QToolButton>

class easerButton : public QToolButton
{
    Q_OBJECT
public:
    explicit easerButton(QWidget *parent = nullptr);
    // 你可以在这里添加自定义属性、方法、信号槽
};

#endif // EASERBUTTON_H 