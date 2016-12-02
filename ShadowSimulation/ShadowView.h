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

private:
    ShadowViewBasic* _osgWidget;
};

#endif // CONSOLE_H
