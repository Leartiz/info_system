#ifndef ENTRYWINDOW_H
#define ENTRYWINDOW_H

#include <QDialog>

#include "storage/storage.h"

namespace Ui {
class EntryWindow;
}

class EntryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EntryWindow(QWidget *parent = nullptr);
    ~EntryWindow();

public slots:
    void onClicked_pushBtnSignIn();

signals:
    void successful();

private:
    Ui::EntryWindow *ui;
    Storage& storage;
};

#endif // ENTRYWINDOW_H
