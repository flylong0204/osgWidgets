#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osg/ref_ptr>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/GUIEventHandler>
#include <osg/Timer>
#include <iostream>

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

    //得到一个tick值是多少(意思大概是能计算的最小时间)
    osg::Timer *timer = new osg::Timer;
    std::cout << timer->getSecondsPerTick() << std::endl;

    //计算模型加载花费时间
    osg::Timer_t start_time = timer->tick();
    node = osgDB::readNodeFile("../data/model/avatar.osg");
    osg::Timer_t stop_time = timer->tick();
    std::cout << "读取模型时间:" << timer->delta_s(start_time,stop_time) << std::endl;

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
