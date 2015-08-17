#include "MyCentralRectItem.h"
#include "MyDropGraphicsScene.h"
#include <QPen>
#include <QPainter>

MyCentralRectItem::MyCentralRectItem(const QRectF & rect, QGraphicsItem * parent)
		: MyCentralGraphicsItem(rect, parent){
	setAcceptHoverEvents(true);
	
	/*brushItem = new MyBrushItem(QPointF(10,10));
	MyDropGraphicsScene* dropScene = dynamic_cast<MyDropGraphicsScene*>(this->scene());
	dropScene->addItem(brushItem);
	brushItem->hide();*/
}

void MyCentralRectItem::paint(QPainter * painter,
		const QStyleOptionGraphicsItem * option, QWidget * widget){
	this->pen = QPen(Qt::green, 3);
	painter->setPen(pen);
	painter->setRenderHint(QPainter::Antialiasing);
	QBrush brush(Qt::white);
	painter->setBrush(brush);
	painter->drawRect(boundingRect());
	MyCentralGraphicsItem::updateConnectingPoints();
	MyCentralGraphicsItem::paint(painter, option, widget);
}
void MyCentralRectItem::mousePressEvent(QGraphicsSceneMouseEvent * event){
	/*if(isSelected()){
		brushItem->show();
	}
	else{
		brushItem->hide();
	}*/
	MyCentralGraphicsItem::mousePressEvent(event);
}