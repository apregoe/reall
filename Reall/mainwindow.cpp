#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   connect(this->button, SIGNAL(clicked(bool),)

}

MainWindow::~MainWindow()
{
    delete ui;
}
