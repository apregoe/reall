#include <string>
#include <iostream>
#include "Main_window.h"

using namespace std;

Main_window::Main_window(){

	//Window Title
	this->setWindowTitle("Re:all - Software Infogram");

	 OuterContainer = new QGridLayout(this);
	 Emotions_Canvas_Splitter = new QSplitter();
		Emotions = new QHBoxLayout(this);
			this->setupEmoticonGridBox();
		MainCanvas = new MyCanvas();//index 1

	//Splitter settings
	Emotions_Canvas_Splitter->addWidget(EmoticonGridBox);
	Emotions_Canvas_Splitter->addWidget(MainCanvas);
	OuterContainer->addWidget(Emotions_Canvas_Splitter);
	Emotions_Canvas_Splitter->setCollapsible(1/*QSplitter::indexOf(MainCanvas)*/, 0);//MainCanvas Collapsible (index=1)
	this->setLayout(OuterContainer);
}

void Main_window::setupEmoticonGridBox(){
	EmoticonGridBox = new QComboBox[3];
	for(unsigned int row = 0; row < 3; ++row){
		string path = "images/emotions/smile/smile/";
		string smile_png = "smile"+ to_string(row+1) +".png";
		QString Qpath_ = QString::fromStdString(path+smile_png);
		EmoticonGridBox[row].addItem(QIcon(Qpath_), QString::fromStdString("smile"+to_string(row)));
		cout << row;
	}
}