#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>
#include <QTimer>

class Indicator : public QWidget
{
    Q_OBJECT
public:
    explicit Indicator(QWidget *parent = 0);

signals:

public slots:

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

    // QWidget interface
public:
    QSize sizeHint() const;
    bool green_active_;
    bool red_active_;
    bool yellow_active_;
    bool active_off_;
    QTimer *timer_;
};

#endif // INDICATOR_H
