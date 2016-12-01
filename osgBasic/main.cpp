
#include "osgDB/ReadFile"
#include "osgViewer/Viewer"

int main()
{
    osgViewer::Viewer viewer;
    osg::Node *node = new osg::Node;
    node = osgDB::readNodeFile("../data/model/text.DAE");
    viewer.setSceneData(node);
    return viewer.run();
}
