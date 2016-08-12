win32:CONFIG(debug, debug|release) {
  TARGET = gastosd
} else {
  TARGET = gastos
}

QT -= gui

INCLUDEPATH *= $$PWD/include

TEMPLATE = lib

DEFINES += GASTOS_LIBRARY

SOURCES += \
  src/GAsn1Object.cpp

HEADERS += \
  include/gastos.h \
  include/GAsn1Object.h
