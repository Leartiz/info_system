#include <QApplication>
#include <QMessageBox>

#include "windownavigator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WindowNavigator _;
    return a.exec();
}
