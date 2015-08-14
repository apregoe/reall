#ifndef MYORGANIZATIONDOCKWIDGET_H
#define MYORGANIZATIONDOCKWIDGET_H
#include "MyRectItem.h"

class MyOrganizationDockWidget : public QDockWidget{
public:
	MyOrganizationDockWidget(const QString & title, QWidget * parent = 0, Qt::WindowFlags flags = 0);
private:
	QGraphicsScene* scene;
	void addShapes();
	MyRectItem* rectItem;
	QGraphicsEllipseItem* ellipseItem;
protected:
	void resizeEvent(QResizeEvent * event);
};
#endif