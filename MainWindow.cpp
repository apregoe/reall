#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent){
	this->setWindowTitle("Re:all - Infogram Software");
    QDesktopWidget dw;

    this->resize(dw.width()*0.65, dw.height()*0.65);

    createCentralWidget();
    createDockWidget();
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
    centralView->setSceneRect(this->rect());
    centralScene->setSceneRect(this->rect());
	this->setCentralWidget(centralView);
}

void MainWindow::resizeEvent(QResizeEvent * event){
    qDebug() << "resizing mainwindow"<<endl;
    centralView->setSceneRect(this->rect());
    centralScene->setSceneRect(this->rect());
    delete mainRect;
    mainRect = centralScene->addRect(centralScene->sceneRect().adjusted(10,10,-10,-10));
    QMainWindow::resizeEvent(event);
}