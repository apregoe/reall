#ifndef MYCENTRALGRAPHICSITEM_H
#define MYCENTRALGRAPHICSITEM_H
#include "MyDropGraphicsScene.h"

class MyCentralGraphicsItem : public QAbstractGraphicsShapeItem {
public:
	MyCentralGraphicsItem(const QRectF & rect, QGraphicsItem * parent = 0);
	QRectF boundingRect() const;
	void connect();
	QPointF up() const {return pUp;}
	QPointF down() const{return pDown;}
	QPointF right() const {return pRight;}
	QPointF left() const {return pLeft;}
protected:
	void hoverMoveEvent(QGraphicsSceneHoverEvent * event);
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
	bool verifyCorner(const QPointF & p1,const QPointF & p2);
	QRectF rect;
	int resizeMode() const{return rMode;}
	void updateConnectingPoints();
private:
	int rMode;
	QGraphicsItem* connectedItem;
	bool amIConnected;
	QPointF pUp, pDown, pRight, pLeft;
	
};
#endif