#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug()<<"UI Thread "<<QThread::currentThread();
    connect(&watcher_,&QFutureWatcher<void>::finished,[=](){

        qDebug()<<"Computation done";
        QVector<int>resultVector = watcher_.result();

        if(!watcher_.isCanceled())
        {
            for (int i =0 ; i<resultVector.count();i++)
            {
                qDebug()<<"element ["<< i<<"]:"<<resultVector[i];
            }
        }
        else
        {
            qDebug()<<"Watcher is already cancelled";
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

QFuture<QVector<int> > Widget::HeavyWorkWithReturn()
{
    auto heavyWork = [=](){

        QVector<int> int_vector;
        qDebug()<<"Running Heavy Work"<<QThread::currentThread();
        for(int i = 0 ;i<100000001;i++)
        {
            if((i%100000)== 0){

                double percentage  = ((i/10000000.0))*100;
                qDebug()<<"Percentage : " <<QVariant::fromValue(percentage).toInt()
                        <<"| Thread : " <<QThread::currentThread();

                int_vector.push_back(QVariant::fromValue(percentage).toInt());

            }

        }
        return int_vector;
    };

    return QtConcurrent::run(heavyWork);
}

void Widget::on_pushButton_Start__clicked()
{
     future_ = HeavyWorkWithReturn();

    watcher_.setFuture(future_);
}

void Widget::on_pushButton_Resume__clicked()
{

}

void Widget::on_pushButton_Pause__clicked()
{

}

void Widget::on_pushButton_Cancel__clicked()
{

}
