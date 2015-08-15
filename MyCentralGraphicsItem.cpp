#include "MyCentralGraphicsItem.h"
#include "MyDropGraphicsScene.h"

MyCentralGraphicsItem::MyCentralGraphicsItem(const QRectF & rect, QGraphicsItem * parent)
		: QAbstractGraphicsShapeItem(parent), rMode(0), connectedItem(NULL), amIConnected(false){
	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable,true);
	this->rect = rect;
	updateConnectingPoints();
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
		setCursor(Qt::ArrowCursor);
	}
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
	if(verifyCorner(boundingRect().topLeft(), event->pos())){
		rMode = 1;
	}
	else if(verifyCorner(boundingRect().topRight(), event->pos())){
		rMode = 2;
	}
	else if(verifyCorner(boundingRect().bottomLeft(), event->pos())){
		rMode = 3;
	}
	else if(verifyCorner(boundingRect().bottomRight(), event->pos())){
		rMode = 4;
	}
	else{
		rMode = 0;
	}
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
			update();
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
			update();
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
			update();
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
			update();
		}
		connectScene();
		MyCentralGraphicsItem::updateConnectingPoints();
		return;
	}
	connectScene();
	MyCentralGraphicsItem::updateConnectingPoints();
	QAbstractGraphicsShapeItem::mouseMoveEvent(event);
}

void MyCentralGraphicsItem::connect(QList<QPointF> & newPoints){
	MyDropGraphicsScene* dropScene = dynamic_cast<MyDropGraphicsScene*>(this->scene());
	if(dropScene->items().count() <= 1){
		amIConnected = false;
		connectedItem = NULL;
		qDebug() << amIConnected<<endl;
	}
	else{
		amIConnected = true;

		connectedItem = NULL;
		qDebug() << amIConnected<<endl;
	}
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




















