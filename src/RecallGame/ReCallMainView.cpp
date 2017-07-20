#include "ReCallMainView.h"

ReCallMainView::ReCallMainView(QGraphicsScene *scene)
    :QGraphicsView(scene)
    ,m_tube(Q_NULLPTR)
    ,m_backGround(Q_NULLPTR)
    ,m_svgRenderer(Q_NULLPTR)
    ,m_playerScore(Q_NULLPTR)
    ,m_title(Q_NULLPTR)
    ,scoreLegend("Player score: ")
    ,m_score_button(Q_NULLPTR)
    ,m_reset_button(Q_NULLPTR)
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

    //Configuración del titulo
    m_title = new PropObject("title1");
    m_title->setSharedRenderer(m_svgRenderer);
    m_scene->addItem(m_title);
    m_title->setZValue(1);
    m_title->setStartPosition(50,this->m_tube->y()-30);
    m_title->addSvgName("title1");
    m_title->addSvgName("title2");
    m_title->addSvgName("title3");
    m_title->addSvgName("title4");
    m_title->addSvgName("title5");
    m_title->addSvgName("title6");
    m_title->addSvgName("title7");
    m_title->addSvgName("title8");
    m_title->addSvgName("title9");
    m_title->startStaticAnimations(150);


    m_score_button = new PropObject("scores");
    m_score_button->setSharedRenderer(m_svgRenderer);
    m_scene->addItem(m_score_button);
    m_score_button->setZValue(1);
    m_score_button->setPos(50,65);
    //m_score_button->setEnabled(false);

    m_reset_button = new PropObject("reset");
    m_reset_button->setSharedRenderer(m_svgRenderer);
    m_scene->addItem(m_reset_button);
    m_reset_button->setZValue(1);
    m_reset_button->setPos(80,66);

    this->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    this->setMaximumHeight(this->height());
    this->setMaximumWidth(this->width()+200);
    this->setMaximumHeight(this->height());
    this->setMaximumWidth(this->width()+200);
}

void ReCallMainView::paintBackGround(QGraphicsScene* m_scene){
 QSvgRenderer* svgRenderer = new QSvgRenderer(QString("::/../Assets/backgrounds.svg"), this);
 m_backGround = new PropObject("background2");
 m_backGround->setSharedRenderer(svgRenderer);
 m_scene->addItem(m_backGround);
 this->fitInView(m_backGround,Qt::KeepAspectRatioByExpanding);
 m_backGround->setZValue(-1);
}
#include <iostream>
ReCallMainView::~ReCallMainView()
{
    std::cout<<"Vista se destruye"<<std::endl;
    //ya son de la escena
    //delete this->m_backGround;
    //delete this->m_tube;
    //delete this->m_svgRenderer;
    //delete this->m_playerScore;
}

#include <QFont>
void ReCallMainView::updateScore(const int &newScoreText)
{
    this->m_playerScore->setPlainText( QString("%1: %2").arg(this->scoreLegend).arg(newScoreText));
}
