#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSplitter>
#include <QGridLayout>
#include <QMenuBar>
#include <QMenu>
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
private:
    Ui::MainWindow *ui;
    QGridLayout* OuterContainer;
    	QMenuBar* MainWindow_MenuBar;
    	QMenu* MainWindow_QMenu;
    //Menu Actions
    QAction* NewAction;
    QAction* SaveAsAction;
    QAction* ExitAction; 
    QAction* SaveAction;

    //
    void setupActions();
    void createMenu();

};

#endif // MAINWINDOW_H
