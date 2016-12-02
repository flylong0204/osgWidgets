#ifndef CONSOLE_H
#define CONSOLE_H

#include <QOpenGLWidget>
#include <unordered_map>
#include <QInputEvent>
#include <osgViewer/GraphicsWindow>
#include <osgGA/GUIEventAdapter>

class AdapterWidget : public QOpenGLWidget
{
public:
    AdapterWidget(QWidget *parent = 0, Qt::WindowFlags f = 0);
    ~AdapterWidget(){}

protected:
    virtual void resizeGL(int w, int h) override;
    virtual void keyPressEvent(QKeyEvent* event) override;
    virtual void keyReleaseEvent(QKeyEvent* event) override;
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
    virtual void wheelEvent(QWheelEvent* event) override;

private:
    void _SetKeyboardModifiers(QInputEvent* event);

protected:
    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> _graphicsWindowembedded;

private:
    static std::unordered_map<int, int> _keyMap;
    qreal _devicePixelRatio_;
};

#include <QEvent>
#include <osgViewer/Viewer>

class ShadowViewBasic : public AdapterWidget, public osgViewer::Viewer
{
    Q_OBJECT

public:
    ShadowViewBasic(QWidget *parent);
    ~ShadowViewBasic(){}

protected:
    void initializeGL() override;
    void paintGL() override;
    bool event(QEvent* event) override;
};

#include <QMainWindow>

class ShadowView : public QMainWindow
{
	Q_OBJECT

public:
    ShadowView(QWidget *parent = 0);
    ~ShadowView(){}
    void setModelPath( const QString &path );
    QString getModelPath();

private:
    ShadowViewBasic* _osgWidget;
    osg::ref_ptr<osg::Node> _pNode;
    QString _modelPath;
};

#endif // CONSOLE_H
