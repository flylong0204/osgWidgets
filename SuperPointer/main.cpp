#include "osgDB/ReadFile"
#include "osgViewer/Viewer"
#include "osg/ref_ptr"

int main()
{
    osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
    osg::ref_ptr<osg::Node> node = new osg::Node;
    node = osgDB::readNodeFile("../data/model/avatar.osg");
    viewer->setSceneData(node);
    return viewer->run();
}

