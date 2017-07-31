#include "PropItem.h"

PropItem::PropItem()
    :m_controller(Q_NULLPTR)
    ,staticAnimationTimer(Q_NULLPTR)
    ,currentSVG(1)
    ,lauchControl(true)
{
    //this->setElementId(name);
    staticAnimationTimer = new QTimer();
    //TUBE//QTimer::connect(staticAnimationTimer,SIGNAL(timeout()),this,SLOT(nextSvgName()));
}

void PropItem::setUpAnimation(const QStringList parameters)
{
    this->staticAnimationTimer->setInterval(parameters[0].toDouble());
}

#include <iostream>
PropItem::~PropItem()
{
    //std::cout<<"Prop se elimina :"<<this->elementId().toStdString()<<std::endl;
    delete this->staticAnimationTimer;
}

/*tube
void PropItem::setStartPosition(const qreal x, const qreal y)
{
    qreal xC=0;
    qreal yC=0;
    if(x==0&&y==0)
    {
        xC = ( scene()->width()- boundingRect().width()) * 0.5;
        yC = ( scene()->height()- boundingRect().height());
    }else
    {
        xC = ( scene()->width()- boundingRect().width()) * 0.5;
        yC = y;
    }

    setPos(xC,yC);
}
*/

/*tube
void PropItem::nextSvgName()
{
    ++currentSVG;
    currentSVG = (currentSVG) % (svgs.size()-1);
    this->setElementId( svgs[currentSVG]);
    update();
}
*/

/* tube
void PropItem::stopStaticAnimations()
{
    if (this->staticAnimationTimer)
        this->staticAnimationTimer->stop();

    this->setElementId(this->svgs[0]);
}
*/

void PropItem::setControllerEvent(ReCallController *controller)
{
    this->m_controller=controller;
}
