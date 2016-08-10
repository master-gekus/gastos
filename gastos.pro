TEMPLATE = subdirs

SUBDIRS += \
    gastos \
    test-gastos

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/gastos/ -lgastos
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/gastos/ -lgastosd
else:unix: LIBS += -L$$OUT_PWD/gastos/ -lgastos

INCLUDEPATH += $$PWD/gastos
DEPENDPATH += $$PWD/gastos
