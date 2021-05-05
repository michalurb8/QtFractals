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
    void putPixel(QPoint point, QColor color);
    void resizeEvent(QResizeEvent* e) override;
    QColor getColor(QPoint point);
    void setBackColor(QColor color);

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    QPixmap pixmap;
    QImage image;
    QColor backColor;

public slots:
    void clear();
    void save();

signals:
    void resized();
};

#endif // PIXMAPWIDGET_H
