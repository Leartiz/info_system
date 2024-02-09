/********************************************************************************
** Form generated from reading UI file 'adduserwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSERWINDOW_H
#define UI_ADDUSERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_AddUserWindow
{
public:

    void setupUi(QDialog *AddUserWindow)
    {
        if (AddUserWindow->objectName().isEmpty())
            AddUserWindow->setObjectName("AddUserWindow");
        AddUserWindow->resize(400, 300);

        retranslateUi(AddUserWindow);

        QMetaObject::connectSlotsByName(AddUserWindow);
    } // setupUi

    void retranslateUi(QDialog *AddUserWindow)
    {
        AddUserWindow->setWindowTitle(QCoreApplication::translate("AddUserWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddUserWindow: public Ui_AddUserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSERWINDOW_H
