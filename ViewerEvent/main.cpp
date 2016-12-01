#include "osgDB/ReadFile"
#include "osgViewer/Viewer"
#include "osg/ref_ptr"
#include "osgViewer/ViewerEventHandlers"
#include "osgGA/GUIEventHandler"

class PrintName : public osgGA::GUIEventHandler
{
public:
    virtual void getUsage(osg::ApplicationUsage &usage) const
    {
        usage.addKeyboardMouseBinding("mf", "Great");
    }
};

int main()
{
    osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
    osg::ref_ptr<osg::Node> node = new osg::Node;

    node = osgDB::readNodeFile("../data/model/avatar.osg");

    viewer->setName("事件");

    //添加帮助事件，h
    viewer->addEventHandler(new osgViewer::HelpHandler);
    //添加自定义事件，h
    viewer->addEventHandler(new PrintName);
    //添加帧数事件，s
    viewer->addEventHandler(new osgViewer::StatsHandler);
    //添加全屏事件，f
    viewer->addEventHandler(new osgViewer::WindowSizeHandler);
    //添加截图事件，c
    viewer->addEventHandler(new osgViewer::ScreenCaptureHandler);

    viewer->setSceneData(node);
    return viewer->run();
}
