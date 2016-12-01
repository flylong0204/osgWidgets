#ifndef EVENTADAPTER_H
#define EVENTADAPTER_H

/*!
 *	@brief	mapping the key/mouse event of OpenSceneGraph to Qt.
 *	@author	pezy
 *	@date	2016-08-05
 *	@see
 */

#include <QOpenGLWidget>
#include <unordered_map>
#include <QInputEvent>
#include <osgViewer/GraphicsWindow>
#include <osgGA/GUIEventAdapter>

class EventAdapterWidget : public QOpenGLWidget
{
public:
	EventAdapterWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
	~EventAdapterWidget();

protected:
	void resizeGL(int w, int h) override;
	void keyPressEvent(QKeyEvent* event) override;
	void keyReleaseEvent(QKeyEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseDoubleClickEvent(QMouseEvent *event) override;
	void wheelEvent(QWheelEvent* event) override;

private:
	void _SetKeyboardModifiers(QInputEvent* event);

protected:
	osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> graphics_windowembedded;

private:
	static std::unordered_map<int, int> key_map_;
	qreal device_pixel_ratio_;
};

#endif // EVENTADAPTER_H
