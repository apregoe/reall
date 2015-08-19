#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "MyOrganizationDockWidget.h"
#include "MyDropGraphicsScene.h"
#include "MyGraphicsView.h"
#include <QtGui>
#include <QtCore>
class MainWindow : public QMainWindow{
Q_OBJECT
public:
	MainWindow(QWidget* parent = 0);
	bool painterCursorActivated(){return painterCursorActivated_;}
	QCursor getPainterCursor(){return painterCursor;}
private slots:
	void painterToggled(bool toggled);
	void rejectColor();
	void acceptColor(const QColor &);
private:
	void createActions();
	void createToolBar();
	void createDockWidget();
	void createCentralWidget();
	void createPainterCursor();
	MyOrganizationDockWidget* organizationDockWidget;
	MyDropGraphicsScene* centralScene;
	MyGraphicsView* centralView;
	QToolBar* toolBar;
	QColorDialog* colorDialog;
	QCursor painterCursor;
	bool painterCursorActivated_;
	//Actions
	QAction* painterAction;
protected:
	void resizeEvent(QResizeEvent * event);
};

#endif