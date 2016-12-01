#ifndef SANDWIDGET_H
#define SANDWIDGET_H

/*!
 *	@brief	the main widget to show 3D scene.
 *	@author	pezy
 *	@date	2016-08-05
 *	@see
 */

#include "eventadapterwidget.h"
#include <osgViewer/Viewer>

class SandWidget : public EventAdapterWidget, public osgViewer::Viewer
{
	Q_OBJECT

public:
	SandWidget(QWidget *parent);
	~SandWidget();

protected:
	void initializeGL() override;
	void paintGL() override;
	bool event(QEvent* event) override;
};

#endif // SANDWIDGET_H
