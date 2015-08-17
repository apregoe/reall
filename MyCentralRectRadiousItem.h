#ifndef MYCENTRALRECTRADIOUSITEM_H
#define MYCENTRALRECTRADIOUSITEM_H
#include "MyCentralGraphicsItem.h"
#include <QtCore>
#include <QPen>

class MyCentralRectRadiousItem : public MyCentralGraphicsItem {
public:
	MyCentralRectRadiousItem(const QRectF & rect, QGraphicsItem * parent = 0);
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
			QWidget * widget = 0);
	int type() const{return Type;}
	const QPen getPen() const {return pen;}
private:
	enum { Type = 2 };
	QPen pen;
	qreal radious;
};
#endif