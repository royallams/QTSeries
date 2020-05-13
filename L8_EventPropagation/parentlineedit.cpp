#include "parentlineedit.h"
#include <QDebug>


ParentLineEdit::ParentLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

void ParentLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"Parent Line Edit : keyPressEvent called";

    QLineEdit::keyPressEvent(event);
}
