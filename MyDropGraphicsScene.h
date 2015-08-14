#ifndef MYDROPGRAPHICSSCENE_H
#define MYDROPGRAPHICSSCENE_H
#include <QtGui>
#include <QtCore>
#include "MyCentralRectItem.h"
class MyDropGraphicsScene : public QGraphicsScene {
public:
	MyDropGraphicsScene(QObject * parent = 0);
	void addItem(QGraphicsItem * item);
	void addItemPoints(QGraphicsItem * item);
protected:
	void dropEvent(QGraphicsSceneDragDropEvent * event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent * event);
	void dragMoveEvent(QGraphicsSceneDragDropEvent * event){}
private:
	QList<QPointF> allPoints;
};
#endif