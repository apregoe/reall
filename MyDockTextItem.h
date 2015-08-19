#ifndef MYDOCKTEXTITEM_H
#define MYDOCKTEXTITEM_H
#include <QtGui>
#include <QtCore>
class MyDockTextItem : public QAbstractGraphicsShapeItem{
public:
	MyDockTextItem(const QRectF & rect, QGraphicsItem * parent = 0);
	enum { Type = 5 };
	int type() const{return Type;}
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
		QWidget * widget = 0);
	QRectF boundingRect() const{return this->rect;}
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	QDrag* drag;
private:
	QRectF rect;
};
#endif