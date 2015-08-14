#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "MyOrganizationDockWidget.h"
#include "MyDropGraphicsScene.h"
#include "MyGraphicsView.h"
class MainWindow : public QMainWindow{
Q_OBJECT
public:
	MainWindow(QWidget* parent = 0);
private:
	MyOrganizationDockWidget* organizationDockWidget;
	MyDropGraphicsScene* centralScene;
	MyGraphicsView* centralView;
	void createDockWidget();
	void createCentralWidget();
protected:
	void resizeEvent(QResizeEvent * event);
};

#endif