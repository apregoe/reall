#include "MyCentralRectItem.h"

MyCentralRectItem::MyCentralRectItem(const QRectF & rect, QGraphicsItem * parent)
		: MyRectItem(rect, parent){
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable,true);
}