#include "mainwindow.h"
#include "ui_mainwindow.h"

/*!
 * \class MainWindow
 * \inmodule test-gastos
 * \brief Main Window
 *
 * Описание окна Main Window
 */

/*!
      \page altruism-faq.html faq
      \title Altruism Frequently Asked Questions
      \inmodule test-gastos

      \brief All the questions about altruism, answered.

      ...
  */

/*!
 * \brief Описание конструктора
 * \param parent Парент
 * \inmodule test-gastos
 */
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

/*!
 * \brief Описание слота
 * \inmodule test-gastos
 */
void MainWindow::public_slot()
{

}

void MainWindow::private_slot()
{

}
