#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    OuterContainer = new QGridLayout(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

