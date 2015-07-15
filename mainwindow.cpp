#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Reall - Infogram Software");

    OuterContainer = new QGridLayout(this);
    MainWindow_MenuBar = new QMenuBar(this);
    	MainWindow_QMenu = new QMenu("Menu Title", this);

    MainWindow_MenuBar->addMenu(MainWindow_QMenu);
    this->setMenuBar(MainWindow_MenuBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}

