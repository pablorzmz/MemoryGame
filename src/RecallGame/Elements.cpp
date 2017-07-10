#include "Elements.h"

Elements::Elements()
{
    addElements();
}

#include <iostream>
void Elements::loadElements(QSvgRenderer* svgRenderer, QGraphicsScene* scene,qreal xReference,qreal yReference)
{
    Object* temp;
    qreal prueba = 1;
   //se cargar los elementos en el arreglo.
   for(int index = 0; index < nombresSVG.size()/2;++index)
   {
        temp = new Object(nombresSVG[index]);
        temp->setElementId(nombresSVG[index]);
        temp->setSharedRenderer(svgRenderer);
        temp->setZValue(-1);
        temp->setStartPosition(xReference,yReference);
        scene->addItem(temp);
        elementosSGV.append(temp);
        prueba+=10;
        std::cout<<index<<": Element loaded("<<nombresSVG[index].toStdString()<<")"<<std::endl;
   }
}


void Elements::shuffleObjects()
{
    //tomado de cplusplus
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->elementosSGV.begin(),this->elementosSGV.end(),std::default_random_engine(seed));
}

QPropertyAnimation* Elements::getObjectAnimation(const int index)
{
    return this->elementosSGV[index]->m_animation;
}


void Elements::startInitialAnimation()
{
    qreal x = 12;
    qreal y = 20;    
    this->elementosSGV[0]->m_animation->start();
}


void Elements::addElements()
{
    nombresSVG.append("apple");
    nombresSVG.append("bunny");
    nombresSVG.append("cat");
    nombresSVG.append("dog");
    nombresSVG.append("watermalon");
    nombresSVG.append("vespa");
    nombresSVG.append("girl");
    nombresSVG.append("house");
    nombresSVG.append("horse");
}
