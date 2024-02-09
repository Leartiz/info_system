#include "windownavigator.h"
#include "entrywindow.h"

#include "clientwindow.h"
#include "workerwindow.h"
#include "adminwindow.h"

WindowNavigator::WindowNavigator()
    : entryWindow(new EntryWindow)
    , adminWindow(nullptr)
    , workerWindow(nullptr)
    , clientWindow(nullptr)
{
    {
        connect(entryWindow, &EntryWindow::successful,
                this, &WindowNavigator::onSuccessful_entryWindow);
    }

    entryWindow->show();
}

WindowNavigator::~WindowNavigator()
{
    delete entryWindow;
    delete adminWindow;
    delete workerWindow;
    delete clientWindow;
}

// -----------------------------------------------------------------------

void WindowNavigator::onSuccessful_entryWindow(
    const User& user)
{
    qInfo() << user.toJsonString();
    entryWindow->hide();

    entryWindow->deleteLater();
    entryWindow = nullptr;

    // ***

    switch (user.getRole()) {
    case Role::Client:
        clientWindow = new ClientWindow;
        clientWindow->show();
        break;
    case Role::Worker:
        workerWindow = new WorkerWindow;
        workerWindow->show();
        break;
    case Role::Admin:
        adminWindow = new AdminWindow;
        adminWindow->show();
        break;
    }
}
