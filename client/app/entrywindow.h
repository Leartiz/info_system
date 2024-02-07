#ifndef ENTRYWINDOW_H
#define ENTRYWINDOW_H

#include <QDialog>

namespace Ui {
class EntryWindow;
}

class EntryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EntryWindow(QWidget *parent = nullptr);
    ~EntryWindow();

private:
    Ui::EntryWindow *ui;
};

#endif // ENTRYWINDOW_H
