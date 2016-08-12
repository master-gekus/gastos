QT += testlib
QT -= gui

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
  libgastos-test.cpp

DEFINES *= SRCDIR=\\\"$$PWD/\\\"
