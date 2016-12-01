#ifndef CONSOLE_H
#define CONSOLE_H

#include "ShadowViewBasic.h"
#include <QMainWindow>

class ShadowView;

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
