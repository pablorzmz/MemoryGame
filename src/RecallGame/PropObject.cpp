#include "PropObject.h"

PropObject::PropObject(QString nombre,ReCallController* controller)
    :QGraphicsSvgItem()
    ,m_controller(controller)
    ,staticAnimationTimer(Q_NULLPTR)
    ,lauchControl(true)
    ,currentSVG(1)
{
    this->setElementId(nombre);
    staticAnimationTimer = new QTimer(this);
    QObject::connect(staticAnimationTimer,SIGNAL(timeout()),this,SLOT(nextSvgName()));
}


PropObject::~PropObject()
{

}

void PropObject::nextSvgName()
{
    currentSVG = ++currentSVG % 5;
    this->setElementId( svgs[currentSVG]);
    //this->moveBy(5,0);
    update();
}

void PropObject::setStartPosition(const qreal x, const qreal y)
{
    if(x==0&&y==0)
    {
        qreal x = ( scene()->width()- boundingRect().width()) * 0.5;
        qreal y = ( scene()->height()- boundingRect().height());
        setPos(x, y);
    }
    else
    {
        setPos(x,y);
    }
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
}

void PropObject::setControllerEvent(ReCallController *controller)
{
    this->m_controller=controller;
}
