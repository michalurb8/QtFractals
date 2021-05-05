#ifndef FRACTALAPP_H
#define FRACTALAPP_H

#include "fractal.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FractalApp; }
QT_END_NAMESPACE

enum colorRule {MONO, PARENT, AGE, ALPHA};

class FractalApp : public QMainWindow
{
    Q_OBJECT

public:
    FractalApp(QWidget *parent = nullptr);
    ~FractalApp();
private:
    Ui::FractalApp *ui;
    QColor backColor, fractalColor;
    Fractal fract;
    void updateColors();
    colorRule cRule;

private slots:
    void on_sliderPoints_valueChanged(int value);
    void on_buttonBackColor_clicked();
    void on_buttonFractalColor_clicked();
    void on_buttonCircle_clicked();
    void on_buttonRandom_clicked();
    void drawMore();
    void on_radioMono_clicked();
    void on_radioParent_clicked();
    void on_radioAge_clicked();
    void on_radioAlpha_clicked();
    void updateFractal();
};
#endif // FRACTALAPP_H
