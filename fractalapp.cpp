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

