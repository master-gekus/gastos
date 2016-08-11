#-------------------------------------------------
#
# Project created by QtCreator 2016-08-11T05:30:37
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_gastostest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_gastostest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../gastos/lib/ -lgastos
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../gastos/lib/ -lgastosd
else:unix: LIBS += -L$$PWD/../gastos/lib/ -lgastos
