#include "MyOrganizationDockWidget.h"

MyOrganizationDockWidget::MyOrganizationDockWidget(
		const QString & title, QWidget * parent, Qt::WindowFlags flags)
		: QDockWidget(title, parent, flags){

	this->setFixedWidth(200);

	addShapes();
}

void MyOrganizationDockWidget::addShapes(){
	scene = new QGraphicsScene();
	QGraphicsView* view = new QGraphicsView(scene);

	scene->setSceneRect(this->rect());
	view->setSceneRect(this->rect());

	QPointF point(this->rect().topLeft());
	QRectF rect(QPointF(point.x()+2, point.y()), QSizeF(20,20));
	rectItem = new MyRectItem(rect);
	scene->addItem(rectItem);

	point = QPointF(rectItem->boundingRect().topRight());
	rect = QRectF(QPointF(point.x()+5,point.y()), QSizeF(20,20));
	radiousRectItem = new MyRectRadiousItem(rect);
	scene->addItem(radiousRectItem);

	point = QPointF(radiousRectItem->boundingRect().topRight());
	rect = QRectF(QPointF(point.x()+5,point.y()), QSizeF(20,20));
	ellipseItem = new MyEllipseItem(rect);
	scene->addItem(ellipseItem);

	point = QPointF(ellipseItem->boundingRect().topRight());
	rect = QRectF(QPointF(point.x()+5,point.y()), QSizeF(20,20));
	textEditItem = new MyDockTextItem(rect);
	scene->addItem(textEditItem);
	
	view->setHorizontalScrollBarPolicy (Qt::ScrollBarAsNeeded);
	view->setVerticalScrollBarPolicy (Qt::ScrollBarAsNeeded);
	this->setWidget(view);
}

void MyOrganizationDockWidget::resizeEvent(QResizeEvent * event){ 
	QPointF point(this->rect().topLeft());
	rectItem->update(point.x(), point.y(), 20,20);
	QDockWidget::resizeEvent(event);
}
















