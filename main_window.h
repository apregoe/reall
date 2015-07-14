#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <iostream>
#include <QMessageBox>

class Main_window : public QWidget {
Q_OBJECT
public:
	Main_window();

private slots:

private:
	QVBoxLayout* Outercontainer;
		QHBoxLayout* Header;
			QLabel* image_container;
				QImage Logo;
			QPushButton* account_button;
			QPushButton* library_button;
			QPushButton* search_button;
			QPushButton* random_button;
		QVBoxLayout* Middle_container;
			//This is to get a fixed size:
			QWidget* Middle_widget;
			
			QHBoxLayout* left_middle_container;
				QVBoxLayout* Emotions_container;
				QVBoxLayout* Organizations_structure_container;
			QHBoxLayout* Middle_center_container;
			QVBoxLayout* Middle_right_container;
				QHBoxLayout* Chart_container;
				QHBoxLayout* Data_library_container;
};

#endif