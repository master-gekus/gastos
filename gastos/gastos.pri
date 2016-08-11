win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -lgastos
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -lgastosd
else:unix: LIBS += -L$$PWD/lib/ -lgastos

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

