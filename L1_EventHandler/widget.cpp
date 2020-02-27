#include "widget.h"
#include "ui_widget.h"
#include <qdebug.h>
#include <QMenu>

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

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"mousePressEvent"<<event->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"mouseReleaseEvent"<<event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"mouseMoveEvent"<<event->pos();
}

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug()<<"closeEvent";

}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{

    qDebug()<<"contextMenuEvent"<<event->pos();

    QMenu *menu = new QMenu(this);
    menu->addAction(tr("Action1"));
    menu->addAction(tr("Action2"));
    menu->popup(mapToGlobal(event->pos()));

    qDebug()<<"Event Pos"<<event->pos();

    qDebug()<<"Reason : "<<event->reason();

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<"Key Pressed : "<<event->text();

    if(event->modifiers() & Qt::ShiftModifier)
    {
        qDebug()<<"Shift Modifier : "<<event->text();
    }

    if(event->modifiers() & Qt::ControlModifier)
    {
        qDebug()<<"Ctrl Modifier : "<<event->text();
    }
}
