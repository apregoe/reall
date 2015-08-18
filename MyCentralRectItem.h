#ifndef MYCENTRALRECTITEM_H
#define MYCENTRALRECTITEM_H
#include "MyCentralGraphicsItem.h"
#include <QtCore>
#include <QtGui>

class MyCentralRectItem : public MyCentralGraphicsItem {
public:
	MyCentralRectItem(const QRectF & rect, QGraphicsItem * parent = 0);
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
			QWidget * widget = 0);
	int type() const{return Type;}
private:
	enum { Type = 1 };
	MyBrushItem* brushItem;
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
};
#endif