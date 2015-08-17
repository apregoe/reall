#include <cmath>
#include "MyDropGraphicsScene.h"
#include "MyCentralRectItem.h"
#include "MyCentralRectRadiousItem.h"

#define PI 3.14159265

MyDropGraphicsScene::MyDropGraphicsScene(QObject * parent) : QGraphicsScene(parent){
}

void MyDropGraphicsScene::dropEvent ( QGraphicsSceneDragDropEvent * event ){
	QByteArray byteArray = event->mimeData()->data("MyItemType");
	int type = byteArray.toInt();
	QPointF point = event->scenePos();
	MyCentralGraphicsItem* item;
	if(type == 1){
		item = new MyCentralRectItem(QRectF(point, QSizeF(40,40)));
		this->addItem(item);
	}
	else if(type == 2){
		item = new MyCentralRectRadiousItem(QRectF(point, QSizeF(40,40)));
		this->addItem(item);	
	}
	item->setZValue(1);

	//Connecting the closest Item with the one that is being dropped!
	this->connect();//I also call this in MyCentralGraphicsItem, mousemove event is called
	//Gathering the closest points. The points will me added to a
	//priority queue in which the closestone will be on top

	QGraphicsScene::dropEvent(event);
}
void MyDropGraphicsScene::addItem(MyCentralGraphicsItem* item){
	myItems.insert(0,item);
	QGraphicsScene::addItem(item);
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
		myMappedPoint->item = myItems[i];
		allPoints.insert(0,myMappedPoint);
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
		//Now Ill have to get the type of each item to decrease the length of the line
		//so that it only touches the border of the item
		reduceLineToBorders(line, point, 0);
		if(point->item->type() == 1){
			point->connectingLine = addLine(line);
		}
		else{
			point->connectingLine = addLine(line, QPen(Qt::blue, 3));
		}
		point->connectingLine->setZValue(0);
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

void MyDropGraphicsScene::reduceLineToBorders(QLineF & line, MyPointF * point, int it){
	if(it == 2){return;}
	if((point->item->type() ==1) || (point->item->type() == 2)){//its a rectangle
		//Determining in which cuadrant *point->closestPoint is
		MyCentralGraphicsItem* item = dynamic_cast<MyCentralGraphicsItem*>(point->item);
		//MyCentralGraphicsItem* item2 = dynamic_cast<MyCentralGraphicsItem*>(point->closestPoint->item);
		float x,y;
		if((line.angle() >= item->topRightAngle()) &&(line.angle() < item->topLeftAngle())){// up
			if(it == 0){
				y = point->y() - item->boundingRect().height()/2;
				x = point->x() + (item->boundingRect().height()/2)/(std::tan((line.angle()  * PI )/ 180.0));
			}
			else{
				y = point->y() + item->boundingRect().height()/2;
				x = point->x() - (item->boundingRect().height()/2)/(std::tan((line.angle()  * PI )/ 180.0));	
			}
		}
		else if((line.angle() >= item->topLeftAngle()) &&(line.angle() < item->bottomLeftAngle())){// left
			if(it == 0){
				x = point->x() - item->boundingRect().width()/2;
				y = point->y() + (item->boundingRect().width()/2)*(std::tan((line.angle()*PI)/180));
			}
			else{
				x = point->x() + item->boundingRect().width()/2;
				y = point->y() - (item->boundingRect().width()/2)*(std::tan((line.angle()*PI)/180));
			}
		}
		else if((line.angle() >= item->bottomLeftAngle()) && (line.angle() < item->bottomRightAngle())){//bottom
			if(it == 0){
				y = point->y() + item->boundingRect().height()/2;
				x = point->x() - (item->boundingRect().height()/2)/(std::tan((line.angle()  * PI )/ 180.0));
			}
			else{
				y = point->y() - item->boundingRect().height()/2;
				x = point->x() + (item->boundingRect().height()/2)/(std::tan((line.angle()  * PI )/ 180.0));	
			}
		}
		else if((line.angle() >= item->bottomRightAngle()) || (line.angle() <= item->topRightAngle())){ //right
			if(it == 0){
				x = point->x() + item->boundingRect().width()/2;
				y = point->y() - (item->boundingRect().width()/2)*(std::tan((line.angle()*PI)/180));
			}
			else{
				x = point->x() - item->boundingRect().width()/2;
				y = point->y() + (item->boundingRect().width()/2)*(std::tan((line.angle()*PI)/180));
			}
		}
		if(it == 0){line.setP1(QPointF(x,y));}
		else{line.setP2(QPointF(x,y));}

	}
	reduceLineToBorders(line, point->closestPoint, ++it);
}





























