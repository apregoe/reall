#include <QApplication>
#include "MainWindow.h"

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	Q_INIT_RESOURCE(resources);
	app.setWindowIcon(QPixmap(":/images/reall.jpg"));
	//I create MainWindow in MainWindow.h
	MainWindow h;
	h.show();
	return app.exec();
}