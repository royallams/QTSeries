#include "childlineedit.h"
#include <QDebug>
#include <QKeyEvent>


ChildLineEdit::ChildLineEdit(QWidget *parent) : ParentLineEdit(parent)
{

}

void ChildLineEdit::keyPressEvent(QKeyEvent *event)
{
     qDebug()<< "Child Line Edit : keyPressEvent";



     if(event->key() == Qt::Key_Delete)
     {
         qDebug()<< "Delete Key Pressed";
         clear();
     }
     else{
         ParentLineEdit::keyPressEvent(event);
     }
}
