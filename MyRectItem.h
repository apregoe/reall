#ifndef MYRECTITEM_H
#define MYRECTITEM_H
#include <QtGui>
#include <QtCore>
/*This object will be displayed in a fixed manner on MyOrganizationDockWidget
so that you can drag and drop it as MyCentralGraphicsRectItem
*/
class MyRectItem : public QGraphicsRectItem{
public:
	MyRectItem(const QRectF & rect, QGraphicsItem * parent = 0);
	enum { Type = 1 };
	//type() will be used to sens the type of item I am dropping into MyDropGraphicsScene
	int type() const{return Type;}
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	QDrag* drag;
	
};
#endif