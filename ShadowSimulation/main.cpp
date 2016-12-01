#include "MainWindow.h"
#include "ShadowView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a( argc, argv );
    osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile("../data/model/avatar.osg");
    ViewerQT* viewerWindow = new ViewerQT;
    viewerWindow->setCameraManipulator(new osgGA::TrackballManipulator);
    viewerWindow->setSceneData(loadedModel.get());
    MainWindow mw;
    QMdiArea* mdiArea = new QMdiArea(&mw);
    mw.setCentralWidget(mdiArea);
    QMdiSubWindow *subWindow = mdiArea->addSubWindow(viewerWindow);
    subWindow->setGeometry(0,0,200,200);
    subWindow->setWindowTitle("New Window");
    subWindow->setWindowFlags(Qt::FramelessWindowHint);
    mw.show();
    a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
    return a.exec();
//    QApplication a( argc, argv );
//    MainWindow w;
//    w.show();
//    return a.exec();
}
