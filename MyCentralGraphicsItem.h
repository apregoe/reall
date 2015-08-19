#ifndef MYCENTRALGRAPHICSITEM_H
#define MYCENTRALGRAPHICSITEM_H
#include <QAbstractGraphicsShapeItem>
#include <QtGui>
#include <QtCore>

class MyCentralGraphicsItem : public QAbstractGraphicsShapeItem {
public:
	MyCentralGraphicsItem(const QRectF & rect, QGraphicsItem * parent = 0);
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
		QWidget * widget = 0);
	QRectF boundingRect() const;
	QPointF * up() {return &pUp;}
	QPointF * down() {return &pDown;}
	QPointF * right() {return &pRight;}
	QPointF * left() {return &pLeft;}
	double topRightAngle();
	double topLeftAngle();
	double bottomRightAngle();
	double bottomLeftAngle();
	virtual int type() const = 0;
	QCursor getPainterCursor(){return painterCursor;}
	// if inheriting from this class, you might want to define enum { Type = x}; as a private member
protected:
	void hoverMoveEvent(QGraphicsSceneHoverEvent * event);
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
	bool verifyCorner(const QPointF & p1,const QPointF & p2);
	int resizeMode() const{return rMode;}
	void setResizeMode(int i){rMode = i;}
	void updateConnectingPoints();
	QPen* pen;
private:
	void connectScene();
	int rMode;
	QPointF closestPoint;
	QRectF rect;
	QCursor painterCursor;
 	QPointF pUp, pDown, pRight, pLeft;
	
};
#endif