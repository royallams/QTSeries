#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    button1_ = new Button(this);
    button1_->setText("button1");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QMouseEvent * event = new QMouseEvent(QEvent::MouseButtonPress, QPointF(10,10), Qt::LeftButton,
                                          Qt::LeftButton , Qt::NoModifier);
    //Send : directly
    if(QApplication::sendEvent(button1_, event)){
        qDebug()<<" Event acccepted";
    }

//    //Post :  in queue
//    if(QApplication::sendEvent(button1_, event)){
//        qDebug()<<" Event acccepted";
//    }

}
