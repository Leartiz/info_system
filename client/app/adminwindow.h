#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

public slots:
    void onClicked_pushBtnAdd();

private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
