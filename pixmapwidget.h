#ifndef PIXMAPWIDGET_H
#define PIXMAPWIDGET_H

#include <QWidget>
#include <QPixmap>

class PixmapWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PixmapWidget(QWidget *parent = nullptr);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    QPixmap pixmap;

};

#endif // PIXMAPWIDGET_H
