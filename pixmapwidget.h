#ifndef PIXMAPWIDGET_H
#define PIXMAPWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QImage>
#include <QColor>
#include <QPainter>

class PixmapWidget : public QWidget
{
    Q_OBJECT
public:
    PixmapWidget(QWidget *parent = nullptr);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    QPixmap pixmap;
    QImage image;
    QColor backColor;
};

#endif // PIXMAPWIDGET_H
