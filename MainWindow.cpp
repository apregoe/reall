#include "MainWindow.h"
#include "MyCentralRectItem.h"
#include <QtCore>
#include <cstdlib>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent){
	this->setWindowTitle("Re:all - Infogram Software");
    QDesktopWidget dw;

    this->resize(dw.width()*0.65, dw.height()*0.65);

    createCentralWidget();
    createDockWidget();
/*
    
    for(int i = 0; i < 10; ++i){
        int x = centralScene->sceneRect().width();
        int y = centralScene->sceneRect().height();
        QRectF r(QPointF(std::rand() % x ,std::rand() % y), QSizeF(20,20));
        centralScene->addItem(new MyCentralRectItem(r));
    }
    centralScene->connect();*/
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
    centralView->setSceneRect(this->rect());
    centralScene->setSceneRect(this->rect());
    QMainWindow::resizeEvent(event);
}