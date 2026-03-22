#include "mainwindow.h"
#include "ui_form.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
    resize(400, 300);
}
