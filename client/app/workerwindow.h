#ifndef WORKERWINDOW_H
#define WORKERWINDOW_H

#include <QDialog>

namespace Ui {
class WorkerWindow;
}

class WorkerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WorkerWindow(QWidget *parent = nullptr);
    ~WorkerWindow();

private:
    Ui::WorkerWindow *ui;
};

#endif // WORKERWINDOW_H
