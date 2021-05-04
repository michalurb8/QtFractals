#include "pixmapwidget.h"
#include <QPainter>

PixmapWidget::PixmapWidget(QWidget *parent) : QWidget(parent)
{
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

}

QSize PixmapWidget::sizeHint() const
{
    return QSize(200,200);
}

QSize PixmapWidget::minimumSizeHint() const
{
    return QSize(50,50);
}

void PixmapWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::black);
}
