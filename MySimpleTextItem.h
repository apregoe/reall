#ifndef MYSIMPLETEXTITEM_H
#define MYSIMPLETEXTITEM_H
#include <QtGui>

class MySimpleTextItem : public QGraphicsTextItem{
public:
	MySimpleTextItem(const QString & text, QGraphicsItem * parent = 0);
	int type() const{return Type;}
private:
	enum { Type = 5 };
};

#endif