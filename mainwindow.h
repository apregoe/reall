#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QPushButton>
#include <QBrush>
#include <QSplitter>
#include <QGraphicsView>
#include <QLabel>
#include <QGraphicsItem>
#include <QPen>
#include <QObject>
#include <QGridLayout>
#include <QMenuBar>
#include <QMenu>
#include <QScrollArea>
#include <QToolBar>
#include <QWidget>
#include <QAction>
#include <QKeySequence>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
	void Create_new_file();
	void Save_as_file();
	void Exit_file();

private:
    Ui::MainWindow *ui;
    QMenu* MainWindow_QMenu;
    QToolBar* MainWindow_ToolBar;
    //Menu Actions
    QAction* NewAction;
    QAction* SaveAsAction;
    QAction* ExitAction; 
    QAction* SaveAction;
    //Central Widget, graphics
    QGraphicsView* CentralWidget;
    QGraphicsScene* GraphicsScene;
    	//*****Testing/practicing graphicsview*****/
    	QGraphicsRectItem* Rectangle;
    	QGraphicsEllipseItem* Ellipse; 
    

    //
    void setupActions();
    void createMenu();
    void createToolBar();
    void setupCentralWidget();

};

#endif // MAINWINDOW_H
