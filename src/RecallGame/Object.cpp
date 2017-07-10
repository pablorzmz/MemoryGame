#include "Object.h"

Object::Object(QString nombre)
    :QGraphicsSvgItem()
    ,m_animation(nullptr)
    ,pastX(0)
    ,pastY(0)
{
this->setElementId(nombre);
m_animation = new QPropertyAnimation(this,"pos");
}

void Object::setStartPosition(const qreal x, const qreal y)
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


void Object::setAnimation(int duration,const qreal finalX, const qreal finalY, const qreal startX, const qreal startY)
{
    m_animation->setDuration(duration);
    pastX= this->x();
    pastY=this->y();
    if(startX==-1&&startY==-1)
    {
        m_animation->setStartValue(QPointF(this->x(),this->y()));
    }else
    {
        m_animation->setStartValue(QPointF(startX,startY));
    }
    m_animation->setEndValue(QPointF(finalX,finalY));
}

#include <iostream>
void Object::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    this->setAnimation(500,pastX,pastY,-1,-1);
    this->m_animation->start();
}

 Object::~Object()
 {

 }

