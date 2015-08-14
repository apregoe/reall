#include "MyDropGraphicsScene.h"

MyDropGraphicsScene::MyDropGraphicsScene(QObject * parent) : QGraphicsScene(parent){
}

void MyDropGraphicsScene::dropEvent ( QGraphicsSceneDragDropEvent * event ){
	QByteArray byteArray = event->mimeData()->data("MyItemType");
	int type = byteArray.toInt();
	QPointF point = event->scenePos();
	MyCentralGraphicsItem* item;
	if(type == 1){
		item = new MyCentralRectItem(QRectF(point, QSizeF(40,40)));
		addItem(item);
	}

	//Connecting the closest Item with the one that is being dropped!
	item->connect();
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

void MyDropGraphicsScene::addItem(QGraphicsItem * item){
	QGraphicsScene::addItem(item);
	this->addItemPoints(item);
}

void MyDropGraphicsScene::addItemPoints(QGraphicsItem* item){
	MyCentralGraphicsItem* item_ = dynamic_cast<MyCentralGraphicsItem*>(item);
	if(item_ != NULL){
		this->allPoints.insert(0,item_->up());
		this->allPoints.insert(0,item_->down());
		this->allPoints.insert(0,item_->left());
		this->allPoints.insert(0,item_->down());
	}

}

























