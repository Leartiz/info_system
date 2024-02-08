#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    entryWindow = new EntryWindow(this);
    entryWindow->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

