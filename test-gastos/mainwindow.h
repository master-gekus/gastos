#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;

signals:
  void test_signal();

public slots:
  void public_slot();

private slots:
  void private_slot();

public:
  static void static_function(int a);
};

#endif // MAINWINDOW_H
