#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFuture>
#include <QThread>
#include <QDebug>
#include <QtConcurrent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static void RunHeavyWork();
private slots:
    void on_pushButton_Start_clicked();

    void on_pushButton_Cancel_clicked();

    void on_pushButton_Pause_clicked();

    void on_pushButton_Resume_clicked();

private:
    Ui::MainWindow *ui;
    QFuture<void> future_;
};

#endif // MAINWINDOW_H
