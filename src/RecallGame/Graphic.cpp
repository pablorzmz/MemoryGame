#include "Graphic.h"

Graphic::Graphic(QString nombre)
    :nombre(nombre)
{
this->setElementId(nombre);
}

Graphic::~Graphic()
{
}

void Graphic::setStartPosition(const qreal x, const qreal y)
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



#include <iostream>
void Graphic::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    std::cout<<"TOUCHED("<<this->nombre.toStdString()<<")"<<std::endl;
    if(!this->nombre.startsWith("background"))
        this->setVisible(false);
}
