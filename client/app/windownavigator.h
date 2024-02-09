#ifndef WINDOWNAVIGATOR_H
#define WINDOWNAVIGATOR_H

#include <memory>

#include <QObject>
#include <QMainWindow>

#include "entrywindow.h"

class EntryWindow;
class User;

class WindowNavigator : public QObject
{
    Q_OBJECT

public:
    WindowNavigator();

public slots:
    void onSuccessful_entryWindow(const User& user);
    void onLogout_windowForRole();

private:
    std::unique_ptr<EntryWindow> entryWindow;
    void hideAndRemoveEntry();
    void connectToEntry();

private:
    std::unique_ptr<QMainWindow> windowForRole;
    void hideAndRemoveForRole();
};

#endif // WINDOWNAVIGATOR_H
