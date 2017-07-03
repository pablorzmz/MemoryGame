#include "MainWindow.h"


MainWindow::MainWindow(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
    , M_scene(nullptr)
    , M_view(nullptr)
{
}


int MainWindow::runGame()
{
    M_scene = new QGraphicsScene();
    M_view = new QGraphicsView(M_scene);
    M_view->setBackgroundBrush(QBrush(Qt::green, Qt::SolidPattern));
    //TAMAÑO DE LA ESCENA SE REDIMENCIONA AL TAMAÑO DE LA VISTA PARA NO TENER BARRAS DE SCROLL
    M_scene->setSceneRect( M_view->rect() );
    // Disable scrollbars because they are not needed
    M_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    M_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    M_view->show();
    return exec();
}

MainWindow::~MainWindow()
{
    delete M_scene;
    delete M_view;
}
