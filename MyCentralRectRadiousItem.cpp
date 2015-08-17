#include "MyCentralRectRadiousItem.h"
#include "MyDropGraphicsScene.h"
#include <QPen>
#include <QPainter>

MyCentralRectRadiousItem::MyCentralRectRadiousItem(const QRectF & rect, QGraphicsItem * parent)
		: MyCentralGraphicsItem(rect, parent){
	setAcceptHoverEvents(true);
	/*brushItem = new MyBrushItem(QPointF(10,10));
	MyDropGraphicsScene* dropScene = dynamic_cast<MyDropGraphicsScene*>(this->scene());
	dropScene->addItem(brushItem);
	brushItem->hide();
	*/
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
	MyCentralGraphicsItem::paint(painter, option, widget);
}

void MyCentralRectRadiousItem::mousePressEvent(QGraphicsSceneMouseEvent * event){
	/*if(isSelected()){
		brushItem->show();
	}
	else{
		brushItem->hide();
	}*/
	MyCentralGraphicsItem::mousePressEvent(event);
}