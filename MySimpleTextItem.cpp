#include "MySimpleTextItem.h"

MySimpleTextItem::MySimpleTextItem(const QString & text, QGraphicsItem * parent)
		: QGraphicsTextItem(text, parent){
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable,true);
}