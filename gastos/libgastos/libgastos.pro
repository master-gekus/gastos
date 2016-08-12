win32:CONFIG(debug, debug|release) {
  TARGET = gastosd
} else {
  TARGET = gastos
}

QT -= gui

TEMPLATE = lib

include($$PWD/libgastos.pri)

DEFINES -= GASTOS_LIBRARY_INSOURCE
DEFINES += GASTOS_LIBRARY
