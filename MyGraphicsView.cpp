#include "MyGraphicsView.h"
#include <QtCore>

MyGraphicsView::MyGraphicsView(MyDropGraphicsScene * scene, QWidget * parent)
		: QGraphicsView(scene), Scene(scene){
	Q_UNUSED(parent);
	setRenderHint(QPainter::Antialiasing);
	connect(Scene, SIGNAL(selectionChanged()), this, SLOT(selectionChanged()));
}
void MyGraphicsView::selectionChanged(){
}
void MyGraphicsView::dragEnterEvent ( QDragEnterEvent * event ){
	QGraphicsView::dragEnterEvent(event);
}
void MyGraphicsView::dragLeaveEvent ( QDragLeaveEvent * event ){
	QGraphicsView::dragLeaveEvent(event);
}
void MyGraphicsView::dragMoveEvent ( QDragMoveEvent * event ){
	QGraphicsView::dragMoveEvent(event);
}
void MyGraphicsView::dropEvent ( QDropEvent * event ){
	QGraphicsView::dropEvent(event);
}