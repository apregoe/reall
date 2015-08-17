#ifndef MYBRUSHITEM_H
#define MYBRUSHITEM_H
#include <QtGui>
#include <QtCore>
class MyBrushItem : public QGraphicsItem {
public:
	MyBrushItem(QPointF point, QGraphicsItem * parent = 0);
	QRectF boundingRect() const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
	int type() const{
		return 3;
	}
private:
	QPointF point;
};
#endif