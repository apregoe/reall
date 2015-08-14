#include "MyRectItem.h"

MyRectItem::MyRectItem(const QRectF & rect, QGraphicsItem * parent)
		: QGraphicsRectItem(rect, parent){
}

void MyRectItem::mousePressEvent(QGraphicsSceneMouseEvent * event){

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