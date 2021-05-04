#include "pixmapwidget.h"

PixmapWidget::PixmapWidget(QWidget *parent)
    : QWidget(parent)
    , backColor(Qt::blue)
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

void PixmapWidget::paintEvent(QPaintEvent*)
{

    QPainter painter(this);
    painter.fillRect(rect(), backColor);
    image = QImage(this->size()/2, QImage::Format_RGBA64);
    image.fill(qRgba(0,0,0,0));
    pixmap = QPixmap::fromImage(image);
    painter.drawPixmap(QPoint(0,0),pixmap);
}
