QT += testlib
QT += core gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_general.cpp
HEADERS += tst_general.h

message($$PWD) # <--- app
message($$PWD/../app)

include($$PWD/../app/app_code.pri)
