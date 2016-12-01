#ifndef ShadowViewBasic_H
#define ShadowViewBasic_H

#include "AdapterWidget.h"
#include <osgViewer/Viewer>

class ShadowViewBasic : public AdapterWidget, public osgViewer::Viewer
{
	Q_OBJECT

public:
    ShadowViewBasic(QWidget *parent);
    ~ShadowViewBasic();

protected:
	void initializeGL() override;
	void paintGL() override;
	bool event(QEvent* event) override;
};

#endif // ShadowViewBasic_H
