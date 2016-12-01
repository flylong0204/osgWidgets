#ifndef CONSOLE_H
#define CONSOLE_H

#include <QtWidgets/QMainWindow>
#include "ui_console.h"

class SandWidget;

class Console : public QMainWindow
{
	Q_OBJECT

public:
	Console(QWidget *parent = 0);
	~Console();

private:
	void _Init();
	void _TestCow();

private:
	Ui::consoleClass ui_;
	SandWidget* osg_widget_;
};

#endif // CONSOLE_H
