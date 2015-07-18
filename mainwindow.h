#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QRectF>
#include <QPushButton>
#include <QBrush>
#include <QTimer>
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
#include <QDesktopWidget>
#include <QAction>
#include <QKeySequence>

#include <QTextEdit>

#include "MyGraphicsItem.h"

class MainWindow : public QMainWindow{
Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private slots:
	void Create_new_file();
	void Save_as_file();
	void Exit_file();
	void Save_File();
	void Undo_routine();
	void Redo_routine();
	void Load_File();

private:
    QMenu* MainWindow_QMenu;
    QToolBar* MainWindow_ToolBar;

    //Central Widget
    QTextEdit* text;

    //Menu Actions
    QAction* NewAction;
    QAction* SaveAsAction;
    QAction* SaveAction;
    QAction* ExitAction; 
    QAction* UndoAction;
    QAction* RedoAction;
    QAction* LoadAction;
    	QString* Filepath;//file path in which the widget is


    //
    void setupActions();
    void createMenu();
    void createToolBar();
    void setupCentralWidget();

};

#endif
