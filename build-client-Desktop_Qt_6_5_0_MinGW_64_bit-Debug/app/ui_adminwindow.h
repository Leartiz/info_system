/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QAction *actionAccessLevel;
    QAction *actionLogout;
    QAction *actionCloseApp;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditSearchParam;
    QPushButton *pushBtnSearch;
    QTableView *tableViewUsers;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushBtnDelete;
    QPushButton *pushBtnAdd;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(516, 435);
        QFont font;
        font.setPointSize(12);
        AdminWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        AdminWindow->setWindowIcon(icon);
        actionAccessLevel = new QAction(AdminWindow);
        actionAccessLevel->setObjectName("actionAccessLevel");
        actionLogout = new QAction(AdminWindow);
        actionLogout->setObjectName("actionLogout");
        actionCloseApp = new QAction(AdminWindow);
        actionCloseApp->setObjectName("actionCloseApp");
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        lineEditSearchParam = new QLineEdit(centralwidget);
        lineEditSearchParam->setObjectName("lineEditSearchParam");

        horizontalLayout->addWidget(lineEditSearchParam);

        pushBtnSearch = new QPushButton(centralwidget);
        pushBtnSearch->setObjectName("pushBtnSearch");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushBtnSearch->setIcon(icon1);
        pushBtnSearch->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(pushBtnSearch);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableViewUsers = new QTableView(centralwidget);
        tableViewUsers->setObjectName("tableViewUsers");

        gridLayout->addWidget(tableViewUsers, 1, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        pushBtnDelete = new QPushButton(centralwidget);
        pushBtnDelete->setObjectName("pushBtnDelete");

        horizontalLayout_9->addWidget(pushBtnDelete);

        pushBtnAdd = new QPushButton(centralwidget);
        pushBtnAdd->setObjectName("pushBtnAdd");

        horizontalLayout_9->addWidget(pushBtnAdd);


        gridLayout->addLayout(horizontalLayout_9, 2, 0, 1, 1);

        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 516, 26));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        AdminWindow->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionAccessLevel);
        menu->addSeparator();
        menu->addAction(actionLogout);
        menu->addAction(actionCloseApp);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "\320\233\320\270\321\207\320\275\321\213\320\271 \320\272\320\260\320\261\320\270\320\275\320\265\321\202 \320\260\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200\320\260", nullptr));
        actionAccessLevel->setText(QCoreApplication::translate("AdminWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\224\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        actionLogout->setText(QCoreApplication::translate("AdminWindow", "\320\240\320\260\320\267\320\273\320\276\320\263\320\270\320\275\320\270\321\202\321\214\321\201\321\217", nullptr));
        actionCloseApp->setText(QCoreApplication::translate("AdminWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203", nullptr));
        pushBtnSearch->setText(QString());
        pushBtnDelete->setText(QCoreApplication::translate("AdminWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushBtnAdd->setText(QCoreApplication::translate("AdminWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        menu->setTitle(QCoreApplication::translate("AdminWindow", "\320\235\320\260\320\262\320\270\320\263\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
