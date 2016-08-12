TEMPLATE = subdirs

libgastos.file = libgastos/libgastos.pro

libgastos-test.file = libgastos/tests/libgastos-test.pro
libgastos-test.depends *= libgastos

SUBDIRS += \
  libgastos \
  libgastos-test
