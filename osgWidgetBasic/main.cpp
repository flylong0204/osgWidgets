#include <osg/ArgumentParser>
#include <osgViewer/Viewer>
#include <osgViewer/CompositeViewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/TrackballManipulator>
#include <osgDB/ReadFile>

#include <QApplication>
#include <QString>
#include <QTimer>
#include <QKeyEvent>
#include <QGLWidget>
#include <QMainWindow>
#include <QMdiSubWindow>
#include <QMdiArea>
using Qt::WindowFlags;
#include <iostream>

class AdapterWidget : public QGLWidget
{
    public:
        AdapterWidget( QWidget * parent = 0, const char * name = 0, const QGLWidget * shareWidget = 0, WindowFlags f = 0 );
        virtual ~AdapterWidget(){}

        osgViewer::GraphicsWindow* getGraphicsWindow() { return _gw.get(); }
        const osgViewer::GraphicsWindow* getGraphicsWindow() const { return _gw.get(); }
    protected:
        void init();
        virtual void resizeGL( int width, int height );
        virtual void keyPressEvent( QKeyEvent* event );
        virtual void keyReleaseEvent( QKeyEvent* event );
        virtual void mousePressEvent( QMouseEvent* event );
        virtual void mouseReleaseEvent( QMouseEvent* event );
        virtual void mouseMoveEvent( QMouseEvent* event );
        osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> _gw;
};

AdapterWidget::AdapterWidget( QWidget * parent, const char * name, const QGLWidget * shareWidget, WindowFlags f):
    QGLWidget(parent, shareWidget, f)
{
    _gw = new osgViewer::GraphicsWindowEmbedded(0,0,width(),height());
    setFocusPolicy(Qt::ClickFocus);
}
void AdapterWidget::resizeGL( int width, int height )
{
    _gw->getEventQueue()->windowResize(0, 0, width, height );
    _gw->resized(0,0,width,height);
}
void AdapterWidget::keyPressEvent( QKeyEvent* event )
{
    _gw->getEventQueue()->keyPress( (osgGA::GUIEventAdapter::KeySymbol) *(event->text().toLatin1().data() ) );
}
void AdapterWidget::keyReleaseEvent( QKeyEvent* event )
{
    _gw->getEventQueue()->keyRelease( (osgGA::GUIEventAdapter::KeySymbol) *(event->text().toLatin1().data() ) );
}
void AdapterWidget::mousePressEvent( QMouseEvent* event )
{
    int button = 0;
    switch(event->button())
    {
        case(Qt::LeftButton): button = 1; break;
        case(Qt::MidButton): button = 2; break;
        case(Qt::RightButton): button = 3; break;
        case(Qt::NoButton): button = 0; break;
        default: button = 0; break;
    }
    _gw->getEventQueue()->mouseButtonPress(event->x(), event->y(), button);
}
void AdapterWidget::mouseReleaseEvent( QMouseEvent* event )
{
    int button = 0;
    switch(event->button())
    {
        case(Qt::LeftButton): button = 1; break;
        case(Qt::MidButton): button = 2; break;
        case(Qt::RightButton): button = 3; break;
        case(Qt::NoButton): button = 0; break;
        default: button = 0; break;
    }
    _gw->getEventQueue()->mouseButtonRelease(event->x(), event->y(), button);
}
void AdapterWidget::mouseMoveEvent( QMouseEvent* event )
{
    _gw->getEventQueue()->mouseMotion(event->x(), event->y());
}
/*
 *建议学习一下《最长的一帧》
 *实际上，上面的那个窗口仅仅实现了一帧里面的viewerInit。其他的任何事情都没做。
 *于是乎需要做realize,OSG一帧大概需要五个大动作。
 *而realize实际上只是属于第一个动作里面收尾的一个动作（也就是初始化视景器）。
*/






class ViewerQT : public osgViewer::Viewer, public AdapterWidget
{
    public:
        ViewerQT(QWidget * parent = 0, const char * name = 0, const QGLWidget * shareWidget = 0, WindowFlags f = 0):
            AdapterWidget( parent, name, shareWidget, f )
        {
            getCamera()->setViewport(new osg::Viewport(0,0,width(),height()));
            getCamera()->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(width())/static_cast<double>(height()), 1.0f, 10000.0f);
            getCamera()->setGraphicsContext(getGraphicsWindow());
            setThreadingModel(osgViewer::Viewer::SingleThreaded);
            connect(&_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
            _timer.start(10);
        }
        virtual void paintGL()
        {
            frame();
        }

    protected:
        QTimer _timer;
};

