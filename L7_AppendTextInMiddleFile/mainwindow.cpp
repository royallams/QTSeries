#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //read from file

    QDir().setCurrent(QCoreApplication::applicationDirPath());
       QFile inFile("final_alsim.nas");
       if (!inFile.exists()) {
           qDebug() << "file doesn't exist";
           return;
       }
       qDebug() << "file exist";


       if (!inFile.open(QIODevice::ReadOnly)) {
           qDebug() << "can't open inFile";
           return;
       }
       qDebug() << "file opened";

       // ready all data
        QByteArray in = inFile.readAll();

       inFile.close();
       qDebug() << "file read all into bytearray";



       auto last_postion = in.length();
       auto to_append_postion = last_postion -9                                                                                                                                         ;

       in.insert(to_append_postion,"\n\nHi this is Royal\n\n");

       // write into file
       QFile outFile("final_alsim_appended.nas");
       if (!outFile.open(QIODevice::WriteOnly)) {
           qDebug() << "can't open outFile";
           return;
       }
       qDebug() << "file written succesfully";

       outFile.write(in);
       outFile.close();

}
