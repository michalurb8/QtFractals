#include "pixmapwidget.h"
#include <ctime>

PixmapWidget::PixmapWidget(QWidget *parent)
    : QWidget(parent)
    , backColor(Qt::black)
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

void PixmapWidget::putPixel(QPoint point, QColor color)
{
    int x = point.x();
    int y = point.y();
    x += image.width()/2;
    y = image.height()/2 - y;
    point = QPoint(x,y);
    image.setPixelColor(point, color);
    update();
}

void PixmapWidget::resizeEvent(QResizeEvent*)
{
    int minDim = qMin(height(), width());
    image = QImage(QSize(minDim, minDim), QImage::Format_RGBA64);
    clear();
    emit resized();
}

QColor PixmapWidget::getColor(QPoint point)
{
    int x = point.x();
    int y = point.y();
    x += image.width()/2;
    y = image.height()/2 - y;
    point = QPoint(x,y);
    return image.pixelColor(point);
}

void PixmapWidget::setBackColor(QColor color)
{
    backColor = color;
}

void PixmapWidget::clear()
{
    image.fill(qRgba(255,255,255,0));
    update();
}

void PixmapWidget::save()
{
    QImage background = QImage(image);
    background.fill(backColor);
    QPainter painter(&background);
    painter.drawImage(QPoint(0,0), image);
    QString name = "img"+QString::number(time(NULL))+".bmp";
    background.save(name);
}

void PixmapWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.fillRect(rect(), backColor);
    pixmap = QPixmap::fromImage(image);
    QPoint offset = width() > height() ? QPoint(width()-height(), 0)/2 : QPoint(0,-width()+height())/2;
    painter.drawPixmap(offset, pixmap);
}
