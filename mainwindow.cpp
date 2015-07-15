#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Reall - Infogram Software");
    setupActions();
    createMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Create_new_file(){
	(new MainWindow())->show();
}

void MainWindow::setupActions(){
	NewAction = new QAction(QIcon("images/menuactionicons/new.png"), "New", this);
	NewAction->setShortcut(QKeySequence("Ctrl+N"));
	NewAction->setStatusTip("Create new Infographic");
	connect(NewAction, SIGNAL(triggered(bool)), this, SLOT(Create_new_file()));
	connect(NewAction, SIGNAL(hovered()), this, SLOT(Create_new_file()));
}

void MainWindow::createMenu(){
	MainWindow_QMenu = this->menuBar()->addMenu("File");
	MainWindow_QMenu->addAction(NewAction);
}