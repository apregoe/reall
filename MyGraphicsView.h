#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include "MyDropGraphicsScene.h"
#include <QObject>

class MyGraphicsView : public QGraphicsView{
Q_OBJECT
public:
	MyGraphicsView(MyDropGraphicsScene * scene, QWidget * parent = 0);
private:
	MyDropGraphicsScene* Scene;
protected:
	void dragEnterEvent ( QDragEnterEvent * event );
	void dragLeaveEvent ( QDragLeaveEvent * event );
	void dragMoveEvent ( QDragMoveEvent * event );
	void dropEvent ( QDropEvent * event );
};

#endif					