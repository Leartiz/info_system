#include <QAction>
#include <QApplication>

#include "workerwindow.h"
#include "ui_workerwindow.h"

WorkerWindow::WorkerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WorkerWindow)
{
    ui->setupUi(this);

    // ui
    {
        // menu
        {
            connect(ui->actionCloseApp, &QAction::triggered,
                    qApp, &QApplication::quit);
            connect(ui->actionLogout, &QAction::triggered,
                    this, &WorkerWindow::logout);
        }
    }
}

WorkerWindow::~WorkerWindow()
{
    delete ui;
}
