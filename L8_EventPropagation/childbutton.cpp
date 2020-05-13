#include "childbutton.h"
#include <QDebug>

ChildButton::ChildButton(QWidget *parent) : ParentButton(parent)
{

}

void ChildButton::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<" Child Button : mousePressEvent called ";

    ParentButton::mousePressEvent(event);//Must propagate back to the parent(QPushButton)  else slots will be inactive
}
