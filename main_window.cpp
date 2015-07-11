#include <iostream>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <iostream>
#include <QMessageBox>
#include "main_window.h"

using namespace std;

Main_window::Main_window(){
	setWindowTitle("Re:all Infographic software");

	Outercontainer = new QHBoxLayout();
		Header = new QHBoxLayout();
			Logo.load("reconnect_logo_crop.jpg");
			image_container = new QLabel();
			image_container->setPixmap(QPixmap::fromImage(Logo.scaled(150,80)));
			account_button = new QPushButton("account");
			account_button->setStyleSheet("QPushButton:hover{background-color: red; color: blue;} QPushButton{background-color: blue; border-radius: 3px; color:red;}");
			account_button->setWindowOpacity(0.1);
			library_button = new QPushButton("library");
			search_button = new QPushButton("search");
			random_button = new QPushButton("random");
	//Setting Main_Window
	Outercontainer->addLayout(Header);
		Header->addWidget(image_container);
		Header->addWidget(account_button);
		Header->addWidget(library_button);
		Header->addWidget(search_button);
		Header->addWidget(random_button);
	setLayout(Outercontainer);
}