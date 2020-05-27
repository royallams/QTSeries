#ifndef MYQOBJECT_H
#define MYQOBJECT_H

#include <QObject>

class MyQobject : public QObject
{
    Q_OBJECT
public:
    explicit MyQobject(QObject *parent = 0);

signals:

public slots:
};

#endif // MYQOBJECT_H