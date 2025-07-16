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
    explicit CarButton(QWidget *parent = nullptr) : QToolButton(parent) {}

protected:
    void mouseMoveEvent(QMouseEvent *event) override {
        qDebug() << "[CarButton] mouseMoveEvent triggered";
        if (event->buttons() & Qt::LeftButton) {
            QMimeData *mimeData = new QMimeData;
            mimeData->setData("application/x-car", QByteArray("car"));
            QDrag *drag = new QDrag(this);
            drag->setMimeData(mimeData);
            drag->setPixmap(this->icon().pixmap(32, 32));
            qDebug() << "[CarButton] start drag";
            drag->exec(Qt::CopyAction);
        }
        QToolButton::mouseMoveEvent(event);
    }
};

#endif // CARBUTTON_H
