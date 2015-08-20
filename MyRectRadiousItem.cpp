#include "MyRectRadiousItem.h"

MyRectRadiousItem::MyRectRadiousItem(const QRectF & rect, QGraphicsItem * parent)
		: QGraphicsRectItem(rect, parent){
	setFlag(QGraphicsItem::ItemIsMovable, false);
	setFlag(QGraphicsItem::ItemIsSelectable,true);
}
void MyRectRadiousItem::paint(QPainter * painter,
		const QStyleOptionGraphicsItem * option, QWidget * widget){
	Q_UNUSED(option);
	Q_UNUSED(widget);
	QPen pen(Qt::black, 1.5);
	painter->setPen(pen);
	painter->setRenderHint(QPainter::Antialiasing);
	painter->drawRoundedRect(boundingRect(), 15,15,Qt::RelativeSize);
}

void MyRectRadiousItem::mousePressEvent(QGraphicsSceneMouseEvent * event){

	//This to bytearray
	QByteArray byteArray;
	byteArray.setNum(this->type());
	//inserting bytes to mimeData
	QMimeData* mimeData = new QMimeData;
	mimeData->setData("MyItemType", byteArray);

	drag = new QDrag(event->widget());
	drag->setMimeData(mimeData);
	drag->start();

	QGraphicsRectItem::mousePressEvent(event);
}