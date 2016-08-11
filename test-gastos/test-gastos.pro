#-------------------------------------------------
#
# Project created by QtCreator 2016-08-10T18:31:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test-gastos
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../gastos/lib/ -lgastos
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../gastos/lib/ -lgastosd
else:unix: LIBS += -L$$PWD/../gastos/lib/ -lgastos

INCLUDEPATH += $$PWD/../gastos
DEPENDPATH += $$PWD/../gastos

qtPrepareTool(QDOC, qdoc)
# message($$QDOC)

docs_html.target = docs_html
docs_html.commands += $$QDOC $$PWD/gastos-test.qdocconf --outputdir $$OUT_PWD/docs
QMAKE_EXTRA_TARGETS += docs_html


# QDOC_FILES += gastos-test.qdocconf

