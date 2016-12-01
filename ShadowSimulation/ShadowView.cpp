#include "ShadowView.h"

#include <osgGA/TrackballManipulator>
#include <osgGA/StateSetManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgDB/ReadFile>
#include <osg/MatrixTransform>

ShadowView::ShadowView(QWidget *parent)
    : QMainWindow(parent)
{
    _osgWidget = new ShadowViewBasic(this);
    _osgWidget->setCameraManipulator(new osgGA::TrackballManipulator);
    _osgWidget->addEventHandler(new osgGA::StateSetManipulator(_osgWidget->getCamera()->getOrCreateStateSet()));
    _osgWidget->addEventHandler(new osgViewer::StatsHandler);

    setCentralWidget(_osgWidget);
    //setMinimumSize(200, 200);

    osg::Node* pNode = osgDB::readNodeFile("../data/model/text.DAE");
    _osgWidget->setSceneData(pNode);
}
