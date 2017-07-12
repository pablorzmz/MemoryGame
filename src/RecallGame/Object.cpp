#include "Object.h"

Object::Object(QString nombre, QString* ElementsCurrentTop)
    :QGraphicsSvgItem()
    ,m_animation(Q_NULLPTR)
    ,m_animation2(Q_NULLPTR)
    ,currentTop(ElementsCurrentTop)
    ,pastX(0)
    ,pastY(0)
{
    this->setElementId(nombre);
    m_animation = new QPropertyAnimation(this,"pos");
    m_animation2 = new QPropertyAnimation(this,"pos");
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

void Object::setAnimation(int animationNumber,int duration,const qreal finalX, const qreal finalY, const qreal startX, const qreal startY)
{
    if(animationNumber==1)
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
    }else
    {
        m_animation2->setDuration(duration);

            pastX= this->x();
            pastY=this->y();

        if(startX==-1&&startY==-1)
        {
            m_animation2->setStartValue(QPointF(this->x(),this->y()));
        }else
        {
            m_animation2->setStartValue(QPointF(startX,startY));
        }
        m_animation2->setEndValue(QPointF(finalX,finalY));
    }

    this->setEnabled(false);
}

void Object::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    //std::cout<<"TOUCHED("<<this->elementId().toStdString()<<")"<<std::endl;
    this->setAnimation(2,200,pastX,pastY,this->x(),this->y());
    this->m_animation2->start();
    this->pastX=this->x();
    this->pastY=this->y();
    setMeAsCurrentQueueTop();
}

void Object::setMeAsCurrentQueueTop()
{
    this->currentTop->clear();
    *(currentTop) = this->elementId();
}


 Object::~Object()
 {
    delete this->m_animation;
    delete this->m_animation2;
 }

