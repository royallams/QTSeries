#include "button.h"
#include <QMouseEvent>
#include <QDebug>

Button::Button(QWidget *parent) : QPushButton(parent)
{
}

void Button::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"Button : Mouse pressed at : "<< event->pos();
    QPushButton::mousePressEvent(event);

}

void Button::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"Button : Mouse released at : "<< event->pos();
    QPushButton::mouseReleaseEvent(event);
}

void Button::mouseMoveEvent(QMouseEvent *event)
{

    qDebug()<<"Button : Mouse moved at : "<< event->pos();
    QPushButton::mouseMoveEvent(event);
}
