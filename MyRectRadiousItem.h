#ifndef MYRECTRADIOUSITEM_H
#define MYRECTRADIOUSITEM_H
#include <QtGui>
#include <QtCore>
class MyRectRadiousItem : public QGraphicsRectItem{
public:
	MyRectRadiousItem(const QRectF & rect, QGraphicsItem * parent = 0);
	enum { Type = 2 };
	int type() const{return Type;}
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	QDrag* drag;
	
};
#endif