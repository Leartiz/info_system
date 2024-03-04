#include "windownavigator.h"
#include "entrywindow.h"

#include "adminwindow.h"
#include "clientwindow.h"
#include "workerwindow.h"

WindowNavigator::WindowNavigator(
    UserStorage& storage, QObject* parent)
    : QObject(parent)
    , entryWindow(nullptr)
    , windowForRole(nullptr)
    , storage(storage)
{
    createAndShowEntry();
}

// -----------------------------------------------------------------------

void WindowNavigator::onSuccessful_entryWindow(
    const User& user)
{
    qInfo() << user.toJsonString();
    hideAndRemoveEntry();

    // ***

    switch (user.getRole()) {
    case Role::Client:
        {
            auto *window = new ClientWindow;
            windowForRole.reset(window);
            connectToClient(window);
        }
        break;
    case Role::Worker:
        {
            auto *window = new WorkerWindow;
            windowForRole.reset(window);
            connectToWorker(window);
        }
        break;
    case Role::Admin:
        {
            auto *window = new AdminWindow;
            windowForRole.reset(window);
            connectToAdmin(window);
        }
        break;
    default:
        Q_ASSERT(false);
    }

    windowForRole->show();
}

void WindowNavigator::onLogout_windowForRole()
{
    hideAndRemoveForRole();

    entryWindow.reset(new EntryWindow(storage));
    connectToEntry();
    entryWindow->show();
}

// -----------------------------------------------------------------------

void WindowNavigator::connectToEntry()
{
    connect(entryWindow.get(), &EntryWindow::successful,
            this, &WindowNavigator::onSuccessful_entryWindow);
}

void WindowNavigator::connectToAdmin(AdminWindow*)
{

}

void WindowNavigator::connectToWorker(WorkerWindow* window)
{
    connect(window, &WorkerWindow::logout,
            this, &WindowNavigator::onLogout_windowForRole);
}

void WindowNavigator::connectToClient(ClientWindow*)
{

}

// -----------------------------------------------------------------------

void WindowNavigator::hideAndRemoveEntry()
{
    entryWindow->hide();
    entryWindow.reset();
}

void WindowNavigator::hideAndRemoveForRole()
{
    windowForRole->hide();
    windowForRole.reset();
}

void WindowNavigator::createAndShowEntry()
{
    entryWindow.reset(
        new EntryWindow(storage));

    connectToEntry();
    entryWindow->show();
}
