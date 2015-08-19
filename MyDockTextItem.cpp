#include "MyDockTextItem.h"

MyDockTextItem::MyDockTextItem(const QRectF & rect, QGraphicsItem * parent)
		: QAbstractGraphicsShapeItem(parent){
	this->rect = rect;
}

void MyDockTextItem::mousePressEvent(QGraphicsSceneMouseEvent * event){
	//This to bytearray
	QByteArray byteArray;
	byteArray.setNum(this->type());
	//inserting bytes to mimeData
	QMimeData* mimeData = new QMimeData;
	mimeData->setData("MyItemType", byteArray);

	drag = new QDrag(event->widget());
	drag->setMimeData(mimeData);
	drag->start();

	QAbstractGraphicsShapeItem::mousePressEvent(event);
}

void MyDockTextItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
		QWidget * widget){
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->setPen(QPen(Qt::black,2));
	painter->setFont(QFont("Georgia", 25));
	painter->drawText(rect, Qt::AlignCenter, "T");
}