#include <QDebug>
#include <QMessageBox>
#include <QValidator>

#include "messageforclient.h"
#include "entrywindow.h"
#include "ui_entrywindow.h"

#include "storage/storageerror.h"
#include "storage/storagefactory.h"
#include "subject_area/validators/regexuservalidator.h"

using MessageForClient::Warning;
using MessageForClient::Critical;

EntryWindow::EntryWindow(QWidget *parent) :
    QDialog(parent), ui(new Ui::EntryWindow),
    storage(StorageFactory::get(StorageFactory::Csv))
{
    ui->setupUi(this);

    // validators
    {
        ui->lineEditLogin->setValidator(
            new QRegularExpressionValidator(
                RegexUserValidator::usernameRegex(), this));
        ui->lineEditPass->setValidator(
            new QRegularExpressionValidator(
                RegexUserValidator::passwordRegex(), this));
    }

    // ui
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
        const User user = storage.getUserByCredentials(
            ui->lineEditLogin->text(),
            ui->lineEditPass->text()
            );

        qInfo() << user.toJsonString();
        emit successful(user);

    } catch(const StorageError::NotFound& err) {
        qWarning() << err.what();
        QMessageBox::warning(
            this, windowTitle(),
            Warning::userByCredentialsNotFound()
            );
        return;
    } catch(const std::runtime_error& err) {
        qCritical() << err.what();
        QMessageBox::warning(
            this, windowTitle(),
            Critical::unexpectedError() +
                " : " + err.what()
            );

        qApp->quit();
        return;
    }
}
