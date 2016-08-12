TARGET = libgastos-test

include($$PWD/libgastos-test.pri)

INCLUDEPATH *= $$PWD/../include

win32:CONFIG(release, debug|release) {
  LIBS += -L$$OUT_PWD/../release -lgastos
} else:win32:CONFIG(debug, debug|release) {
  LIBS += -L$$OUT_PWD/../debug -lgastosd
} else:unix {
  LIBS += -L$$OUT_PWD/../ -lgastos
}
