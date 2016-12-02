#include "ShadowView.h"

ShadowViewBasic::ShadowViewBasic(QWidget *parent)
    : AdapterWidget(parent)
{

}

void ShadowViewBasic::initializeGL()
{
    osg::GraphicsContext::Traits *traits = new osg::GraphicsContext::Traits;
    traits->windowDecoration = true;
    traits->x = 0;
    traits->y = 0;
    traits->width = 800;
    traits->height = 600;
    traits->doubleBuffer = true;

    _graphicsWindowembedded = new osgViewer::GraphicsWindowEmbedded(traits);

    osg::Camera* pCamera = getCamera();
    pCamera->setGraphicsContext(_graphicsWindowembedded);
    pCamera->setClearColor(osg::Vec4(0.176, 0.18, 0.157, 0.9));
    pCamera->setViewport(new osg::Viewport(0, 0, 800, 600));
    pCamera->setClearMask(pCamera->getClearMask() | GL_STENCIL_BUFFER_BIT);
    pCamera->setProjectionMatrixAsPerspective(30.f, 4.0 / 3, 1.f, 10000.f);
}

void ShadowViewBasic::paintGL()
{
    frame();
}

bool ShadowViewBasic::event(QEvent* event)
{
    bool bRet = AdapterWidget::event(event);
    switch (event->type())
    {
        case QEvent::KeyPress:
        case QEvent::KeyRelease:
        case QEvent::MouseButtonDblClick:
        case QEvent::MouseButtonPress:
        case QEvent::MouseButtonRelease:
        case QEvent::MouseMove:
        case QEvent::Wheel:
            this->update();
            break;

        default:
            break;
    }

    return bRet;
}

#include <osgGA/TrackballManipulator>
#include <osgGA/StateSetManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgDB/ReadFile>
#include <osg/MatrixTransform>

ShadowView::ShadowView(QWidget *parent)
    : QMainWindow(parent),_modelPath("../data/model/text.DAE")
{
    _osgWidget = new ShadowViewBasic(this);
    _osgWidget->setCameraManipulator(new osgGA::TrackballManipulator);
    _osgWidget->addEventHandler(new osgGA::StateSetManipulator(_osgWidget->getCamera()->getOrCreateStateSet()));
    _osgWidget->addEventHandler(new osgViewer::StatsHandler);

    setCentralWidget(_osgWidget);
    //setMinimumSize(200, 200);

    _pNode = osgDB::readNodeFile(_modelPath.toStdString().c_str());
    _osgWidget->setSceneData(_pNode);
}

void ShadowView::setModelPath(const QString &path)
{
    if(_modelPath != path)
    {
        _modelPath = path;
        _pNode = osgDB::readNodeFile(_modelPath.toStdString().c_str());
        _osgWidget->setSceneData(_pNode);
    }
    else
    {
        return;
    }
}

QString ShadowView::getModelPath()
{
    return _modelPath;
}

