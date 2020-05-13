#include "parentbutton.h"
#include <QDebug>


ParentButton::ParentButton(QWidget *parent) : QPushButton(parent)
{

}

void ParentButton::mousePressEvent(QMouseEvent *event)
{
       qDebug()<< "Parent Button :  mousePressEvent called ";

       // Must propagate to the parent class ..otherwise the slots wont work.
       QPushButton::mousePressEvent(event);
}
