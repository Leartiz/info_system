#ifndef CLIENTREGWINDOW_H
#define CLIENTREGWINDOW_H

#include <QDialog>

#include "storage/userstorage.h"

namespace Ui {
class ClientRegWindow;
} // namespace Ui

class ClientRegWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClientRegWindow(UserStorage& storage,
                             QWidget *parent = nullptr);
    ~ClientRegWindow() override;

public slots:
    void onClicked_pushBtnOk();
    void onClicked_pushBtnCancel();

private:
    Ui::ClientRegWindow *ui;
    UserStorage& storage;
};

#endif // CLIENTREGWINDOW_H
