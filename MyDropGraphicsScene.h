#ifndef MYDROPGRAPHICSSCENE_H
#define MYDROPGRAPHICSSCENE_H
#include <QtGui>
#include <QtCore>
#include "MyCentralGraphicsItem.h"
#include "MyPointF.h"

class MyDropGraphicsScene : public QGraphicsScene {
public:
	MyDropGraphicsScene(QObject * parent = 0);
	void connect();
	QList<MyCentralGraphicsItem* > items() const;
	const double distance(const MyPointF * p1, const MyPointF * p2) const;
	void addItem(MyCentralGraphicsItem* item);
protected:
	void dropEvent(QGraphicsSceneDragDropEvent * event);
	void dragEnterEvent(QGraphicsSceneDragDropEvent * event);
	void dragMoveEvent(QGraphicsSceneDragDropEvent * event){Q_UNUSED(event);}
private:
	void reduceLineToBorders(QLineF &, MyPointF *, int);
	QList<MyCentralGraphicsItem*> myItems;
	QList<QGraphicsItem* > linesList;
};

#endif