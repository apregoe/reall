#include "MyCentralEllipseItem.h"

MyCentralEllipseItem::MyCentralEllipseItem(const QRectF & rect, QGraphicsItem * parent)
		: MyCentralGraphicsItem(rect, parent){
}

void MyCentralEllipseItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
		QWidget * widget){
	painter->setPen(QPen(Qt::darkYellow, 3));
	painter->setBrush(QBrush(Qt::white));
	painter->drawEllipse(boundingRect());
}

QPainterPath MyCentralEllipseItem::shape() const{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}