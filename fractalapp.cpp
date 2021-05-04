#include "fractalapp.h"
#include "ui_fractalapp.h"
#include <QColorDialog>

FractalApp::FractalApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FractalApp)
    , backColor("black")
    , fractalColor("red")
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
}

void FractalApp::on_buttonFractalColor_clicked()
{
    fractalColor = QColorDialog().getColor();
    updateColors();
}
