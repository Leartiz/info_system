#include "windownavigator.h"
#include "entrywindow.h"

#include "clientwindow.h"
#include "workerwindow.h"
#include "adminwindow.h"

WindowNavigator::WindowNavigator()
    : entryWindow(new EntryWindow)
    , windowForRole(nullptr)
{
    connectToEntry();
    entryWindow->show();
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
            auto window = new ClientWindow;
            {

            }
            windowForRole.reset(window);
        }
        break;
    case Role::Worker:
        {
            auto window = new WorkerWindow;
            {
                connect(window, &WorkerWindow::logout,
                        this, &WindowNavigator::onLogout_windowForRole);
            }
            windowForRole.reset(window);
        }
        break;
    case Role::Admin:
        {
            auto window = new AdminWindow;
            {

            }
            windowForRole.reset(window);
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

    entryWindow.reset(new EntryWindow);
    connectToEntry();
    entryWindow->show();
}

// -----------------------------------------------------------------------

void WindowNavigator::connectToEntry()
{
    {
        connect(entryWindow.get(), &EntryWindow::successful,
                this, &WindowNavigator::onSuccessful_entryWindow);
    }
}

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
