#include "MyCentralRectItem.h"

MyCentralRectItem::MyCentralRectItem(const QRectF & rect, QGraphicsItem * parent)
		: MyCentralGraphicsItem(rect, parent){
	this->rect = rect;
	setAcceptHoverEvents(true);
}

void MyCentralRectItem::paint(QPainter * painter,
		const QStyleOptionGraphicsItem * option, QWidget * widget){
	QPen pen(Qt::green, 3);
	painter->setPen(pen);
	painter->setRenderHint(QPainter::Antialiasing);
	painter->drawRect(boundingRect());
	MyCentralGraphicsItem::updateConnectingPoints();
}