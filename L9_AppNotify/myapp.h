#ifndef MYAPP_H
#define MYAPP_H

#include <QApplication>

class MyApp : public QApplication
{
    Q_OBJECT
public:
    explicit MyApp(int argc, char *argv[]);

signals:

public slots:

    // QCoreApplication interface
public:
    bool notify(QObject *dest, QEvent *event);
};

#endif // MYAPP_H
