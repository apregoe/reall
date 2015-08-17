#include "MyEllipseItem.h"

MyEllipseItem::MyEllipseItem(const QRectF & rect, QGraphicsItem * parent)
		: QGraphicsEllipseItem(rect, parent){
}

void MyEllipseItem::mousePressEvent(QGraphicsSceneMouseEvent * event){
	//This to bytearray
	QByteArray byteArray;
	byteArray.setNum(this->type());
	//inserting bytes to mimeData
	QMimeData* mimeData = new QMimeData;
	mimeData->setData("MyItemType", byteArray);

	drag = new QDrag(event->widget());
	drag->setMimeData(mimeData);
	drag->start();

	QGraphicsEllipseItem::mousePressEvent(event);
}