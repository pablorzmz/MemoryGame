#include "PropObject.h"

PropObject::PropObject(QString name,ReCallController* controller)
    :QGraphicsSvgItem()
    ,m_controller(controller)
    ,staticAnimationTimer(Q_NULLPTR)
    ,currentSVG(1)
    ,lauchControl(true)
{
    this->setElementId(name);
    staticAnimationTimer = new QTimer(this);
    QObject::connect(staticAnimationTimer,SIGNAL(timeout()),this,SLOT(nextSvgName()));
}

#include <iostream>
PropObject::~PropObject()
{
 std::cout<<"Prop se elimina :"<<this->elementId().toStdString()<<std::endl;
 delete this->staticAnimationTimer;
}

void PropObject::startStaticAnimations(const int duration)
{
    this->staticAnimationTimer->start(duration);
}

void PropObject::nextSvgName()
{
    ++currentSVG;
    currentSVG = (currentSVG) % (svgs.size()-1);
    this->setElementId( svgs[currentSVG]);
    update();
}

void PropObject::setStartPosition(const qreal x, const qreal y)
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

void PropObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if((this->elementId()=="tube"||
        this->elementId()=="tube1"||
        this->elementId()=="tube2"||
        this->elementId()=="tube3"||
        this->elementId()=="tube4")
            &&lauchControl)
       {
        staticAnimationTimer->start(100);
        this->m_controller->startGame();
        lauchControl=false;
        this->setEnabled(false);
        }

    if(this->elementId().compare("reset")==0)
    {
        this->m_controller->resetFromButton();
    }

    if(this->elementId().compare("scores")==0)
    {
        this->m_controller->showScoresTable();
    }

}

void PropObject::setControllerEvent(ReCallController *controller)
{
    this->m_controller=controller;
}

void PropObject::stopStaticAnimations()
{
    if (this->staticAnimationTimer)
        this->staticAnimationTimer->stop();

    this->setElementId(this->svgs[0]);
}
