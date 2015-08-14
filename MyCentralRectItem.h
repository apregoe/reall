#ifndef MYCENTRALRECTITEM_H
#define MYCENTRALRECTITEM_H
#include <QtGui>
#include <QtCore>
#include "MyRectItem.h"

class MyCentralRectItem : public MyRectItem {
public:
	MyCentralRectItem(const QRectF & rect, QGraphicsItem * parent = 0);
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event){
		QGraphicsRectItem::mousePressEvent(event);
	}
};
#endif