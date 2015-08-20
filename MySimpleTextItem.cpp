#include "MySimpleTextItem.h"

MySimpleTextItem::MySimpleTextItem(const QString & text, QGraphicsItem * parent)
		: QGraphicsTextItem(text, parent){
	//Since this does not inherits from MyCentralGraphicsItem, I have to set the flags here
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable,true);
	
	setTextInteractionFlags(Qt::TextEditable | Qt::TextSelectableByKeyboard | Qt::TextSelectableByMouse);
}
void MySimpleTextItem::paint(QPainter *painter,
		const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QGraphicsTextItem::paint(painter,option,widget);
}