#include "MyGraphicsView.h"

MyGraphicsView::MyGraphicsView(MyDropGraphicsScene * scene, QWidget * parent)
		: QGraphicsView(scene), Scene(scene){
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