#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<< "UI Thread : "<<QThread::currentThread();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::RunHeavyWork()
{
    qDebug()<<"Running Heavy Work"<<QThread::currentThread();
    for(int i = 0 ;i<10000000000;i++)
    {
        if((i%100000)== 0){

            double percentage  = ((i/1000000000.0))*100;
            qDebug()<<"Percentage : " <<QVariant::fromValue(percentage).toInt()
                    <<"| Thread : " <<QThread::currentThread();

        }

    }

}

void MainWindow::on_pushButton_Start_clicked()
{
     future_ = QtConcurrent::run(RunHeavyWork);
     future_.waitForFinished();
     qDebug()<< "Computation Done";
}

void MainWindow::on_pushButton_Cancel_clicked()
{

}

void MainWindow::on_pushButton_Pause_clicked()
{

}

void MainWindow::on_pushButton_Resume_clicked()
{

}
