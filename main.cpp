#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	//I create MainWindow in MainWindow.h
	MainWindow h;
	h.show();
	return a.exec();
}