#include "ReCallMainView.h"

ReCallMainView::ReCallMainView(QGraphicsScene *scene)
    :QGraphicsView(scene)
{

}

void ReCallMainView::initComponents(QGraphicsScene* m_scene)
{
   //Configuración del botón

    m_starButton= new QPushButton(this);
    m_starButton->setText(tr("PLAY"));
    m_starButton->setGeometry(QRect(QPoint(4, 4),QSize(75, 50)));
    QPalette pal = m_starButton->palette();
    pal.setColor(QPalette::Button, QColor(Qt::yellow));
    m_starButton->setAutoFillBackground(true);
    m_starButton->setPalette(pal);
    m_starButton->update();

    //Configuración inicial del fondo
    this->paintBackGround(m_scene);
    this->setBackgroundBrush(QBrush(Qt::white, Qt::SolidPattern));
    this->setSceneRect( m_backGround->sceneBoundingRect());


    //Se desactivan los scrollbars
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_svgRenderer = new QSvgRenderer(QString("::/../Assets/pics.svg"), this);

    //Configuración del tubo
    m_tube = new Object("tube");
    m_tube->setElementId("tube");
    m_tube->setSharedRenderer(m_svgRenderer);
    m_scene->addItem(m_tube);
    m_tube->setStartPosition();
    m_tube->setZValue(1);
}

void ReCallMainView::paintBackGround(QGraphicsScene* m_scene){
 QSvgRenderer* svgRenderer = new QSvgRenderer(QString("::/../Assets/backgrounds.svg"), this);
 m_backGround = new Object("background");
 m_backGround->setSharedRenderer(svgRenderer);
 m_scene->addItem(m_backGround);
 this->fitInView(m_backGround,Qt::KeepAspectRatioByExpanding);
 m_backGround->setZValue(-1);
 m_backGround->setOpacity(0.5);
}
