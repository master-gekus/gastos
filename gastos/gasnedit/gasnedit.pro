TARGET = gasnedit

include($$PWD/gasnedit.pri)

INCLUDEPATH *= $$PWD/../libgastos/include

win32:CONFIG(release, debug|release) {
  LIBS += -L$$OUT_PWD/../libgastos/release -lgastos
} else:win32:CONFIG(debug, debug|release) {
  LIBS += -L$$OUT_PWD/../libgastos/debug -lgastosd
} else:unix {
  LIBS += -L$$OUT_PWD/../libgastos/ -lgastos
}
