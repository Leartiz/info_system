#ifndef WINDOWNAVIGATOR_H
#define WINDOWNAVIGATOR_H

#include <QObject>

class EntryWindow;
class AdminWindow;
class ClientWindow;
class WorkerWindow;

class User;

class WindowNavigator : public QObject
{
    Q_OBJECT

public:
    WindowNavigator();
    ~WindowNavigator();

public slots:
    void onSuccessful_entryWindow(const User& user);

private:
    EntryWindow* entryWindow;

    AdminWindow* adminWindow;
    WorkerWindow* workerWindow;
    ClientWindow* clientWindow;


};

#endif // WINDOWNAVIGATOR_H
