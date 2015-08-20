#ifndef MYCENTRALELLIPSEITEM
#define MYCENTRALELLIPSEITEM
#include "MyCentralGraphicsItem.h"
#include <QtGui>
class MyCentralEllipseItem : public MyCentralGraphicsItem{
public:
	MyCentralEllipseItem(const QRectF & rect, QGraphicsItem * parent = 0);
	/*!
	 * \brief Inherits from MyCentralGraphicsItem to draw the shape of the item.
	 *
	 * Called whenever there is a change in this Item (resize, move, etc).
	 * Used to draw the ellipse on the boundingRect().
	 */
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option,
		QWidget * widget = 0);

	/*!
	 *type() will be used to get the type of item I am dropping into MyDropGraphicsScene
	 *or in some other ocassions when you dont know which item is which
	 */
	int type() const{return Type;}

	/*!
	 *shape() was supposed to be used to get the intersection point with the line that
	 *was connecting this Item, but isnt really used since I couldnt move the beginning
	 *point of the line to the porder of the ellipse, so I had to paint the background 
	 *with white. Setting the Z value of the line lower than the z value of this item
	 */
	QPainterPath shape() const;
	/*!
	 *innerRect() is used to return the inner rectangle in the ellipse.
	 */
	QRectF innerRect();
private:
	//! Enum type value 4
	enum { Type = 4 };
protected:
	/*! \brief called whenever this item is clicked, inherits from MyCentralGraphicsItem
	 *  \brief @param event used to get the position of the cursor when this function is called
	 */

	void mousePressEvent(QGraphicsSceneMouseEvent * event);

	/*!
	 *The Hover event has to be used since, instead of the boundingrect corners of the
	 *ellipse, we will use the inner rect corners to resize de ellipse.
	 *So that when the user hovers over the inner conners the current cursor changes
	 *the shape indicating that he can press and resize the ellipse
	 */
	void hoverMoveEvent(QGraphicsSceneHoverEvent * event);
};
#endif	