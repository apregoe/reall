#include "MainWindow.h"
#include "MyCentralRectItem.h"
#include "MyCentralRectRadiousItem.h"
#include "MyCentralEllipseItem.h"
#include "MySimpleTextItem.h"
#include <cstdlib>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent){
	this->setWindowTitle("re:all - Interactive Infographic");
    QDesktopWidget dw;
    this->resize(dw.width()*0.65, dw.height()*0.65);
    painterCursorActivated_ = false;
    createActions();
    createToolBar();
    createCentralWidget();
    createPainterCursor();
    createDockWidget();
}
void MainWindow::createPainterCursor(){
    QPixmap pMap = QPixmap(":/images/brush.png");
    pMap = pMap.scaled(QSize(14,14));
    painterCursor = QCursor((pMap), Qt::IgnoreAspectRatio);
}

void MainWindow::createActions(){
    QIcon icon(":/images/brush.png");
    painterAction = new QAction(icon, "Color Selection", this);
    painterAction->setCheckable(true);
    connect(painterAction, SIGNAL(toggled(bool)), this, SLOT(painterToggled(bool)));
        //Color dialog
        colorDialog = new QColorDialog();
        connect(colorDialog, SIGNAL(rejected()), this, SLOT(rejectColor()));
        connect(colorDialog, SIGNAL(colorSelected(const QColor &)), this, SLOT(acceptColor(const QColor &)));
}

void MainWindow::rejectColor(){
    painterCursorActivated_ = false;
    setCursor(Qt::ArrowCursor);
    centralView->setCursor(Qt::ArrowCursor);
    painterAction->setChecked(false);
}
void MainWindow::acceptColor(const QColor & color){
    painterCursorActivated_ = true;
	setCursor(painterCursor);
    centralView->setCursor(painterCursor);
    painterAction->setChecked(true);

    centralScene->setPainterColor(color);
}

void MainWindow::painterToggled(bool toggled){
    if(toggled){
	    painterCursorActivated_ = true;
		setCursor(painterCursor);
	    centralView->setCursor(painterCursor);
        colorDialog->exec();
    }
    else{
	    this->setCursor(Qt::ArrowCursor);
	    centralView->setCursor(Qt::ArrowCursor);
	    painterCursorActivated_ = false;
    }
}

void MainWindow::createToolBar(){
    toolBar = new QToolBar(this);
    toolBar->setFloatable(false);
    toolBar->setAllowedAreas(Qt::TopToolBarArea | Qt::LeftToolBarArea);
    toolBar->addAction(painterAction);
    this->addToolBar(Qt::TopToolBarArea,toolBar);
}

void MainWindow::createDockWidget(){
    organizationDockWidget = new MyOrganizationDockWidget("Organizations", this);
    organizationDockWidget->setFloating(true);
    organizationDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
    this->addDockWidget(Qt::LeftDockWidgetArea, organizationDockWidget);
}
void MainWindow::createCentralWidget(){
	centralScene = new MyDropGraphicsScene();
	centralView = new MyGraphicsView(centralScene, this);
    centralScene->setParent(centralView);
    centralView->setParent(this);
    centralView->setSceneRect(this->rect());
    centralScene->setSceneRect(this->rect());
	this->setCentralWidget(centralView);
}




















