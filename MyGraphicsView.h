#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include "MyDropGraphicsScene.h"

class MyGraphicsView : public QGraphicsView{
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