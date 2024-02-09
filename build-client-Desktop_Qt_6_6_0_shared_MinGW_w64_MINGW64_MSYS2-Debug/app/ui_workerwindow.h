/********************************************************************************
** Form generated from reading UI file 'workerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKERWINDOW_H
#define UI_WORKERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>

QT_BEGIN_NAMESPACE

class Ui_WorkerWindow
{
public:
    QGridLayout *gridLayout;

    void setupUi(QDialog *WorkerWindow)
    {
        if (WorkerWindow->objectName().isEmpty())
            WorkerWindow->setObjectName("WorkerWindow");
        WorkerWindow->resize(539, 360);
        gridLayout = new QGridLayout(WorkerWindow);
        gridLayout->setObjectName("gridLayout");

        retranslateUi(WorkerWindow);

        QMetaObject::connectSlotsByName(WorkerWindow);
    } // setupUi

    void retranslateUi(QDialog *WorkerWindow)
    {
        WorkerWindow->setWindowTitle(QCoreApplication::translate("WorkerWindow", "\320\233\320\270\321\207\320\275\321\213\320\271 \320\272\320\260\320\261\320\270\320\275\320\265\321\202 \321\200\320\260\320\261\320\276\321\202\320\275\320\270\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkerWindow: public Ui_WorkerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERWINDOW_H
