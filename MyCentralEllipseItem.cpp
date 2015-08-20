#include <cmath>
#include "MyCentralEllipseItem.h"
#include "MainWindow.h"

MyCentralEllipseItem::MyCentralEllipseItem(const QRectF & rect, QGraphicsItem * parent)
		: MyCentralGraphicsItem(rect, parent){
	setAcceptHoverEvents(true);
}

void MyCentralEllipseItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
		QWidget * widget){
	 /*since the items can change of colors, I use the QPen provided by MyCentralGraphicsRectItem
	 *which is a pointer to a pen that has the color chosen by the user when they hit the brush
	 *in the toolbal
	 */
	painter->setPen(*(MyCentralGraphicsItem::pen));
	painter->setRenderHint(QPainter::Antialiasing);
	 /*The followinf line of code makes the backgound of this ellipse white.
	 *This is not the best way to get the connecting line to the border of
	 *the item, it should be changed. The line is actually directly connected
	 *to the center of this item, not to the ellipse borders. Check
	 *MyDropGraphicsScene::reduceLineToBorders() in MyDropGraphicsScene to
	 *see my attempts to move the line to the border of the ellipse.
	*/
	painter->setBrush(QBrush(Qt::white));
	painter->drawEllipse(boundingRect());
	 /*if its selected, I have to draw the inner rectangle of so that the user
	 *knows where to hover,press, and move in order to resize the ellipse
	 *I directly use the innerRect() to draw the inner rectangle
	 */
	if(isSelected()){
		QPen dottedPen(Qt::black,1);
		dottedPen.setStyle(Qt::DashLine);
		painter->setPen(dottedPen);
		painter->setBrush(QBrush(Qt::NoBrush));
		painter->drawRect(this->innerRect());
	}
	 /*I call the following function since MyCentralGraphicsitem::paint()
	 *draws the bounding rectangle of the item;
	 */
	MyCentralGraphicsItem::paint(painter, option, widget);
}

QPainterPath MyCentralEllipseItem::shape() const{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

QRectF MyCentralEllipseItem::innerRect(){
	QRectF r = boundingRect();
	 /*The following formula to get the points of the largest inner rectangle in the ellipse was taken from here:
	 * http://math.stackexchange.com/questions/210695/how-to-find-the-largest-rectangle-inside-an-ellipse
	 */
	float a = r.width()/2.0;
	float b = r.height()/2.0;
	float x = a*(std::sqrt(2))/2.0;
	float y = b*(std::sqrt(2))/2.0;
	QRectF returnRect(QPointF(x,-y),QPointF(-x,y));
	/*I move it to the center of this item, otherwise, the inner rectangle would be drawn set in the top left
	 *corner of the graphicsScene
	 */
	returnRect.moveCenter(boundingRect().center());
	return returnRect;

}

void MyCentralEllipseItem::mousePressEvent(QGraphicsSceneMouseEvent * event){
	MyGraphicsView* myView = dynamic_cast<MyGraphicsView*>(scene()->views().at(0));
	MainWindow* window = dynamic_cast<MainWindow*>(myView->parent());
	//If the painterCursor is activated, then this item color should be changed. 
	if(window->painterCursorActivated()){
		MyDropGraphicsScene* scene = dynamic_cast<MyDropGraphicsScene*>(this->scene());
		MyCentralGraphicsItem::pen->setColor(scene->painterColor());
		this->update(boundingRect());
	}
	 /*This part is different from MyCentralGraphicsItem::mousePressEvent()
	 *since I have to use the inner rectangle, instead of the bounding rectangle
	 *check mousePressEvent() in MyCentralGraphicsItem.cpp to see the difference
	 *in the following if statements
	 */
	if(verifyCorner(innerRect().topLeft(), event->pos())){
		setResizeMode(2);
	}
	else if(verifyCorner(innerRect().topRight(), event->pos())){
		setResizeMode(1);
	}
	else if(verifyCorner(innerRect().bottomLeft(), event->pos())){
		setResizeMode(4);
	}
	else if(verifyCorner(innerRect().bottomRight(), event->pos())){
		setResizeMode(3);
	}
	else{
		setResizeMode(0);
	}
	 /*I dont use MyCentralGraphicsItem::mousePressEvent(event) here since
	 *its implementation of this event handler uses the boundingRect(), 
	 *instead of the innerRect()
	 */
	QAbstractGraphicsShapeItem::mousePressEvent(event);
}

void MyCentralEllipseItem::hoverMoveEvent(QGraphicsSceneHoverEvent * event){
	 /*same as MyCentralEllipseItem::mousePressEvent(), I have to
	 *once again I have to  re-implement the if statemnts logic
	 *since I use the bounding rectangle, instead of the inner rectangle
	 *check mhoverMoveEvent() in MyCentralGraphicsItem.cpp to see the difference
	 *in the following if statements
	 */
	if(verifyCorner(innerRect().topLeft(), event->pos())){
		setCursor(Qt::SizeBDiagCursor);
	}
	else if(verifyCorner(innerRect().topRight(), event->pos())){
		setCursor(Qt::SizeFDiagCursor);
	}
	else if(verifyCorner(innerRect().bottomLeft(), event->pos())){
		setCursor(Qt::SizeFDiagCursor);
	}
	else if(verifyCorner(innerRect().bottomRight(), event->pos())){
		setCursor(Qt::SizeBDiagCursor);
	}
	else{
		MyGraphicsView* myView = dynamic_cast<MyGraphicsView*>(scene()->views().at(0));
		MainWindow* window = dynamic_cast<MainWindow*>(myView->parent());
		 /*there are two options, either the user wants to repaint or just move the
		 *item. if the painter cursor is activated that means that the user choose
		 *a color from the brush in the tool bar
		 */
		if(window->painterCursorActivated()){
			setCursor(getPainterCursor());
			window->setCursor(getPainterCursor());
			myView->setCursor(getPainterCursor());
		}else{
			this->setCursor(Qt::ArrowCursor);
			window->setCursor(Qt::ArrowCursor);
			myView->setCursor(Qt::ArrowCursor);
		}
	}
	QAbstractGraphicsShapeItem::hoverMoveEvent(event);
}






















