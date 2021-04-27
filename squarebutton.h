#ifndef SQUAREBUTTON_H
#define SQUAREBUTTON_H

#include <QPushButton>

class SquareButton : public QPushButton
{
    Q_OBJECT
public:
    explicit SquareButton(QWidget* parent = 0);
    void resizeEvent(QResizeEvent* e);
    virtual ~SquareButton();
    QSize sizeHint();
};

#endif // SQUAREBUTTON_H
