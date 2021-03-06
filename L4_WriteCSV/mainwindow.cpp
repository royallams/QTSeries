#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    // prepare data that you want to save to csv-file
        QStringList strList;
        strList << "one" << "two" << "three";

        QtCSV::StringData strData;
        strData.addRow(strList);
        strData.addEmptyRow();
        strData << strList << "this is the last row";

        // write to file
        QString filePath = QDir::currentPath() + "/test.csv";
        QtCSV::Writer::write(filePath, strData);

        // read data from file
        QList<QStringList> readData = QtCSV::Reader::readToList(filePath);
        for ( int i = 0; i < readData.size(); ++i )
        {
            qDebug() << readData.at(i).join(",");
        }
}
