#ifndef MYCENTRALELLIPSEITEM
#define MYCENTRALELLIPSEITEM
#include "MyCentralGraphicsItem.h"
#include <QtGui>
class MyCentralEllipseItem : public MyCentralGraphicsItem
{
public:
	MyCentralEllipseItem(const QRectF & rect, QGraphicsItem * parent = 0);
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
		QWidget * widget = 0);
	int type() const{return Type;}
	QPainterPath shape() const;
private:
	enum { Type = 4 };
};
#endif	