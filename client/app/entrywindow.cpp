#include <QCloseEvent>
#include <QDebug>
#include <QMessageBox>

#include <QRegularExpressionValidator>
#include <QValidator>

#include "messageforclient.h"

#include "entrywindow.h"
#include "ui_entrywindow.h"
#include "clientregwindow.h"

#include "storage/storageerror.h"
#include "storage/storagefactory.h"
#include "subject_area/validators/regexuservalidator.h"

using MessageForClient::Warning;
using MessageForClient::Critical;

EntryWindow::EntryWindow(Storage& storage, QWidget *parent)
    : QDialog(parent), ui(new Ui::EntryWindow)
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
    }

    // ui
    {
        connect(ui->pushBtnSignIn, &QPushButton::clicked,
                this, &EntryWindow::onClicked_pushBtnSignIn);
        connect(ui->pushBtnSignUp, &QPushButton::clicked,
                this, &EntryWindow::onClicked_pushBtnSignUp);
    }
}

EntryWindow::~EntryWindow()
{
    delete ui;
}

void EntryWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    qApp->quit();
}

// -----------------------------------------------------------------------

void EntryWindow::onClicked_pushBtnSignIn()
{
    qDebug() << "SignIn button pressed";

    // Первоначальная обработка формы
    const auto pass = ui->lineEditPass->text();
    const auto login = ui->lineEditLogin->text();
    if (login.isEmpty() || pass.isEmpty()) {
        QMessageBox::warning(
            this, windowTitle(),
            Warning::loginOrPassIsEmpty());
        return;
    }

    // ***

    try {
        // Поиск пользователя по логину и паролю (обращение к хранилищу)
        const User user =
            storage.getUserByCredentials(login, pass);

        // Обработка ответа (основная последовательность)

        qInfo() << user.toJsonString();
        emit successful(user);

        // Обработчики ошибок (альтернативные последовательности)
        // |
        // V
    } catch(const StorageError::NotFound& err) {
        qWarning() << err.what();
        QMessageBox::warning(
            this, windowTitle(),
            Warning::userByCredentialsNotFound());
        return;
    } catch(const std::runtime_error& err) {
        qCritical() << err.what();
        QMessageBox::critical(
            this, windowTitle(),
            MessageForClient::withArg(
                Critical::unexpectedError(), err.what()));

        qApp->quit();
        return;
    }
}

void EntryWindow::onClicked_pushBtnSignUp()
{
    auto* regWindow = new ClientRegWindow(storage, this);
    regWindow->open();
}

