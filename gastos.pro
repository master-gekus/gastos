TEMPLATE = subdirs

gastos_unit_test.file = $$PWD/gastos/gastos-unit-test.pro

SUBDIRS += \
    gastos \
    test-gastos \
    test-gastos-console \
    gastos_unit_test
