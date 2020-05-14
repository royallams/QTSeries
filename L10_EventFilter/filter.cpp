#include "filter.h"
#include <QEvent>
#include <QDebug>

Filter::Filter(QObject *parent) : QObject(parent)
{

}

bool Filter::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress
        || event->type() == QEvent::MouseButtonDblClick){

        qDebug()<<"Event Hijacked";
//        return true; //Event handle no need to notify original destination
        return false; //Event handle should notify original destination...button click will work now


    }

    return QObject::eventFilter(watched, event);
}
