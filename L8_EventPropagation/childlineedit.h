#ifndef CHILDLINEEDIT_H
#define CHILDLINEEDIT_H

#include <parentlineedit.h>

class ChildLineEdit : public ParentLineEdit
{
    Q_OBJECT
public:
    explicit ChildLineEdit(QWidget *parent = 0);

signals:

public slots:

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // CHILDLINEEDIT_H
