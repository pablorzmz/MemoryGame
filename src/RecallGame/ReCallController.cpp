#include "MainWindow.h"

MainWindow::MainWindow(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
    , M_scene(nullptr)
    , M_view(nullptr)
    ,M_svgRenderer(nullptr)
    ,M_tube(nullptr)
    ,M_backGround(nullptr)
{
    M_scene = new QGraphicsScene();
    M_view = new QGraphicsView(M_scene);
    initComponents();
    this->setApplicationName("Recall game v1.0");
    this->setStyle(QStyleFactory::create("WindowsVista"));
    M_view->show();
    connect(M_starButton, SIGNAL (released()), this, SLOT (startGame()));

}

void MainWindow::startGame()
{
    M_mainController.loadPics(M_svgRenderer,M_scene,M_tube->x()+3,M_tube->y()+1);
    M_starButton->setText("Playing");
    M_starButton->setEnabled(false);
}


void MainWindow::initComponents()
{
   //Configuración del botón

    M_starButton= new QPushButton(M_view);
    M_starButton->setText(tr("PLAY"));
    M_starButton->setGeometry(QRect(QPoint(4, 4),QSize(75, 50)));
    QPalette pal = M_starButton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::yellow));
    M_starButton->setAutoFillBackground(true);
    M_starButton->setPalette(pal);
    M_starButton->update();

    //Configuración inicial del fondo
    paintBackGround();
    M_view->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    M_scene->setSceneRect( M_backGround->sceneBoundingRect());


    //Se desactivan los scrollbars
    M_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    M_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    M_svgRenderer = new QSvgRenderer(QString(":/pics.svg"), this);

    //Configuración del tubo
    M_tube = new Graphic("tube");
    M_tube->setElementId("tube");
    M_tube->setSharedRenderer(M_svgRenderer);
    M_scene->addItem(M_tube);
    M_tube->setStartPosition();
    M_tube->setZValue(1);
}


int MainWindow::runGame()
{
    return exec();
}


void MainWindow::paintBackGround(){
 QSvgRenderer* svgRenderer = new QSvgRenderer(QString(":/backgrounds.svg"), this);
 M_backGround = new Graphic("background");
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
