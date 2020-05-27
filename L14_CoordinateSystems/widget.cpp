#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPen pen;
    pen.setWidth(3);

    QPainter painter(this);
    painter.setPen(pen);


    qDebug()<<"Logical coordinate :"<<painter.window();
    qDebug()<<"Physical coordinate :"<<painter.viewport();


    painter.drawRect(50,50, 100,100);

    painter.save();//saves the state in the stack
    // Change the logical keep the physical same
    painter.setWindow(0,0,300,200);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawRect(50,50,100,100);//Larger this is the physical coordinat or view port
    painter.restore();

    // Change the physical and keep the logical same
    painter.save();
    painter.setViewport(0,0,200,50);
    painter.setPen(Qt::blue);
    painter.drawRect(50,50,100,100);
    painter.restore();








}
