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
    enum ToolType { Tool_Select = 0, Tool_DrawCar = 1, Tool_Eraser = 2 /*, Tool_DrawLine, ...*/ };

signals:
    void toolChanged(ToolType type);

public:
    explicit leftbar(QWidget *parent = nullptr);
    ~leftbar();

private slots:
    void on_curserButton_clicked();
    void on_carButton_clicked();
    void on_eraserButton_clicked();

private:
    Ui::leftbar *ui;
};

#endif // LEFTBAR_H
