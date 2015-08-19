#ifndef MYCENTRALRECTITEM_H
#define MYCENTRALRECTITEM_H
#include "MyCentralGraphicsItem.h"
#include <QtCore>
#include <QtGui>

class MyCentralRectItem : public MyCentralGraphicsItem {
public:
	MyCentralRectItem(const QRectF & rect, QGraphicsItem * parent = 0);
	//paint() is called whenever there is a change in this Item (resize, move, etc)
	//I paint the rectangle bounded by boundingRect()
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
			QWidget * widget = 0);
	//type() will be used to get the type of item I am dropping into MyDropGraphicsScene
	//so that it knows what item to initialize and add into the scene
	int type() const{return Type;}
private:
	enum { Type = 1 };
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
};
#endif