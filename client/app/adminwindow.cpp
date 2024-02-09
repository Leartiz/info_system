#include "adduserwindow.h"
#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    {
        connect(ui->pushBtnAdd, &QPushButton::clicked,
                this, &AdminWindow::onClicked_pushBtnAdd);
    }
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

// -----------------------------------------------------------------------

void AdminWindow::onClicked_pushBtnAdd()
{
    auto window = new AddUserWindow(this);

    window->setModal(true);
    window->exec();
}
