#ifndef SYMBOL_H
#define SYMBOL_H
#include <QPointF>
#include <QGraphicsLineItem>
#include <QtCore>
#include <climits>
class MyPointF : public QPointF{
public:
	MyPointF() : QPointF(), connectingLine(NULL), item(NULL)
			, closestPoint(NULL), closestDistance(LLONG_MAX) {}
	~MyPointF(){}
	//connectingLine is going to be a Qlist afterwards, divide and conquer.
	QGraphicsLineItem* connectingLine;
	QGraphicsItem* item;
	MyPointF* closestPoint;
	double closestDistance;
};
#endif