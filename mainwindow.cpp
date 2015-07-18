#include "mainwindow.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent){

    this->setWindowTitle("Reall - Infogram Software");
    QDesktopWidget dw;
    this->resize(dw.width()*0.65, dw.height()*0.65);

    setupActions();
    createMenu();
    createToolBar();


    setupCentralWidget();
}

void MainWindow::Create_new_file(){
	(new MainWindow())->show();
}
void MainWindow::Save_as_file(){

}

void MainWindow::Save_File(){

}

void MainWindow::Exit_file(){
	this->close();
}

void MainWindow::Undo_routine(){

}
void MainWindow::Redo_routine(){

}
void MainWindow::Load_File(){

}

void MainWindow::setupActions(){
	NewAction = new QAction(QIcon("images/menuactionicons/new.png"), tr("New"), this);
	NewAction->setShortcut(QKeySequence("Ctrl+n"));
	NewAction->setStatusTip("Create new Infographic");
	connect(NewAction, SIGNAL(triggered(bool)), this, SLOT(Create_new_file()));

	SaveAsAction = new QAction(QIcon("images/menuactionicons/Save_as.png"), "Save As", this);
	SaveAsAction->setShortcut(QKeySequence("Ctrl+S"));
	SaveAsAction->setStatusTip("Save Infographic to a file");
	connect(SaveAsAction, SIGNAL(triggered(bool)), this, SLOT(Save_as_file()));

	SaveAction = new QAction(QIcon("images/menuactionicons/save.png"), "Save", this);
	SaveAction->setShortcut(QKeySequence("Ctr+S"));
	SaveAsAction->setStatusTip("Save Infographic to a file");
	connect(SaveAction,SIGNAL(triggered(bool)), this,SLOT(Save_File()));

	ExitAction = new QAction(QIcon("images/menuactionicons/exit.png"), "Exit", this);
	ExitAction->setShortcut(QKeySequence::Close);
	ExitAction->setStatusTip("Exit Program");
	connect(ExitAction, SIGNAL(triggered(bool)), this, SLOT(Exit_file()));



}

void MainWindow::createMenu(){
	MainWindow_QMenu = this->menuBar()->addMenu("File");
	MainWindow_QMenu->addAction(NewAction);
	MainWindow_QMenu->addAction(SaveAsAction);
	MainWindow_QMenu->addSeparator();
	MainWindow_QMenu->addAction(ExitAction);
}

void MainWindow::createToolBar(){
	MainWindow_ToolBar = new QToolBar("File", this);
	MainWindow_ToolBar->addAction(NewAction);
	MainWindow_ToolBar->addAction(SaveAsAction);
	MainWindow_ToolBar->addSeparator();
	MainWindow_ToolBar->addAction(ExitAction);
	MainWindow_ToolBar->setMovable(true);
	this->addToolBar(MainWindow_ToolBar);
}

void MainWindow::setupCentralWidget(){
	text = new QTextEdit("Write Here",this);
	setCentralWidget(text);
}