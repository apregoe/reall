#include <cmath>
#include "MyDropGraphicsScene.h"
#include "MyCentralRectItem.h"

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
	myItems.insert(0,item);

	//Connecting the closest Item with the one that is being dropped!
	this->connect();//I also call this in MyCentralGraphicsItem, mousemove event is called
	//Gathering the closest points. The points will me added to a
	//priority queue in which the closestone will be on top

	QGraphicsScene::dropEvent(event);
}

void MyDropGraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent * event){
	if(event && event->mimeData()){
		event->acceptProposedAction();
	}
}

QList<MyCentralGraphicsItem* > MyDropGraphicsScene::items() const{
	return myItems;
}

void MyDropGraphicsScene::connect(){
	//No segfault!

	QList<MyCentralGraphicsItem * > myItems = this->items();
	if(myItems.count() <= 1){
		return;
	}
	QList<MyPointF *> allPoints;
	for(int i = 0; i < myItems.count(); ++i){
		QPointF temp;
		temp.setX(myItems.at(i)->boundingRect().center().x());
		temp.setY(myItems.at(i)->boundingRect().center().y());
		QPointF mappedPoint = myItems.at(i)->mapToScene(temp);
		MyPointF* myMappedPoint = new MyPointF();
		myMappedPoint->setX(mappedPoint.x());
		myMappedPoint->setY(mappedPoint.y());
		allPoints.append(myMappedPoint);
	}

	for(int i = 0; i < allPoints.count(); ++i){
		//the next line is valid since allPoints.count() = myItems.count()
		MyCentralGraphicsItem* currentItem = myItems[i];
		for(int j = 0; j < allPoints.count(); ++j){
			MyPointF* p1 = allPoints[i];
			MyPointF* p2 = allPoints[j];
			if(p1 == p2){continue;}
			const double d = distance(p1, p2);
			if(p1->closestDistance > d){
				p1->closestDistance = d;
				p1->closestPoint = p2;
			}
		}
	}
	for(int i = 0; i < linesList.count(); ++i){
		removeItem(linesList[i]);
		delete linesList[i];
	}
	linesList.clear();
	for(int i = 0; i < allPoints.count(); ++i){
		MyPointF* point = allPoints[i];
		QLineF line(*point, *(point->closestPoint));

		point->connectingLine = addLine(line);
		linesList.append(point->connectingLine);
	}
	for(int i = 0; i < myItems.count(); ++i){
		delete allPoints[i];
	}

}

const double MyDropGraphicsScene::distance(const MyPointF * p1, const MyPointF * p2) const{
	double dx2 = std::pow(p1->x() - p2->x(), 2);
	double dy2 = std::pow(p1->y() - p2->y(),2);
	const double distance_ =  std::sqrt(dx2+dy2);
	return distance_;
}


















