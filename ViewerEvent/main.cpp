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

    //添加帮助事件
    viewer->addEventHandler(new osgViewer::HelpHandler);
    viewer->addEventHandler(new PrintName);

    viewer->setSceneData(node);
    return viewer->run();
}
