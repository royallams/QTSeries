#include "keyboardfilter.h"
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>

KeyboardFilter::KeyboardFilter(QObject *parent) : QObject(parent)
{

}

bool KeyboardFilter::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *key_event = dynamic_cast<QKeyEvent*>(event);
        QString numbers  = QString("1234567890");
        if(numbers.indexOf(key_event->text()) != -1)
        {
            qDebug()<<"Numbers filtered out!!";
            return false; //dont propagate to the parent
        }
    }


    return QObject::eventFilter(watched, event);
}
