#include "entrywindow.h"
#include "ui_entrywindow.h"

EntryWindow::EntryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryWindow)
{
    ui->setupUi(this);
}

EntryWindow::~EntryWindow()
{
    delete ui;
}
