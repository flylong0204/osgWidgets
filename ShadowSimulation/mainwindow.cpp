#include "MainWindow.h"
#include "ShadowView.h"
#include "ui_MainWindow.h"

#include <osgGA/TrackballManipulator>
#include <osgGA/StateSetManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgDB/ReadFile>
#include <osg/MatrixTransform>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui->setupUi(this);
    _Init();
    _TestCow();
}

MainWindow::~MainWindow()
{

}

void MainWindow::_Init()
{
    osg_widget_ = new ShadowViewBasics(this);
    osg_widget_->setCameraManipulator(new osgGA::TrackballManipulator);
    osg_widget_->addEventHandler(new osgGA::StateSetManipulator(osg_widget_->getCamera()->getOrCreateStateSet()));
    osg_widget_->addEventHandler(new osgViewer::StatsHandler);

    setCentralWidget(osg_widget_);
    setMinimumSize(800, 600);
    setWindowTitle("sanD world");
}

void MainWindow::_TestCow()
{
    osg::Node* pNode = osgDB::readNodeFile("../data/model/text.DAE");
    osg_widget_->setSceneData(pNode);
}

