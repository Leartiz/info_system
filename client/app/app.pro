QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

FORMS += \
    adminwindow.ui \
    clientwindow.ui \
    entrywindow.ui \
    mainwindow.ui \
    workerwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

message($$PWD) # <--- app
message($$PWD/../app)

SOURCES += \
    adminwindow.cpp \
    clientwindow.cpp \
    entrywindow.cpp \
    mainwindow.cpp \
    main.cpp \
    workerwindow.cpp

HEADERS += \
    adminwindow.h \
    clientwindow.h \
    entrywindow.h \
    mainwindow.h \
    workerwindow.h

include(app_code.pri)

RESOURCES += \
    resources.qrc
