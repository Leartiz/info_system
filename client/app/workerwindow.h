#ifndef WORKERWINDOW_H
#define WORKERWINDOW_H

#include <QMainWindow>

namespace Ui {
class WorkerWindow;
}

class WorkerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WorkerWindow(QWidget *parent = nullptr);
    ~WorkerWindow();

signals:
    void logout();

private:
    Ui::WorkerWindow *ui;
};

#endif // WORKERWINDOW_H
