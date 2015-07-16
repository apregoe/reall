#ifndef MYGRAPHICSITEM_H
#define MYGRAPHICSITEM_H

#include <QGraphicsItem>
#include <iostream>

/**This Class is an abstract class that is going to
# be inherited by all of our items (MyGraphicsSquareItem, etc...)
# that will connect to each other once they
# are in the canvas/central\ widget/Graphics\ View**/

class MyGraphicsItem : public QGraphicsItem {
public:
	MyGraphicsItem();
	~MyGraphicsItem();

private:
	
};

#endif