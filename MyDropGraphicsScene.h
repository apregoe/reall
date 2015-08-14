#ifndef MYDROPGRAPHICSSCENE_H
#define MYDROPGRAPHICSSCENE_H
#include <QtGui>
#include <QtCore>
#include "MyRectItem.h"
#include "MyCentralRectItem.h"
class MyDropGraphicsScene : public QGraphicsScene {
public:
	MyDropGraphicsScene(QObject * parent = 0);
protected:
	void dropEvent(QGraphicsSceneDragDropEvent * event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent * event);
	void dragMoveEvent(QGraphicsSceneDragDropEvent * event){}
	
};
#endif