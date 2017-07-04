#include "MainWindow.h"

MainWindow::MainWindow(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
    , M_scene(nullptr)
    , M_view(nullptr)
    ,M_tube(nullptr)
    ,M_backGround(nullptr)
{
}


int MainWindow::runGame()
{
    M_scene = new QGraphicsScene();
    M_view = new QGraphicsView(M_scene);
    paintBackGround();
    M_view->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    M_scene->setSceneRect( M_backGround->sceneBoundingRect());


    // Disable scrollbars because they are not needed
    M_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    M_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QSvgRenderer* svgRenderer = new QSvgRenderer(QString(":/pics.svg"), this);

    //Configuración del tubo
    M_tube = new Graphic();
    M_tube->setElementId("tube");
    M_tube->setSharedRenderer(svgRenderer);
    M_scene->addItem(M_tube);    
    M_tube->setStartPosition();
    M_tube->setZValue(1);


    M_view->show();
    return exec();
}
#include <QPainter>
void MainWindow::paintBackGround(){
 QSvgRenderer* svgRenderer = new QSvgRenderer(QString(":/pics.svg"), this);
 M_backGround = new Graphic();
 M_backGround->setElementId("background");
 M_backGround->setSharedRenderer(svgRenderer);
 M_scene->addItem(M_backGround);
 M_view->fitInView(M_backGround,Qt::KeepAspectRatioByExpanding);
 M_backGround->setZValue(-1);
 M_backGround->setOpacity(0.5);
}


MainWindow::~MainWindow()
{
    delete M_scene;
    delete M_view;    
}
