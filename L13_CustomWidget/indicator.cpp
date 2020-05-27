#include "indicator.h"
#include <QPainter>
#include <QPen>
#include <QBrush>


Indicator::Indicator(QWidget *parent)
    : QWidget(parent),
      red_active_(false),
      green_active_(false),
      yellow_active_(false),
       active_off_(true)
{
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred));
    yellow_active_= true;

    timer_ = new QTimer(this);

}

void Indicator::paintEvent(QPaintEvent *event)
{
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::black);


    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(Qt::gray);

    painter.drawRect(QRect(0,0,120,330));









    if(red_active_)
    {
        painter.setBrush(Qt::red);
        painter.drawEllipse(10,10,100,100);
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,115, 100,100);
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,220, 100,100);


    }
    if(green_active_)
    {
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,10,100,100);
        painter.setBrush(Qt::green);
        painter.drawEllipse(10,115, 100,100);
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,220, 100,100);
    }
    if(yellow_active_)
    {
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,10,100,100);
        painter.setBrush(Qt::black);
        painter.drawEllipse(10,115, 100,100);
        painter.setBrush(Qt::yellow);
        painter.drawEllipse(10,220, 100,100);
    }



}

QSize Indicator::sizeHint() const
{
    return QSize(120,350);
}
