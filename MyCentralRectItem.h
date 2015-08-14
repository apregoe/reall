#ifndef MYCENTRALRECTITEM_H
#define MYCENTRALRECTITEM_H
#include "MyCentralGraphicsItem.h"

class MyCentralRectItem : public MyCentralGraphicsItem {
public:
	MyCentralRectItem(const QRectF & rect, QGraphicsItem * parent = 0);
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
			QWidget * widget = 0);
};
#endif