/*
 * 既然场景已经初始化完毕了，这样简单的一帧就算是完成了。
 * 实际上一帧中的五个大动作中，后面四个都采用的默认设置
 * OSG一帧五个大动作中，第一帧实际上是准备整个场景，其中包含了第一次运行应用程序对OSG环境的初始化
 * 而恰好，我们在做OSG嵌入其他GUI时做的就是这个初始化工作，因为默认的初始化工作满足不了我们的需求，所以我们需要自己去写。
*/






int main( int argc, char *argv[])
{
    QApplication a( argc, argv );
    osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile("../data/model/avatar.osg");
    std::cout<<"Using ViewetQT MDI version"<<std::endl;
    ViewerQT* viewerWindow = new ViewerQT;
    viewerWindow->addEventHandler(new osgViewer::HelpHandler);
    viewerWindow->setCameraManipulator(new osgGA::TrackballManipulator);
    viewerWindow->setSceneData(loadedModel.get());
    QMainWindow* mw = new QMainWindow();
    QMdiArea* mdiArea = new QMdiArea(mw);
    mw->setCentralWidget(mdiArea);
    QMdiSubWindow *subWindow = mdiArea->addSubWindow(viewerWindow);
    subWindow->showMaximized();
    subWindow->setWindowTitle("New Window");
    mw->show();
    a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
    return a.exec();
}

/*
 * 这里需要注意的是Qt是一个非常懒的家伙~你必须告诉它去刷新，它才肯动一下。
 * 所以那个设置QTimer的地方在所有需要有定时刷新机制的程序中必须用到。
*/


//#include <QtCore/QtCore>
//#include <QtGui/QtGui>
//#include <QApplication>
//#include <osgDB/ReadFile>
//#include <osgGA/TrackballManipulator>
//#include <osgViewer/ViewerEventHandlers>
//#include <osgViewer/Viewer>
//#include <osgQt/GraphicsWindowQt>
//#include <QVBoxLayout>
////#include "CommonFunctions"

//osg::Camera* createCamera( int x, int y, int w, int h )
//{
//    osg::DisplaySettings* ds = osg::DisplaySettings::instance().get();
//    osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
//    traits->windowDecoration = false;
//    traits->x = x;
//    traits->y = y;
//    traits->width = w;
//    traits->height = h;
//    traits->doubleBuffer = true;

//    osg::ref_ptr<osg::Camera> camera = new osg::Camera;
//    camera->setGraphicsContext( new osgQt::GraphicsWindowQt(traits.get()) );
//    camera->setClearColor( osg::Vec4(0.2, 0.2, 0.6, 1.0) );
//    camera->setViewport( new osg::Viewport(0, 0, traits->width, traits->height) );
//    camera->setProjectionMatrixAsPerspective(
//        30.0f, static_cast<double>(traits->width)/static_cast<double>(traits->height), 1.0f, 10000.0f );
//    return camera.release();
//}

//class RenderThread : public QThread
//{
//public:
//    RenderThread() : QThread(), viewerPtr(0) {}

//    virtual ~RenderThread()
//    { if (viewerPtr) viewerPtr->setDone(true); wait(); }

//    osgViewer::Viewer* viewerPtr;

//protected:
//    virtual void run()
//    { if (viewerPtr) viewerPtr->run(); }
//};

//class ViewerWidget : public QWidget
//{
//public:
//    ViewerWidget( osg::Camera* camera, osg::Node* scene )
//    :   QWidget()
//    {
//        _viewer.setCamera( camera );
//        _viewer.setSceneData( scene );
//        _viewer.addEventHandler( new osgViewer::StatsHandler );
//        _viewer.setCameraManipulator( new osgGA::TrackballManipulator );
//        _viewer.setThreadingModel( osgViewer::Viewer::SingleThreaded );

//        osgQt::GraphicsWindowQt* gw = dynamic_cast<osgQt::GraphicsWindowQt*>( camera->getGraphicsContext() );
//        if ( gw )
//        {
//            QVBoxLayout* layout = new QVBoxLayout;
//            layout->addWidget( gw->getGLWidget() );
//            setLayout( layout );
//        }

//        _thread.viewerPtr = &_viewer;
//        _thread.start();
//    }

//protected:
//    osgViewer::Viewer _viewer;
//    RenderThread _thread;
//};

//int main( int argc, char** argv )
//{
//    QApplication app( argc, argv );
//    osg::Camera* camera = createCamera( 50, 50, 640, 480 );
//    osg::Node* scene = osgDB::readNodeFile("../data/model/avatar.osg");

//    ViewerWidget* widget = new ViewerWidget(camera, scene);
//    widget->setGeometry( 100, 100, 800, 600 );
//    widget->show();
//    return app.exec();
//}
