#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	app.setWindowIcon(QIcon("reall.jpg"));
	//I create MainWindow in MainWindow.h
	MainWindow h;
	h.show();
	return app.exec();
}