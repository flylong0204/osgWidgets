#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <qDebug>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _shadowview = new ShadowView(this);
    ui->gridLayout->addWidget(_shadowview);
    ui->compute->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                       tr("选择模型"),
                       "./../data/model/",
                       tr("(*.obj *.OBJ *.dxf *.DXF *.osg *.OSG *.dae *.DAE"
                           "*.3ds *.3DS *.3dx *.3DX *.md2 *.MD2 *.p3d *.P3D);"));
    if( filename.isEmpty() )
    {
        return;
    }
    else
    {
        ui->model_name->setText( filename );
        if(_shadowview->getModelPath() != filename)
            _shadowview->setModelPath( filename );
    }
}
