#ifndef MYELLIPSEITEM_H
#define MYELLIPSEITEM_H
#include <QtGui>
#include <QtCore>
class MyEllipseItem : public QGraphicsEllipseItem{
public:
	MyEllipseItem(const QRectF & rect, QGraphicsItem * parent = 0);
	enum { Type = 4 };
	int type() const{return Type;}
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	QDrag* drag;
	
};
#endif