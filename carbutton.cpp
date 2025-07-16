#include "carbutton.h"

CarButton::CarButton(QWidget *parent)
    : QToolButton(parent)
{
}

void CarButton::mouseMoveEvent(QMouseEvent *event)
{
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
