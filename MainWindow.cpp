#include "MainWindow.h"
#include "MyCentralRectItem.h"
#include "MyCentralRectRadiousItem.h"
#include "MyBrushItem.h"
#include "MyCentralEllipseItem.h"
#include "MySimpleTextItem.h"
#include <cstdlib>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent){
	this->setWindowTitle("Re:all - Infogram Software");
    QDesktopWidget dw;

    this->resize(dw.width()*0.65, dw.height()*0.65);
    cursorActivated = false;
    createActions();
    createToolBar();
    createCentralWidget();
    createPainterCursor();
    createDockWidget();
    /*
    for(int i = 0; i < 10; ++i){
        int x = centralScene->sceneRect().width();
        int y = centralScene->sceneRect().height();
        QRectF r(QPointF(std::rand() % x ,std::rand() % y), QSizeF(40,40));
        int j = std::rand() % 3;
        if(j == 0){
            centralScene->addItem(new MyCentralRectItem(r));
        }else if (j ==1){
            centralScene->addItem(new MyCentralRectRadiousItem(r));
        }
        else{
            centralScene->addItem(new MyCentralEllipseItem(r));
        }
    }
    centralScene->connect();*/
}
void MainWindow::createPainterCursor(){
    QPixmap pMap = QPixmap("brush.png");
    painterCursor = new QCursor(pMap.scaled(QSize(14,14)), Qt::IgnoreAspectRatio);
}

void MainWindow::createActions(){
    painterAction = new QAction(QIcon("brush.png"), "Color Selection", this);
    painterAction->setCheckable(true);
    connect(painterAction, SIGNAL(toggled(bool)), this, SLOT(painterToggled(bool)));
        //Color dialog
        colorDialog = new QColorDialog();
 //       colorDialog->setOption(QColorDialog::ShowAlphaChannel);
        connect(colorDialog, SIGNAL(rejected()), this, SLOT(rejectColor()));
        connect(colorDialog, SIGNAL(colorSelected(const QColor &)), this, SLOT(acceptColor(const QColor &)));
}

void MainWindow::rejectColor(){
    cursorActivated = false;
    setCursor(Qt::ArrowCursor);
    centralView->setCursor(Qt::ArrowCursor);
    painterAction->setChecked(false);
}
void MainWindow::acceptColor(const QColor & color){
    cursorActivated = true;
	setCursor(*painterCursor);
    centralView->setCursor(*painterCursor);
    painterAction->setChecked(true);

    centralScene->setPainterColor(color);
}

void MainWindow::painterToggled(bool toggled){
    if(toggled){
	    cursorActivated = true;
		setCursor(*painterCursor);
	    centralView->setCursor(*painterCursor);
        colorDialog->exec();
    }
    else{
	    setCursor(Qt::ArrowCursor);
	    centralView->setCursor(Qt::ArrowCursor);
	    cursorActivated = false;
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
    centralView->setSceneRect(this->rect());
    centralScene->setSceneRect(this->rect());
	this->setCentralWidget(centralView);
}

void MainWindow::resizeEvent(QResizeEvent * event){
    centralView->setSceneRect(this->rect());
    centralScene->setSceneRect(this->rect());
    QMainWindow::resizeEvent(event);
}





















