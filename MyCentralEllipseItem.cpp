#include <cmath>
#include "MyCentralEllipseItem.h"
#include "MainWindow.h"

MyCentralEllipseItem::MyCentralEllipseItem(const QRectF & rect, QGraphicsItem * parent)
		: MyCentralGraphicsItem(rect, parent){
	setAcceptHoverEvents(true);
}

void MyCentralEllipseItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
		QWidget * widget){
	painter->setPen(*(MyCentralGraphicsItem::pen));
	painter->setRenderHint(QPainter::Antialiasing);
	painter->setBrush(QBrush(Qt::white));
	painter->drawEllipse(boundingRect());
	if(isSelected()){
		QPen dottedPen(Qt::black,1);
		dottedPen.setStyle(Qt::DashLine);
		painter->setPen(dottedPen);
		painter->setBrush(QBrush(Qt::NoBrush));
		painter->drawRect(this->innerRect());
	}
	MyCentralGraphicsItem::paint(painter, option, widget);
}

QPainterPath MyCentralEllipseItem::shape() const{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

QRectF MyCentralEllipseItem::innerRect(){
	QRectF r = boundingRect();
	float a = r.width()/2;
	float b = r.height()/2;
	float x = a*(std::sqrt(2))/2.0;
	float y = b*(std::sqrt(2))/2.0;
	QRectF returnRect(QPointF(x,-y),QPointF(-x,y));
	returnRect.moveCenter(boundingRect().center());
	return returnRect;

}

void MyCentralEllipseItem::mousePressEvent(QGraphicsSceneMouseEvent * event){
	MyGraphicsView* myView = dynamic_cast<MyGraphicsView*>(scene()->views().at(0));
	MainWindow* window = dynamic_cast<MainWindow*>(myView->parent());
	if(window->painterCursorActivated()){
		MyDropGraphicsScene* scene = dynamic_cast<MyDropGraphicsScene*>(this->scene());
		MyCentralGraphicsItem::pen->setColor(scene->painterColor());
		this->update(boundingRect());
	}
	if(verifyCorner(innerRect().topLeft(), event->pos())){
		setResizeMode(2);
	}
	else if(verifyCorner(innerRect().topRight(), event->pos())){
		setResizeMode(1);
	}
	else if(verifyCorner(innerRect().bottomLeft(), event->pos())){
		setResizeMode(4);
	}
	else if(verifyCorner(innerRect().bottomRight(), event->pos())){
		setResizeMode(3);
	}
	else{
		setResizeMode(0);
	}
	update(boundingRect());
	QAbstractGraphicsShapeItem::mousePressEvent(event);
}

void MyCentralEllipseItem::hoverMoveEvent(QGraphicsSceneHoverEvent * event){
	if(verifyCorner(innerRect().topLeft(), event->pos())){
		setCursor(Qt::SizeBDiagCursor);
	}
	else if(verifyCorner(innerRect().topRight(), event->pos())){
		setCursor(Qt::SizeFDiagCursor);
	}
	else if(verifyCorner(innerRect().bottomLeft(), event->pos())){
		setCursor(Qt::SizeFDiagCursor);
	}
	else if(verifyCorner(innerRect().bottomRight(), event->pos())){
		setCursor(Qt::SizeBDiagCursor);
	}
	else{
		MyGraphicsView* myView = dynamic_cast<MyGraphicsView*>(scene()->views().at(0));
		MainWindow* window = dynamic_cast<MainWindow*>(myView->parent());
		if(window->painterCursorActivated()){
			setCursor(getPainterCursor());
		}else{setCursor(Qt::ArrowCursor);}
	}
	QAbstractGraphicsShapeItem::hoverMoveEvent(event);
}






















