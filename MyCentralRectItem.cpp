#include "MyCentralRectItem.h"
#include "MyDropGraphicsScene.h"
#include "MainWindow.h"
#include <QPen>
#include <QPainter>

MyCentralRectItem::MyCentralRectItem(const QRectF & rect, QGraphicsItem * parent)
		: MyCentralGraphicsItem(rect, parent){
	setAcceptHoverEvents(true);
}

void MyCentralRectItem::paint(QPainter * painter,
		const QStyleOptionGraphicsItem * option, QWidget * widget){
	painter->setPen(*(MyCentralGraphicsItem::pen));
	painter->setRenderHint(QPainter::Antialiasing);
	painter->drawRect(boundingRect());
	MyCentralGraphicsItem::updateConnectingPoints();
	MyCentralGraphicsItem::paint(painter, option, widget);
}
void MyCentralRectItem::mousePressEvent(QGraphicsSceneMouseEvent * event){
	MyGraphicsView* myView = dynamic_cast<MyGraphicsView*>(scene()->views().at(0));
	MainWindow* window = dynamic_cast<MainWindow*>(myView->parent());
	if(window->painterCursorActivated()){
		MyDropGraphicsScene* scene = dynamic_cast<MyDropGraphicsScene*>(this->scene());
		MyCentralGraphicsItem::pen->setColor(scene->painterColor());
		this->update(boundingRect());
	}
	MyCentralGraphicsItem::mousePressEvent(event);
}