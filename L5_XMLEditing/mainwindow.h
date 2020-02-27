#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString EditTheLine(QString &line);
    unsigned int new_meta_id_start_;
    unsigned int new_meta_id_start_bottom_;

    unsigned int original_meta_id_count_;
    unsigned int original_meta_id_count_bottom_;


};


#endif // MAINWINDOW_H
