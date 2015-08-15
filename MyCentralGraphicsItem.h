#ifndef MYCENTRALGRAPHICSITEM_H
#define MYCENTRALGRAPHICSITEM_H
#include <QAbstractGraphicsShapeItem>

class MyCentralGraphicsItem : public QAbstractGraphicsShapeItem {
public:
	MyCentralGraphicsItem(const QRectF & rect, QGraphicsItem * parent = 0);
	QRectF boundingRect() const;
	void connect(QList<QPointF> & newPoints);
	QPointF * up() {return &pUp;}
	QPointF * down() {return &pDown;}
	QPointF * right() {return &pRight;}
	QPointF * left() {return &pLeft;}
protected:
	void hoverMoveEvent(QGraphicsSceneHoverEvent * event);
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
	bool verifyCorner(const QPointF & p1,const QPointF & p2);
	QRectF rect;
	int resizeMode() const{return rMode;}
	void updateConnectingPoints();
private:
	void connectScene();
	int rMode;
	QGraphicsItem* connectedItem;
	QPointF closestPoint;
	bool amIConnected;
	QPointF pUp, pDown, pRight, pLeft;
	
};
#endif