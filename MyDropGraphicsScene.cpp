#include <cmath>
#include "MyDropGraphicsScene.h"
#include "MyCentralRectItem.h"
#include "MyCentralRectRadiousItem.h"
#include "MyCentralEllipseItem.h"
using namespace std;

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
	else if(type == 4){
		item = new MyCentralEllipseItem(QRectF(point, QSizeF(40,40)));
		this->addItem(item);
	}
	item->setZValue(1);

	//Connecting the closest Item with the one that is being dropped!
	this->connect();//I also call this in MyCentralGraphicsItem, mousemove event is called
	//Gathering the closest points. The points will me added to a
	//priority queue in which the closestone will be on top

	QGraphicsScene::dropEvent(event);
}
void MyDropGraphicsScene::addItem(QGraphicsItem* item){
	if(item->type() == 3 || item->type() == 5){
		QGraphicsScene::addItem(item);
		return;
	}
	MyCentralGraphicsItem* item_ = dynamic_cast<MyCentralGraphicsItem*>(item);
	myItems.insert(0,item_);
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
	QList<MyCentralGraphicsItem *> myItems = this->items();
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
			if(p1->item->collidesWithItem(p2->item)){continue;}
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
		if(point->closestPoint == NULL){continue;}
		QLineF line(*point, *(point->closestPoint));
		//Now Ill have to get the type of each item to decrease the length of the line
		//so that it only touches the border of the item
		reduceLineToBorders(line, point, 0);
		point->connectingLine = addLine(line, QPen(Qt::green, 3));
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
	if(point->closestPoint == NULL){return;}
	if(point->closestPoint->closestPoint == NULL){return;}
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
	/*else if(point->item->type() == 4){//ellipse
		MyCentralGraphicsItem* item = dynamic_cast<MyCentralGraphicsItem*>(point->item);
		//ellipse variables
		double h = item->boundingRect().center().x();
		double k = item->boundingRect().center().y();
		QPointF p(h,k);
		p = item->mapToScene(p);
		h = p.x();
		k = p.y();

		double a2 = item->boundingRect().height()/2;
		a2 *= a2;
		double b2 = item->boundingRect().width()/2;
		b2 *= b2;

		//line variables
		double slope = ((line.y1()-line.y2())/(line.x1()-line.x2()));
		p = line.p1();
		double y_in = p.y() - (slope*p.x());

		//solving it
		double aCom, bCom, cCom;
		aCom = ((1/b2)+(pow(slope,2)/a2));
		bCom = ((2*h)/b2) + ((2*slope*y_in)/a2) + ((2*k*slope)/a2);
		bCom = -bCom;
		cCom = (pow(h,2)/b2) + (pow(y_in,2)/a2) + ((2*k*y_in)/a2) + (pow(k,2)/a2) -1;
//		qDebug() << aCom << bCom << cCom<<endl;


		double discriminant = (pow(bCom,2) - 4*aCom*cCom);
		float positive_root = (((-bCom) + sqrt(discriminant))/(2*aCom));
		double negative_root = (((-bCom) - sqrt(discriminant))/(2*aCom));

		//Final Root Values
		float positive_rootY = slope*positive_root - y_in;
		qDebug() << positive_root << positive_rootY<<endl;

		/*
		if(it == 0){line.setP1(QPointF(positive_root,positive_rootY));}
		else{line.setP2(QPointF(positive_root,positive_rootY));}*/
		
		///////////////
		/*
		float R= 20;

		float x0 = (item->mapToScene(item->shape().controlPointRect().center())).x();
		float y0 = (item->mapToScene(item->shape().controlPointRect().center())).y();
		if(line.x2() != line.x1()){
		QPointF yaxis_intersection;
		line.intersect( QLineF(QPointF(0, 10000), QPointF(0, -10000)), &yaxis_intersection);
		//line->intersect( QLineF(scene()->boundingRect().topLeft(),
		//		scene()->boundingRect().bottomRight()), &yaxis_intersection);

		float a = (line.y2() - line.y1())/(line.x2() - line.x1());
		float b = yaxis_intersection.y();

		float A = 1 + a*a;
		float B = 2*(a*b - a*y0 - x0);
		float C = x0 * x0 + y0*y0 + b*b - 2*b*y0 - R*R;

		float Q = B*B - 4*A*C;

		if(Q > 0){  
		    float s1 = (-1)*(B + sqrt(Q))/(2*A);
		    float s2 = (sqrt(Q) - B)/(2*A);
		    QPointF ps1(s1, a*s1 + b);
		    QPointF ps2(s2, a*s2 + b);
			//if(line.contains(ps1)){
				if(it == 0){line.setP1(ps1);}
				else{line.setP2(ps1);}
			}else{
				if(it == 0){line.setP1(ps2);}
				else{line.setP2(ps2);}
		}else{
			float s0 = (-1)*B/(2A);
			if(it == 0){line.setP1(QPointF(s0, as0 + b));}
			else{line.setP2(QPointF(s0, as0 + b));}
		}

		QPainterPath ellipsePath = item->shape();
		QPolygonF myPolygon;
		myPolygon << line.p1() << line.p2();
		QPainterPath linePath;
		linePath.addPolygon(myPolygon);
		addItem(new QGraphicsPolygonItem(myPolygon));

		QPainterPath collidingPath = ellipsePath.intersected(linePath);
		if(linePath.intersects(ellipsePath)){
			qDebug() << "true";
		}
		else{
			qDebug() << "false";
		}
		
	}*/
	reduceLineToBorders(line, point->closestPoint, ++it);
}





























