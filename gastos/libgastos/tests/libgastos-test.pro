QT += testlib
QT -= gui

TARGET = libgastos-test

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
  libgastos-test.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

INCLUDEPATH *= $$PWD/../include

win32:CONFIG(release, debug|release) {
  LIBS += -L$$OUT_PWD/../release -lgastos
} else:win32:CONFIG(debug, debug|release) {
  LIBS += -L$$OUT_PWD/../debug -lgastosd
} else:unix {
  LIBS += -L$$OUT_PWD/../ -lgastos
}
