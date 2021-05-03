#include "fractalapp.h"
#include "ui_fractalapp.h"

FractalApp::FractalApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FractalApp)
{
    ui->setupUi(this);
}

FractalApp::~FractalApp()
{
    delete ui;
}

void FractalApp::on_sliderPoints_valueChanged(int value)
{
    ui->sliderStep->setRange(0,value-1);
    ui->sliderOffset->setRange(0,value-1);
    ui->spinStep->setRange(0,value-1);
    ui->spinOffset->setRange(0,value-1);
}
