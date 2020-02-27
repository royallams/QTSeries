#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    original_meta_id_count_ = 1;
    original_meta_id_count_bottom_ = 1;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    new_meta_id_start_ = ui->lineEdit->text().toInt();
    new_meta_id_start_bottom_ = ui->lineEdit->text().toInt();

    QString file_path = ui->lineEdit_file_path_->text();


    QString msg = "File Path :"+file_path;
    qDebug()<<msg;
    ui->plainTextEdit->setPlainText(msg);

    msg =  "Meta ID :"+new_meta_id_start_;
    qDebug()<<msg;
    ui->plainTextEdit->appendPlainText(msg);


    QFile inputFile(file_path);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        msg = "Input  File Open Failed :";
        qDebug()<<msg;
        ui->plainTextEdit->appendPlainText(msg);

        return;
    }

    QString ext_removed = file_path;
    ext_removed.remove(".xml");
    QString out_file = ext_removed+"_EDITED.xml";
    QFile outputFile(out_file);
    if(!outputFile.open(QIODevice::WriteOnly))
    {
        msg = "Output File Creatio Failed :";
        qDebug()<<msg;
        ui->plainTextEdit->appendPlainText(msg);

        return;
    }


    QTextStream inputStream(&inputFile);
    QTextStream outStream(&outputFile);

    while (!inputStream.atEnd()) {
        qDebug()<<"File reading..";

        QString line = inputFile.readLine();
        QString edited_line = EditTheLine(line);
        outStream<<edited_line;

    }

    msg = "File Read and Write FINISHED";
    qDebug()<<msg;
    ui->plainTextEdit->appendPlainText(msg);

    outputFile.close();
    inputFile.close();

}

QString MainWindow::EditTheLine(QString &line)
{
    QString new_line;
    //Prepare the original Meta ID string
    QString meta_id_string = QString::number(original_meta_id_count_);
    QString meta_id_string_bottom = QString::number(original_meta_id_count_bottom_);

    QString meta_id_full_name_in_tree = "METADATA_ID=\""+meta_id_string+"\"";
    QString meta_id_full_name_in_bottom = "METADATA ID=\""+meta_id_string_bottom+"\"";

    QString new_meta_id_string = QString::number(new_meta_id_start_);
    QString new_meta_id_string_bottom = QString::number(new_meta_id_start_bottom_);

    QString new_name_in_tree = "METADATA_ID=\""+new_meta_id_string+"\"";
    QString new_name_in_bottom = "METADATA ID=\""+new_meta_id_string_bottom+"\"";



    QString msg;


     if(line.contains(meta_id_full_name_in_tree))
    {
        line.replace(meta_id_full_name_in_tree, new_name_in_tree);
        msg = "TOP"+meta_id_full_name_in_tree
                  +"replaced with "
                 +"TOP NEW"+new_name_in_tree;
        qDebug()<<msg;
        ui->plainTextEdit->appendPlainText(msg);

        original_meta_id_count_++;
        new_meta_id_start_++;

     }
    if(line.contains(meta_id_full_name_in_bottom))
    {
        line.replace(meta_id_full_name_in_bottom, new_name_in_bottom);
        msg = "BOTTOM"+meta_id_full_name_in_bottom
                     +"replaced with "
                    +"BOTTOM NEW"+new_name_in_bottom;
        qDebug()<<msg;
        ui->plainTextEdit->appendPlainText(msg);
        original_meta_id_count_bottom_++;
        new_meta_id_start_bottom_++;
    }



    new_line = line;

    return new_line;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString file_path ;

    file_path = QFileDialog::getOpenFileName(this,
                                             tr("Open XML"), "/home/", tr("XML Files (*.xml *.XML)"));
    ui->lineEdit_file_path_->setText(file_path);

}
