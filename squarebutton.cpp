#include "squarebutton.h"

SquareButton::SquareButton(QWidget* parent)
    :QPushButton(parent)
{

}

void SquareButton::resizeEvent(QResizeEvent* e)
{
    int minDim = height() < width() ? height() : width();
    resize(minDim, minDim);
}

SquareButton::~SquareButton()
{
}

QSize SquareButton::sizeHint()
{
    int minDim = height() < width() ? height() : width();
    return QSize(minDim, minDim);
}
