#ifndef PARENTBUTTON_H
#define PARENTBUTTON_H

#include <QPushButton>

class ParentButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ParentButton(QWidget *parent = 0);

signals:

public slots:

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // PARENTBUTTON_H
