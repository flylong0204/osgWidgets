#ifndef EVENTADAPTER_H
#define EVENTADAPTER_H

#include <QOpenGLWidget>
#include <unordered_map>
#include <QInputEvent>
#include <osgViewer/GraphicsWindow>
#include <osgGA/GUIEventAdapter>

class AdapterWidget : public QOpenGLWidget
{
public:
    AdapterWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~AdapterWidget();

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
    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> _graphicsWindowembedded;

private:
    static std::unordered_map<int, int> _keyMap;
    qreal _devicePixelRatio_;
};

#endif // EVENTADAPTER_H
