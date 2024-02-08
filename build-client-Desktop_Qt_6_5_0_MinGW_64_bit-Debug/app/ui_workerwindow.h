/********************************************************************************
** Form generated from reading UI file 'workerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKERWINDOW_H
#define UI_WORKERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_WorkerWindow
{
public:

    void setupUi(QDialog *WorkerWindow)
    {
        if (WorkerWindow->objectName().isEmpty())
            WorkerWindow->setObjectName("WorkerWindow");
        WorkerWindow->resize(400, 300);

        retranslateUi(WorkerWindow);

        QMetaObject::connectSlotsByName(WorkerWindow);
    } // setupUi

    void retranslateUi(QDialog *WorkerWindow)
    {
        WorkerWindow->setWindowTitle(QCoreApplication::translate("WorkerWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkerWindow: public Ui_WorkerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERWINDOW_H
