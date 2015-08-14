#ifndef MYRECTITEM_H
#define MYRECTITEM_H
#include <QtGui>
#include <QtCore>
class MyRectItem : public QGraphicsRectItem{
public:
	MyRectItem(const QRectF & rect, QGraphicsItem * parent = 0);
	QRectF boundingRect() const;
	enum { Type = 1 };
	int type() const{return Type;}
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	enum ItemType {RectItem};
	QDrag* drag;
	
};
#endif