QT += core
QT -= gui

CONFIG += c++11

TARGET = test-gastos-console
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../gastos/lib/ -lgastos
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../gastos/lib/ -lgastosd
else:unix: LIBS += -L$$OUT_PWD/../gastos/ -lgastos

INCLUDEPATH += $$PWD/../gastos
DEPENDPATH += $$PWD/../gastos
