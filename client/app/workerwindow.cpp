#include "workerwindow.h"
#include "ui_workerwindow.h"

WorkerWindow::WorkerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkerWindow)
{
    ui->setupUi(this);
}

WorkerWindow::~WorkerWindow()
{
    delete ui;
}
