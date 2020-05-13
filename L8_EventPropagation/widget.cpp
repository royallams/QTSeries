#include "widget.h"
#include "ui_widget.h"
#include "childbutton.h"
#include "childlineedit.h"
#include <QDebug>

widget::widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);

    ChildButton *child_button = new ChildButton(this);
    child_button->setText("Test Signal propagation");
    connect(child_button, &ChildButton::clicked, [=](){
       qDebug()<<" Button is clicked!!";
    });

    ChildLineEdit *child_line_edit = new ChildLineEdit(this);

    ui->verticalLayout->addWidget(child_button);
    ui->verticalLayout->addWidget(child_line_edit);
}

widget::~widget()
{
    delete ui;
}
