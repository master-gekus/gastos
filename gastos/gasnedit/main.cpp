#include <QApplication>

#include <GAsn1Object.h>

#include "main_window.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
