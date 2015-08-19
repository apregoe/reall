#include "MySimpleTextItem.h"

MySimpleTextItem::MySimpleTextItem(const QString & text, QGraphicsItem * parent)
		: QGraphicsTextItem(text, parent){
	//Since this does not inherits from MyCentralGraphicsItem, I have to set the flags here
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable,true);
														//For some reason Qt::TextSelectableByMouse gives segfault
	setTextInteractionFlags(Qt::TextEditable | Qt::TextSelectableByKeyboard /*| Qt::TextSelectableByMouse*/);
}