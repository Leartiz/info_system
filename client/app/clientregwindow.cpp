#include <QLineEdit>
#include <QPushButton>

#include <QRegularExpressionValidator>
#include <QValidator>

#include "clientregwindow.h"
#include "ui_clientregwindow.h"

#include "subject_area/validators/regexuservalidator.h"

ClientRegWindow::ClientRegWindow(Storage& storage, QWidget *parent)
    : QDialog(parent), ui(new Ui::ClientRegWindow)
    , storage(storage)
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
        ui->lineEditRepeatPass->setValidator(
            new QRegularExpressionValidator(
                RegexUserValidator::passwordRegex(), this));

        ui->lineEditFullName->setValidator(
            new QRegularExpressionValidator(
                RegexUserValidator::fullNameRegex(), this));
        ui->lineEditPassport->setValidator(
            new QRegularExpressionValidator(
                RegexUserValidator::passportRegex(), this));

        ui->lineEditPass->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        ui->lineEditRepeatPass->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    }

    // ui
    {
        connect(ui->pushBtnOk, &QPushButton::clicked,
                this, &ClientRegWindow::onClicked_pushBtnOk);
        connect(ui->pushBtnCancel, &QPushButton::clicked,
                this, &ClientRegWindow::onClicked_pushBtnCancel);
    }
}

ClientRegWindow::~ClientRegWindow()
{
    delete ui;
}

// -----------------------------------------------------------------------

// Нажимает кнопку "Ок"
void ClientRegWindow::onClicked_pushBtnOk()
{

}

// Нажимает кнопку "Отмена"
void ClientRegWindow::onClicked_pushBtnCancel()
{
    close();
    deleteLater();
}
