#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFutureWatcher>
#include <QFuture>
#include <QDebug>
#include <QThread>
#include <QtConcurrent/QtConcurrent>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    static QFuture<QVector<int>> HeavyWorkWithReturn();
private slots:
    void on_pushButton_Start__clicked();

    void on_pushButton_Resume__clicked();

    void on_pushButton_Pause__clicked();

    void on_pushButton_Cancel__clicked();

private:
    Ui::Widget *ui;
    QFuture<QVector<int>> future_;
    QFutureWatcher<QVector<int>> watcher_;
 };

#endif // WIDGET_H
