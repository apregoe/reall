#ifndef SYMBOL_H
#define SYMBOL_H
#include <QPointF>
#include <QGraphicsLineItem>
#include <QtCore>
#include <climits>
class MyPointF : public QPointF{
public:
	MyPointF() : QPointF(), connectingLine(NULL), closestDistance(LLONG_MAX),lineDrawn(false), closestPoint(NULL){}
	~MyPointF(){}
	//connectingLine is going to be a Qlist afterwards, divide and conquer.
	QGraphicsLineItem* connectingLine;
	MyPointF* closestPoint;
	bool lineDrawn;
	double closestDistance;
};
#endif