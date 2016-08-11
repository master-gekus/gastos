QT += core
QT -= gui

CONFIG += c++11

TARGET = test-gastos-console
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

include(../gastos/gastos.pri)
