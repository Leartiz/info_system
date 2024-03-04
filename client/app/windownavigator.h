#ifndef WINDOWNAVIGATOR_H
#define WINDOWNAVIGATOR_H

#include <memory>

#include <QMainWindow>
#include <QObject>

#include "entrywindow.h"
#include "storage/userstorage.h"

class AdminWindow;
class WorkerWindow;
class ClientWindow;

class User;

class WindowNavigator : public QObject
{
    Q_OBJECT

public:
    explicit WindowNavigator(UserStorage& storage,
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
    UserStorage& storage;
};

#endif // WINDOWNAVIGATOR_H
