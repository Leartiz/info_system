#ifndef WINDOWNAVIGATOR_H
#define WINDOWNAVIGATOR_H

#include <memory>

#include <QMainWindow>
#include <QObject>

#include "entrywindow.h"
#include "storage/storage.h"

class AdminWindow;
class WorkerWindow;
class ClientWindow;

class User;

class WindowNavigator : public QObject
{
    Q_OBJECT

public:
    explicit WindowNavigator(Storage& storage,
                             QObject* parent = nullptr);

public slots:
    void onSuccessful_entryWindow(const User& user);
    void onLogout_windowForRole();

private:
    std::unique_ptr<EntryWindow> entryWindow;
    void hideAndRemoveEntry();
    void connectToEntry();

    void connectToAdmin(AdminWindow*);
    void connectToWorker(WorkerWindow*);
    void connectToClient(ClientWindow*);

private:
    std::unique_ptr<QMainWindow> windowForRole;
    void hideAndRemoveForRole();
    void createAndShowEntry();

private:
    Storage& storage;
};

#endif // WINDOWNAVIGATOR_H
