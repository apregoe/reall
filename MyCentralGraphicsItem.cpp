#include "MyCentralGraphicsItem.h"
#include "MyDropGraphicsScene.h"
#include "MainWindow.h"
#include <QtGui>

MyCentralGraphicsItem::MyCentralGraphicsItem(const QRectF & rect, QGraphicsItem * parent)
		: QAbstractGraphicsShapeItem(parent), rMode(0), connectedItem(NULL), amIConnected(false){
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable,true);
    QPixmap pMap = QPixmap("brush.png");
    pen = new QPen(Qt::black,3);
    painterCursor = new QCursor(pMap.scaled(QSize(14,14)), Qt::IgnoreAspectRatio);
	this->rect = rect;
	updateConnectingPoints();
}
void MyCentralGraphicsItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
		QWidget * widget){
	if(isSelected()){
		QPen dottedPen(Qt::black,1);
		dottedPen.setStyle(Qt::DashLine);
		painter->setPen(dottedPen);
		painter->setBrush(QBrush(Qt::NoBrush));
		painter->drawRect(boundingRect());
	}
}

void MyCentralGraphicsItem::hoverMoveEvent(QGraphicsSceneHoverEvent * event){
	if(verifyCorner(boundingRect().topLeft(), event->pos())){
		setCursor(Qt::SizeFDiagCursor);
	}
	else if(verifyCorner(boundingRect().topRight(), event->pos())){
		setCursor(Qt::SizeBDiagCursor);
	}
	else if(verifyCorner(boundingRect().bottomLeft(), event->pos())){
		setCursor(Qt::SizeBDiagCursor);
	}
	else if(verifyCorner(boundingRect().bottomRight(), event->pos())){
		setCursor(Qt::SizeFDiagCursor);
	}
	else{
		MyGraphicsView* myView = dynamic_cast<MyGraphicsView*>(scene()->views().at(0));
		MainWindow* window = dynamic_cast<MainWindow*>(myView->parent());
		if(window->painterCursorActivated()){
			setCursor(*painterCursor);
		}else{setCursor(Qt::ArrowCursor);}
	}
	QAbstractGraphicsShapeItem::hoverMoveEvent(event);
}

QRectF MyCentralGraphicsItem::boundingRect() const{
	return rect;
}

bool MyCentralGraphicsItem::verifyCorner(const QPointF & p1, const QPointF & p2){
	if((p1.x() <= p2.x()+8) && (p1.x() >= p2.x() -8)){
		if((p1.y() <= p2.y()+8) && (p1.y() >= p2.y() -8)){
			return true;
		}
	}	
	return false;
}

void MyCentralGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent * event){
	MyGraphicsView* myView = dynamic_cast<MyGraphicsView*>(scene()->views().at(0));
	MainWindow* window = dynamic_cast<MainWindow*>(myView->parent());
	if(window->painterCursorActivated()){
		MyDropGraphicsScene* scene = dynamic_cast<MyDropGraphicsScene*>(this->scene());
		pen->setColor(scene->painterColor());
	}
	if(verifyCorner(boundingRect().topLeft(), event->pos())){
		setResizeMode(1);
	}
	else if(verifyCorner(boundingRect().topRight(), event->pos())){
		setResizeMode(2);
	}
	else if(verifyCorner(boundingRect().bottomLeft(), event->pos())){
		setResizeMode(3);
	}
	else if(verifyCorner(boundingRect().bottomRight(), event->pos())){
		setResizeMode(4);
	}
	else{
		setResizeMode(0);
	}
	update(boundingRect());
	QAbstractGraphicsShapeItem::mousePressEvent(event);
}


void MyCentralGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent * event){
	if(resizeMode() != 0){
		int mode = resizeMode();
		prepareGeometryChange();
		QPointF lastPos = event->lastPos();
		QPointF pos = event->pos();
		QRectF oldRect = rect;
		if(mode == 1){//top left
			if(rect.height() <= 20){
				if((lastPos.y()-pos.y()) < 0){
					return;
				}
			}
			if(rect.width() <= 20){
				if((lastPos.x()-pos.x()) < 0){
					return;
				}
			}
			int newWidth = rect.width()+(lastPos.x()-pos.x());
			int newHeight = rect.height() + (lastPos.y()-pos.y());
			rect = QRectF(pos, QSize(newWidth, newHeight));
			update(boundingRect());
		}
		else if(mode == 2){//top right
			if(rect.height() <= 20){
				if((lastPos.y()-pos.y()) < 0){
					return;
				}
			}
			if(rect.width() <= 20){
				if((pos.x()-lastPos.x()) < 0){
					return;
				}
			}
			int newWidth = rect.width()+(pos.x()-lastPos.x());
			int newHeight = rect.height() + (lastPos.y()-pos.y());
			pos.setX(oldRect.topLeft().x());
			rect = QRectF(pos, QSize(newWidth, newHeight));
			update(boundingRect());
		}
		else if(mode == 3){//bottomLeft
			if(rect.height() <= 20){
				if((lastPos.y()-pos.y()) > 0){
					return;
				}
			}
			if(rect.width() <= 20){
				if((pos.x()-lastPos.x()) > 0){
					return;
				}
			}
			int newWidth = rect.width()+(lastPos.x()-pos.x());
			int newHeight = rect.height() + (pos.y()-lastPos.y());
			pos.setY(oldRect.topLeft().y());
			rect = QRectF(pos, QSize(newWidth, newHeight));
			update(boundingRect());
		}
		else if(mode == 4){//bottomRight
			if(rect.height() <= 20){
				if((lastPos.y()-pos.y()) > 0){
					return;
				}
			}
			if(rect.width() <= 20){
				if((lastPos.x()-pos.x()) > 0){
					return;
				}
			}
			int newWidth = rect.width()+(pos.x()-lastPos.x());
			int newHeight = rect.height() + (pos.y()-lastPos.y());
			pos.setY(oldRect.topLeft().y());
			pos.setX(oldRect.topLeft().x());
			rect = QRectF(pos, QSize(newWidth, newHeight));
			update(boundingRect());
		}
		connectScene();
		MyCentralGraphicsItem::updateConnectingPoints();
		return;
	}
	connectScene();
	MyCentralGraphicsItem::updateConnectingPoints();
	QAbstractGraphicsShapeItem::mouseMoveEvent(event);
}


void MyCentralGraphicsItem::updateConnectingPoints(){
	pUp = QPointF((rect.topLeft().x()+rect.topRight().x())/2, rect.topLeft().y());
	pDown = QPointF((rect.bottomLeft().x()+rect.bottomRight().x())/2, rect.topLeft().y());
	pRight = QPointF(rect.topLeft().x(), (rect.topRight().y()+rect.bottomRight().y())/2);
	pLeft = QPointF(rect.topLeft().x(), (rect.topLeft().y()+rect.bottomLeft().y())/2);
}


void MyCentralGraphicsItem::connectScene(){
	MyDropGraphicsScene* dropScene = dynamic_cast<MyDropGraphicsScene*>(this->scene());
	dropScene->connect();
}

double MyCentralGraphicsItem::topRightAngle(){
	QRectF rect = boundingRect();
	QPointF point = rect.topRight();
	QPointF center = rect.center();
	QLineF line(center, point);
	return line.angle();
}
double MyCentralGraphicsItem::topLeftAngle(){
	QRectF rect = boundingRect();
	QPointF point = rect.topLeft();
	QPointF center = rect.center();
	QLineF line(center, point);
	return line.angle();
}
double MyCentralGraphicsItem::bottomRightAngle(){
	QRectF rect = boundingRect();
	QPointF point = rect.bottomRight();
	QPointF center = rect.center();
	QLineF line(center, point);
	return line.angle();
}
double MyCentralGraphicsItem::bottomLeftAngle(){
	QRectF rect = boundingRect();
	QPointF point = rect.bottomLeft();
	QPointF center = rect.center();
	QLineF line(center, point);
	return line.angle();
}


















