#ifndef MYCENTRALELLIPSEITEM
#define MYCENTRALELLIPSEITEM
#include "MyCentralGraphicsItem.h"
#include <QtGui>
class MyCentralEllipseItem : public MyCentralGraphicsItem{
public:
	MyCentralEllipseItem(const QRectF & rect, QGraphicsItem * parent = 0);
	//paint() is used to draw the ellipse on the boundingRect()
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
		QWidget * widget = 0);
	//type() will be used to sens the type of item I am dropping into MyDropGraphicsScene
	int type() const{return Type;}
	QPainterPath shape() const;
	QRectF innerRect();
private:
	enum { Type = 4 };
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	//
	//The Hover event has to be used since, instead of the boundingrect corners of the
	//ellipse, we will use the inner rect corners to resize de ellipse.
	//So that when the user hovers over the inner conners the current cursor changes
	//the shape indicating that he can press and resize the ellipse
	//
	void hoverMoveEvent(QGraphicsSceneHoverEvent * event);
};
#endif	