#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pix_map(width()-10,height()-10);
    pix_map.fill(Qt::green);

    QPen pen;
    pen.setColor(Qt::red);
    QPainter painter(&pix_map);
    painter.setPen(pen);
    painter.setBrush(Qt::yellow);
    painter.drawRect(50,50,100,100);

    QFont font("Consolas",20,QFont::Bold);
    painter.setFont(font);
    painter.drawText(30,120,"Hi THIS IS AWESOME");
    ui->label->setPixmap(pix_map);

}

Widget::~Widget()
{
    delete ui;
}
