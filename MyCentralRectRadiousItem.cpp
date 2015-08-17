#include "MyCentralRectRadiousItem.h"
#include <QPen>
#include <QPainter>

MyCentralRectRadiousItem::MyCentralRectRadiousItem(const QRectF & rect, QGraphicsItem * parent)
		: MyCentralGraphicsItem(rect, parent){
	setAcceptHoverEvents(true);
}

void MyCentralRectRadiousItem::paint(QPainter * painter,
		const QStyleOptionGraphicsItem * option, QWidget * widget){
	this->pen = QPen(Qt::red, 3);
	painter->setPen(pen);
	painter->setRenderHint(QPainter::Antialiasing);
	QBrush brush(Qt::white);
	painter->setBrush(brush);
	radious = 45;
	painter->drawRoundedRect(boundingRect(), 45,45,Qt::RelativeSize);
	MyCentralGraphicsItem::updateConnectingPoints();
}