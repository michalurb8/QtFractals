#ifndef FRACTALAPP_H
#define FRACTALAPP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FractalApp; }
QT_END_NAMESPACE

class FractalApp : public QMainWindow
{
    Q_OBJECT

public:
    FractalApp(QWidget *parent = nullptr);
    ~FractalApp();

private:
    Ui::FractalApp *ui;
};
#endif // FRACTALAPP_H
