#include <QApplication>

#include <gastos.h>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
  Gastos g;

  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
