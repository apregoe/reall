#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSplitter>
#include <QGridLayout>
#include <QMenuBar>
#include <QMenu>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    QGridLayout* OuterContainer;
    	QMenuBar* MainWindow_MenuBar;
    	QMenu* MainWindow_QMenu;

};

#endif // MAINWINDOW_H
