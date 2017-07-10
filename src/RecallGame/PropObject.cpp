#include "PropObject.h"

PropObject::PropObject(QString nombre,ReCallController* controller)
    :QGraphicsSvgItem()
    ,m_controller(controller)
    ,lauchControl(true)
{
    this->setElementId(nombre);
}


PropObject::~PropObject()
{

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
    if(this->elementId()=="tube"&&lauchControl)
       {
        this->m_controller->startGame();
        lauchControl=false;
        }
}

void PropObject::setControllerEvent(ReCallController *controller)
{
    this->m_controller=controller;
}
