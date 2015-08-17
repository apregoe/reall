#include "MyBrushItem.h"

MyBrushItem::MyBrushItem(QPointF point, QGraphicsItem * parent)
		: QGraphicsItem(parent){
	this->point = point;
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable,true);
}
QRectF MyBrushItem::boundingRect() const{
	return QRectF(point, QSizeF(15,15));
}

void MyBrushItem::paint(QPainter * painter
		,const QStyleOptionGraphicsItem * option, QWidget * widget){
	QPixmap pm("brush.png");
	pm = pm.scaled(15,15);
	painter->drawPixmap(point, pm);
}

