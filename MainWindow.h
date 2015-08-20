 /*! @file MainWindow.h */
 /*! \brief This is the main window. */
 /*!
 *This is the windows that will be showing all the time.
 *contains the central widget, dock widget, actions, etc..
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "MyOrganizationDockWidget.h"
#include "MyDropGraphicsScene.h"
#include "MyGraphicsView.h"
#include <QtGui>
#include <QtCore>
class MainWindow : public QMainWindow{
Q_OBJECT
public:
	MainWindow(QWidget* parent = 0);
	//!Checks weather the painter Cursor is activated
	/*!
	 * Returns true if the color from the colorDialog was accepted,
	 * otherwise returns false
	 */
	bool painterCursorActivated(){return painterCursorActivated_;}
	//!Returns the painterCursor
	QCursor getPainterCursor(){return painterCursor;}
private slots:
	//! Emmited when the toggled(bool) signal from painterAction is triggered 
	/*!
	 * @param toggled receives the bool variable from toggled(bool)
	 */
	void painterToggled(bool toggled);

	//! Emmited when the reject() signal from colorDialog is triggered
	/*!
	 * For now it only changes the cursor icon
	*/
	void rejectColor();
	/*! \brief Emmited when the colorSelected() signal from colorDialog is triggered.
	 *
	 * @param color receives the color from the colorDialog.
	 */
	void acceptColor(const QColor & color);

private:
	//! Called in the constructor
	/*
	 *Initialize the actions, so far there is onlt painterAction, but
	 *save, open, new, etc. actions can be created in the future.
	 *
	 *It also initializes the colorDialog
	 */
	void createActions();
	//! Called in the constructor
	/*
	 * Initializes toolBar and adds it to the MainWindow
	 */
	void createToolBar();
	//! Called in the constructor
	/*
	 *Initializes organizationDockWidget and adds it to the MainWindow
	 */
	void createDockWidget();
	//! Called in the constructor
	/*
	 *Initializes organizationDockWidget and adds it to the MainWindow
	 */
	void createCentralWidget();
	//! Called in the constructor
	/*
	 *Only initialized the painterCursor
	 */
	void createPainterCursor();
	MyOrganizationDockWidget* organizationDockWidget;
	MyDropGraphicsScene* centralScene;
	MyGraphicsView* centralView;
	QToolBar* toolBar;
	//! Color Dialog
	/*!
	 * colorDialog is initialized in the createActions()
	 * It is executed when the painterAction is toggled to true;
	 */
	QColorDialog* colorDialog; 
	QCursor painterCursor;
	//! Used to verify if the painter cursor is activated
	/*!
	 * True if its activated, false otherwise.
	 */
	bool painterCursorActivated_; 
	/*! \brief When executed, prompts the color Dialog.
	*
	*Initialized in createActions()
	*/
	QAction* painterAction;
};

#endif