#include "MyCentralRectRadiousItem.h"
#include "MyDropGraphicsScene.h"
#include "MainWindow.h"
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
	painter->setPen(*(MyCentralGraphicsItem::pen));
	painter->setRenderHint(QPainter::Antialiasing);
	QBrush brush(Qt::white);
	painter->setBrush(brush);
	radious = 45;
	painter->drawRoundedRect(boundingRect(), 45,45,Qt::RelativeSize);
	MyCentralGraphicsItem::updateConnectingPoints();
	MyCentralGraphicsItem::paint(painter, option, widget);
}

void MyCentralRectRadiousItem::mousePressEvent(QGraphicsSceneMouseEvent * event){
	MyGraphicsView* myView = dynamic_cast<MyGraphicsView*>(scene()->views().at(0));
	MainWindow* window = dynamic_cast<MainWindow*>(myView->parent());
	if(window->painterCursorActivated()){
		MyDropGraphicsScene* scene = dynamic_cast<MyDropGraphicsScene*>(this->scene());
		MyCentralGraphicsItem::pen->setColor(scene->painterColor());
		this->update(boundingRect());
	}
	MyCentralGraphicsItem::mousePressEvent(event);
}