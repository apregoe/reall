#include <iostream>
#include <QApplication>

#include "main_window.h"

using namespace std;

/**Main file, this calls the Main_window object and execute it */
int main(int argc, char** argv){

	QApplication app(argc, argv);

	Main_window reall_window;
	reall_window.show();

	app.exec();

	return 0;
}