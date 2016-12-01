#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ShadowView.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ShadowView *shadowview = new ShadowView(this);
    ui->gridLayout->addWidget(shadowview);
}

MainWindow::~MainWindow()
{
    delete ui;
}
