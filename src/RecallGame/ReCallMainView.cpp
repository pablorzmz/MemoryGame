#include "ReCallMainView.h"

ReCallMainView::ReCallMainView(QGraphicsScene *scene)
    :QGraphicsView(scene)
    ,m_tube(Q_NULLPTR)
    ,m_backGround(Q_NULLPTR)
    ,m_svgRenderer(Q_NULLPTR)
    ,m_playerScore(Q_NULLPTR)
    ,scoreLegend("Player score: ")
{

}

void ReCallMainView::initComponents(QGraphicsScene* m_scene)
{   
    //Configuración de la etiqueta de score.
    this->m_playerScore = new QGraphicsTextItem(this->scoreLegend);
    this->m_playerScore->setDefaultTextColor(Qt::black);
    this->m_playerScore->setFont(QFont("", 2));
    m_scene->addItem(this->m_playerScore);
    this->m_playerScore->setPos(QPoint(0,0));



    //Configuración inicial del fondo
    this->paintBackGround(m_scene);
    //this->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    this->setSceneRect( m_backGround->sceneBoundingRect());


    //Se desactivan los scrollbars
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_svgRenderer = new QSvgRenderer(QString("::/../Assets/pics.svg"), this);

    //Configuración del tubo
    m_tube = new PropObject("tube");
    m_tube->setSharedRenderer(m_svgRenderer);
    m_scene->addItem(m_tube);
    m_tube->setStartPosition();
    m_tube->setZValue(1);
    m_tube->addSvgName("tube");
    m_tube->addSvgName("tube1");
    m_tube->addSvgName("tube2");
    m_tube->addSvgName("tube3");
    m_tube->addSvgName("tube4");

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
    //ya son de la escena
    //delete this->m_backGround;
    //delete this->m_tube;
    delete this->m_svgRenderer;
    delete this->m_playerScore;
}

#include <QFont>
void ReCallMainView::updateScore(int& newScoreText)
{
    this->m_playerScore->setPlainText( QString("%1: %2").arg(this->scoreLegend).arg(newScoreText));
}
