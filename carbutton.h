#ifndef CARBUTTON_H
#define CARBUTTON_H

#include <QToolButton>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QDebug>

class CarButton : public QToolButton
{
    Q_OBJECT
public:
    explicit CarButton(QWidget *parent = nullptr);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // CARBUTTON_H
