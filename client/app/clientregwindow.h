#ifndef CLIENTREGWINDOW_H
#define CLIENTREGWINDOW_H

#include <QDialog>

#include "storage/storage.h"

namespace Ui {
class ClientRegWindow;
} // namespace Ui

class ClientRegWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClientRegWindow(Storage& storage,
                             QWidget *parent = nullptr);
    ~ClientRegWindow() override;

public slots:
    void onClicked_pushBtnOk();
    void onClicked_pushBtnCancel();

private:
    Ui::ClientRegWindow *ui;
    Storage& storage;
};

#endif // CLIENTREGWINDOW_H
