#include "MyCanvas.h"

MyCanvas::MyCanvas(){
	margins = new QMargins(1,1,1,1);
	this->setViewportMargins(*margins);
}