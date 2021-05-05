#include "fractalapp.h"
#include "ui_fractalapp.h"
#include <QColorDialog>
#include <iostream>

FractalApp::FractalApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FractalApp)
    , backColor("black")
    , fractalColor("red")
    , cRule(MONO)
{
    ui->setupUi(this);
    updateColors();
}

FractalApp::~FractalApp()
{
    delete ui;
}

void FractalApp::updateColors()
{
    QString style = "background-color: " + backColor.name();
    ui->buttonBackColor->setStyleSheet(style);
    style = "background-color: " + fractalColor.name();
    ui->buttonFractalColor->setStyleSheet(style);
}

void FractalApp::on_sliderPoints_valueChanged(int value)
{
    ui->sliderStep->setRange(0,value-1);
    ui->sliderOffset->setRange(0,value-1);
    ui->spinStep->setRange(0,value-1);
    ui->spinOffset->setRange(0,value-1);
}

void FractalApp::on_buttonBackColor_clicked()
{
    backColor = QColorDialog().getColor();
    updateColors();
    ui->pixmapwidget->setBackColor(backColor);
    ui->pixmapwidget->update();
}

void FractalApp::on_buttonFractalColor_clicked()
{
    fractalColor = QColorDialog().getColor();
    updateColors();
}

void FractalApp::drawMore()
{
    int iterNum = ui->spinIterations->value()*10000;
    QColor newColor = fractalColor;
    QColor prevColor;
    float hue;
    int newAlpha;
    for(int i = 0; i < iterNum; ++i)
    {
        QPoint point = QPoint(fract.getX(), fract.getY());
        hue = fract.getParent();
        fract.generateNextPoint();
        switch(cRule)
        {
        default:
        case ALPHA:
            prevColor = ui->pixmapwidget->getColor(point);
            newAlpha = prevColor.alpha()+5;
            newAlpha = qMin(255, newAlpha);
            newColor.setAlpha(newAlpha);
            break;
        case MONO:
            break;
        case AGE:
            hue = fract.getAge()/10000;
            newColor.setHsv(hue,255,255);
            break;
        case PARENT:
//            hue = fract.getParent();
            newColor.setHsv(hue*255,255,255);
            break;
        }
        ui->pixmapwidget->putPixel(point, newColor);
    }
}

void FractalApp::on_buttonCircle_clicked()
{
    float minDim = qMin(ui->pixmapwidget->width(), ui->pixmapwidget->height());
    fract.setupAttractors(minDim/2, CIRCLE);
    update();
}

void FractalApp::on_buttonRandom_clicked()
{
    float minDim = qMin(ui->pixmapwidget->width(), ui->pixmapwidget->height());
    fract.setupAttractors(minDim/2, RANDOM);
    update();
}

void FractalApp::on_buttonRCircle_clicked()
{
    float minDim = qMin(ui->pixmapwidget->width(), ui->pixmapwidget->height());
    fract.setupAttractors(minDim/2, NOISE);
    update();
}

void FractalApp::on_radioMono_clicked()
{
    cRule = MONO;
}

void FractalApp::on_radioParent_clicked()
{
    cRule = PARENT;
}


void FractalApp::on_radioAge_clicked()
{
    cRule = AGE;
}

void FractalApp::on_radioAlpha_clicked()
{
    cRule = ALPHA;
}

void FractalApp::updateFractal()
{
    int points = ui->sliderPoints->value();
    int step = ui->sliderStep->value();
    int offset = ui->sliderOffset->value();
    int minDim = qMin(ui->pixmapwidget->width(), ui->pixmapwidget->height());
    fract.updateParams(points, step, offset);
    fract.setupAttractors(minDim/2.5, CIRCLE);
}
