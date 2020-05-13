#include "myapp.h"
#include <QDebug>
#include "mywidget.h"


MyApp::MyApp(int argc, char *argv[]) : QApplication(argc, argv)
{

}

bool MyApp::notify(QObject *dest, QEvent *event)
{
    qDebug()<<"notify called";

    MyWidget *cast_widget = dynamic_cast<MyWidget*>(dest);
    if(cast_widget)
        qDebug()<<"Cast success";
    else
        qDebug()<<"Cast Failed";




    qDebug()<<"ACTUAL OBJECT : " << dest->metaObject()->className();
    return QApplication::notify( dest, event);
}
