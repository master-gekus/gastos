#-------------------------------------------------
#
# Project created by QtCreator 2016-08-10T18:26:23
#
#-------------------------------------------------

QT       -= gui

win32:CONFIG(debug, debug|release) {
	TARGET = gastosd
} else {
	TARGET = gastos
}

DESTDIR = $$PWD/lib

TEMPLATE = lib

DEFINES += GASTOS_LIBRARY

SOURCES += \
	gastos.cpp

HEADERS += \
	gastos.h \
	gastos_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
