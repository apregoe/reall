#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QComboBox>
#include <QSplitter>
#include "MyCanvas.h"

class Main_window : public QWidget{
public:
	Main_window();
	~Main_window(){}

private slots:
	
	void setupEmoticonGridBox();

private:
	QGridLayout* OuterContainer;
		QHBoxLayout* Emotions;
			QComboBox* EmoticonGridBox;
		QSplitter* Emotions_Canvas_Splitter;
		MyCanvas* MainCanvas;
};

#endif