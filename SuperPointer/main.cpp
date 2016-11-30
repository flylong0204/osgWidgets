#include "osgDB/ReadFile"
#include "osgViewer/Viewer"
#include "osg/ref_ptr"

int main()
{
    /*
     * 这里需要注意，超级指针的对象不需要加*
     * 但是调用该对象的方法的时候要用->符号
     *
     */
    osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
    osg::ref_ptr<osg::Node> node = new osg::Node;
    node = osgDB::readNodeFile("../data/model/avatar.osg");
    viewer->setSceneData(node);
    return viewer->run();
}

