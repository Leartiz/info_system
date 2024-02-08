#include <QDebug>
#include <QMessageBox>
#include <QValidator>

#include "entrywindow.h"
#include "ui_entrywindow.h"

#include "storage/storageerror.h"
#include "storage/storagefactory.h"
#include "subject_area/validators/regexuservalidator.h"

EntryWindow::EntryWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::EntryWindow),
    storage(StorageFactory::get(StorageFactory::Csv))
{
    ui->setupUi(this);

    {
        ui->lineEditLogin->setValidator(
            new QRegularExpressionValidator(
                RegexUserValidator::usernameRegex(), this));
        ui->lineEditPass->setValidator(
            new QRegularExpressionValidator(
                RegexUserValidator::passwordRegex(), this));
    }

    {
        connect(ui->pushBtnSignIn, &QPushButton::clicked,
                this, &EntryWindow::onClicked_pushBtnSignIn);
    }
}

EntryWindow::~EntryWindow()
{
    delete ui;
}

// -----------------------------------------------------------------------

void EntryWindow::onClicked_pushBtnSignIn()
{
    qDebug() << "EntryWindow::onClicked_pushBtnSignIn()";

    try {
//        User user = storage.getUserByCredentials(
//            ui->lineEditLogin->text(),
//            ui->lineEditPass->text());

    User user = storage.getUserByLogin(
            ui->lineEditLogin->text());
        qDebug() << user.toString();


    } catch(const StorageError::NotFound&) {
        QMessageBox::warning(
            this, windowTitle(),
            tr("Пользователь с такими реквизитами не найден")
            );
        return;
    }

    emit successful();
}
