QT += core gui widgets

TEMPLATE = app

SOURCES += \
  main.cpp \
  main_window.cpp

HEADERS += \
  main_window.h

FORMS += \
  main_window.ui

include(../../Gqx/Gqx/GUiHelpers.pri)
