#include "MyDropGraphicsScene.h"

MyDropGraphicsScene::MyDropGraphicsScene(QObject * parent) : QGraphicsScene(parent){
}

void MyDropGraphicsScene::dropEvent ( QGraphicsSceneDragDropEvent * event ){
	QByteArray byteArray = event->mimeData()->data("MyItemType");
	int type = byteArray.toInt();
	QPointF point = event->scenePos();
	qDebug() << "Type = "<< type<<endl;
	if(type == 1){
		QGraphicsItem* item = new QGraphicsRectItem(QRectF(point, QSizeF(20,20)));
		addItem(item);
	}

	//Connecting the closest Item with the one that is being dropped!

	//Gathering the closest points. The points will me added to a
	//priority queue in which the closestone will be on top

	QGraphicsScene::dropEvent(event);
}

void MyDropGraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent * event){
	if(event && event->mimeData()){
		event->acceptProposedAction();
	}
	QGraphicsScene::dragEnterEvent(event);
}