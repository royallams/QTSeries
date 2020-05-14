#include "widget.h"
#include "ui_widget.h"
#include "keyboardfilter.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    KeyboardFilter * key_filter = new KeyboardFilter(this);
    ui->lineEdit->installEventFilter(key_filter);
}

Widget::~Widget()
{
    delete ui;
}
