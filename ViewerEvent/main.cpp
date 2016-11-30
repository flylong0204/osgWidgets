#include "osgDB/ReadFile"
#include "osgViewer/Viewer"
#include "osg/ref_ptr"
#include "osgViewer/ViewerEventHandlers"
#include "osgGa/GUIEventAdapter"

int main()
{
    osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
    osg::ref_ptr<osg::Node> node = new osg::Node;

    node = osgDB::readNodeFile("../data/model/avatar.osg");

    //添加帮助事件
    viewer->addEventHandler(new osgViewer::HelpHandler);

    viewer->setSceneData(node);
    return viewer->run();
}
