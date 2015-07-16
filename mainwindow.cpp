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
    createToolBar();
    setupCentralWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Create_new_file(){
	(new MainWindow())->show();
}
void MainWindow::Save_as_file(){

}

void MainWindow::Exit_file(){
	this->close();
}

void MainWindow::setupActions(){
	NewAction = new QAction(QIcon("images/menuactionicons/new.png"), "New", this);
	NewAction->setShortcut(QKeySequence("Ctrl+n"));
	NewAction->setStatusTip("Create new Infographic");
	connect(NewAction, SIGNAL(triggered(bool)), this, SLOT(Create_new_file()));

	SaveAsAction = new QAction(QIcon("images/menuactionicons/Save_as.png"), "Save As", this);
	SaveAsAction->setShortcut(QKeySequence("Ctrl+s"));
	SaveAsAction->setStatusTip("Save Infographic to a file Infographic");
	connect(SaveAsAction, SIGNAL(triggered(bool)), this, SLOT(Save_as_file()));

	ExitAction = new QAction(QIcon("images/menuactionicons/exit.png"), "Exit", this);
	ExitAction->setShortcut(QKeySequence("Ctr+w"));
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
	GraphicsScene = new QGraphicsScene(this);
	CentralWidget = new QGraphicsView(GraphicsScene ,this);
	CentralWidget->setFrameStyle(QFrame::StyledPanel);
	CentralWidget->setFrameShadow(QFrame::Raised);
	CentralWidget->setContentsMargins(20,20,20,20);
	CentralWidget->setFrameRect(QRect(0,0,this->width(),this->height()));
	QBrush redBrush(Qt::red);
	QPen blackPen(Qt::black);
	blackPen.setWidth(6);

	Ellipse = GraphicsScene->addEllipse(10,10,100,100,blackPen,redBrush);
	Rectangle = GraphicsScene->addRect(-100,-100,50,50, blackPen, redBrush);
	Rectangle->setFlag(QGraphicsItem::ItemIsMovable, QGraphicsItem::ItemIsSelectable);
	this->setCentralWidget(CentralWidget);
}