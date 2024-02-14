#ifndef ENTRYWINDOW_H
#define ENTRYWINDOW_H

#include <QDialog>

#include "storage/storage.h"

namespace Ui {
class EntryWindow;
} // namespace Ui

class EntryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EntryWindow(Storage& storage,
                         QWidget *parent = nullptr);
    ~EntryWindow() override;

public slots:
    void onClicked_pushBtnSignIn();
    void onClicked_pushBtnSignUp();

signals:
    void successful(const User&);

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::EntryWindow *ui;
    Storage& storage;
};

#endif // ENTRYWINDOW_H
