#ifndef SHADOWVIEW_H
#define SHADOWVIEW_H

#include <QOpenGLWidget>
#include <unordered_map>
#include <QInputEvent>
#include <osgViewer/GraphicsWindow>
#include <osgGA/GUIEventAdapter>
#include <osgViewer/Viewer>

class AdapterWidget : public QOpenGLWidget
{
public:
    AdapterWidget( QWidget *parent = 0, Qt::WindowFlags f = 0 );
    virtual ~AdapterWidget(){}

    osgViewer::GraphicsWindow* getGraphicsWindow() { return _graphicsWindowembedded.get(); }
    const osgViewer::GraphicsWindow* getGraphicsWindow() const { return _graphicsWindowembedded.get(); }
protected:
    void init();
    virtual void resizeGL( int width, int height ) override;
    virtual void keyPressEvent( QKeyEvent* event ) override;
    virtual void keyReleaseEvent( QKeyEvent* event ) override;
    virtual void mousePressEvent( QMouseEvent* event ) override;
    virtual void mouseReleaseEvent( QMouseEvent* event ) override;
    virtual void mouseMoveEvent( QMouseEvent* event ) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
    virtual void wheelEvent(QWheelEvent* event) override;
    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> _graphicsWindowembedded;
private:
    void _SetKeyboardModifiers(QInputEvent* event);
    static std::unordered_map<int, int> _keyMap;
    qreal _devicePixelRatio;
};

class ShadowViewBasics : public AdapterWidget, public osgViewer::Viewer
{
    Q_OBJECT

public:
    ShadowViewBasics(QWidget *parent);
    ~ShadowViewBasics();

protected:
    void initializeGL() override;
    void paintGL() override;
    bool event(QEvent* event) override;
};


#endif // SHADOWVIEW_H
