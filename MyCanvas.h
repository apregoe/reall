#ifndef MYCANVAS_H
#define MYCANVAS_H

#include <QMargins>
#include <QWidget>
#include <QAbstractScrollArea>

class MyCanvas : public QAbstractScrollArea {
public:
	MyCanvas();
	~MyCanvas(){}

private:
	QMargins* margins;
};

#endif