#ifndef PARENTLINEEDIT_H
#define PARENTLINEEDIT_H

#include <QLineEdit>

class ParentLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit ParentLineEdit(QWidget *parent = 0);

signals:

public slots:

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // PARENTLINEEDIT_H
