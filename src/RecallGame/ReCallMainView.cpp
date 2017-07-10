#include "ReCallMainView.h"

ReCallMainView::ReCallMainView(QGraphicsScene *scene)
    :QGraphicsView(scene)
    ,m_tube(Q_NULLPTR)
    ,m_backGround(Q_NULLPTR)
    ,m_svgRenderer(Q_NULLPTR)
{

}

void ReCallMainView::initComponents(QGraphicsScene* m_scene)
{   
    //Configuración inicial del fondo
    this->paintBackGround(m_scene);
    this->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    this->setSceneRect( m_backGround->sceneBoundingRect());


    //Se desactivan los scrollbars
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_svgRenderer = new QSvgRenderer(QString("::/../Assets/pics.svg"), this);

    //Configuración del tubo
    m_tube = new PropObject("tube");
    m_tube->setElementId("tube");
    m_tube->setSharedRenderer(m_svgRenderer);
    m_scene->addItem(m_tube);
    m_tube->setStartPosition();
    m_tube->setZValue(1);
}

void ReCallMainView::paintBackGround(QGraphicsScene* m_scene){
 QSvgRenderer* svgRenderer = new QSvgRenderer(QString("::/../Assets/backgrounds.svg"), this);
 m_backGround = new PropObject("background2");
 m_backGround->setSharedRenderer(svgRenderer);
 m_scene->addItem(m_backGround);
 this->fitInView(m_backGround,Qt::KeepAspectRatioByExpanding);
 m_backGround->setZValue(-1);
 m_backGround->setOpacity(0.5);
}

ReCallMainView::~ReCallMainView()
{
    delete this->m_backGround;
    delete this->m_tube;
    delete this->m_svgRenderer;
}
