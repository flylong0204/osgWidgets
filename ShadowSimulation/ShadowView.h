#ifndef CONSOLE_H
#define CONSOLE_H

#include <QMainWindow>
#include <QEvent>
#include "AdapterWidget.h"

#include <osgViewer/Viewer>

class ShadowViewBasic : public AdapterWidget, public osgViewer::Viewer
{
    Q_OBJECT

public:
    ShadowViewBasic(QWidget *parent);
    ~ShadowViewBasic(){}

protected:
    void initializeGL() override;
    void paintGL() override;
    bool event(QEvent* event) override;
};

class ShadowView : public QMainWindow
{
	Q_OBJECT

public:
    ShadowView(QWidget *parent = 0);
    ~ShadowView(){}
    void setModelPath( const QString &path );
    QString getModelPath();

private:
    ShadowViewBasic* _osgWidget;
    osg::ref_ptr<osg::Node> _pNode;
    QString _modelPath;
};

#endif // CONSOLE_H
