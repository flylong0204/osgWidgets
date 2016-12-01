#include "console.h"
#include "sandwidget.h"

#include <osgGA/TrackballManipulator>
#include <osgGA/StateSetManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgDB/ReadFile>
#include <osg/MatrixTransform>

Console::Console(QWidget *parent)
	: QMainWindow(parent)
{
	ui_.setupUi(this);
	_Init();
	_TestCow();
}

Console::~Console()
{

}

void Console::_Init()
{
	osg_widget_ = new SandWidget(this);
	osg_widget_->setCameraManipulator(new osgGA::TrackballManipulator);
	osg_widget_->addEventHandler(new osgGA::StateSetManipulator(osg_widget_->getCamera()->getOrCreateStateSet()));
	osg_widget_->addEventHandler(new osgViewer::StatsHandler);

	setCentralWidget(osg_widget_);
	setMinimumSize(800, 600);
	setWindowTitle("sanD world");
}

void Console::_TestCow()
{
    osg::Node* pNode = osgDB::readNodeFile("../data/model/text.DAE");
	osg_widget_->setSceneData(pNode);
}
