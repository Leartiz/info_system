/********************************************************************************
** Form generated from reading UI file 'entrywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTRYWINDOW_H
#define UI_ENTRYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EntryWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelLogo;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelLogin;
    QLabel *labelPass;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditLogin;
    QLineEdit *lineEditPass;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushBtnSignIn;

    void setupUi(QDialog *EntryWindow)
    {
        if (EntryWindow->objectName().isEmpty())
            EntryWindow->setObjectName("EntryWindow");
        EntryWindow->resize(240, 193);
        EntryWindow->setMinimumSize(QSize(240, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        EntryWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(EntryWindow);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        labelLogo = new QLabel(EntryWindow);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setMinimumSize(QSize(75, 75));
        labelLogo->setMaximumSize(QSize(75, 75));
        labelLogo->setPixmap(QPixmap(QString::fromUtf8(":/resources/logo.png")));
        labelLogo->setScaledContents(true);
        labelLogo->setAlignment(Qt::AlignCenter);
        labelLogo->setWordWrap(false);

        horizontalLayout_2->addWidget(labelLogo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        labelLogin = new QLabel(EntryWindow);
        labelLogin->setObjectName("labelLogin");

        verticalLayout->addWidget(labelLogin);

        labelPass = new QLabel(EntryWindow);
        labelPass->setObjectName("labelPass");

        verticalLayout->addWidget(labelPass);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lineEditLogin = new QLineEdit(EntryWindow);
        lineEditLogin->setObjectName("lineEditLogin");

        verticalLayout_2->addWidget(lineEditLogin);

        lineEditPass = new QLineEdit(EntryWindow);
        lineEditPass->setObjectName("lineEditPass");
        lineEditPass->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        verticalLayout_2->addWidget(lineEditPass);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushBtnSignIn = new QPushButton(EntryWindow);
        pushBtnSignIn->setObjectName("pushBtnSignIn");

        horizontalLayout_3->addWidget(pushBtnSignIn);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

#if QT_CONFIG(shortcut)
        labelLogin->setBuddy(lineEditLogin);
        labelPass->setBuddy(lineEditPass);
#endif // QT_CONFIG(shortcut)

        retranslateUi(EntryWindow);

        QMetaObject::connectSlotsByName(EntryWindow);
    } // setupUi

    void retranslateUi(QDialog *EntryWindow)
    {
        EntryWindow->setWindowTitle(QCoreApplication::translate("EntryWindow", "\320\233\320\276\320\274\320\261\320\260\321\200\320\264", nullptr));
        labelLogo->setText(QString());
        labelLogin->setText(QCoreApplication::translate("EntryWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        labelPass->setText(QCoreApplication::translate("EntryWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushBtnSignIn->setText(QCoreApplication::translate("EntryWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EntryWindow: public Ui_EntryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRYWINDOW_H
