#ifndef MYCENTRALRECTRADIOUSITEM_H
#define MYCENTRALRECTRADIOUSITEM_H
#include "MyCentralGraphicsItem.h"
#include <QtCore>
#include <QtGui>

class MyCentralRectRadiousItem : public MyCentralGraphicsItem {
public:
	MyCentralRectRadiousItem(const QRectF & rect, QGraphicsItem * parent = 0);
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
			QWidget * widget = 0);
	int type() const{return Type;}
private:
	enum { Type = 2 };
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
};
#endif