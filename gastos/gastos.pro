TEMPLATE = subdirs

libgastos.file = libgastos/libgastos.pro

libgastos-test.file = libgastos/tests/libgastos-test.pro
libgastos-test.depends *= libgastos

libgastos-test-insource.file = libgastos/tests/libgastos-test-insource.pro
libgastos-test-insource.depends *= libgastos

gasnedit.file = gasnedit/gasnedit.pro
gasnedit.depends *= libgastos

gasnedit-insource.file = gasnedit/gasnedit-insource.pro
gasnedit-insource.depends *= libgastos

SUBDIRS += \
  libgastos \
  libgastos-test \
  libgastos-test-insource \
  gasnedit \
  gasnedit-insource
