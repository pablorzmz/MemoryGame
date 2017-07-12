#include "Elements.h"

Elements::Elements()
{
    this->currenTop = new QString("No top yet");
}

//#include <iostream>
void Elements::loadElements(QSvgRenderer* svgRenderer, QGraphicsScene* scene,qreal xReference,qreal yReference)
{
    Object* temp;
   //se cargar los elementos en el arreglo.
   for(int index = 0; index < nombresSVG.size();++index)
   {
        temp = new Object(nombresSVG[index],this->currenTop);
        temp->setElementId(nombresSVG[index]);
        temp->setSharedRenderer(svgRenderer);
        temp->setZValue(-1);
        temp->setStartPosition(xReference,yReference);
        scene->addItem(temp);
        elementosSGV.append(temp);
       //std::cout<<index<<": Element loaded("<<nombresSVG[index].toStdString()<<")"<<std::endl;
   }
}


void Elements::shuffleObjects()
{
    //tomado de cplusplus;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(this->elementosSGV.begin(),this->elementosSGV.end(),std::default_random_engine(seed));
}

QPropertyAnimation* Elements::getObjectAnimation(const int index)
{
    return this->elementosSGV[index]->m_animation;
}


void Elements::setEnableLauchedObject(int index)
{
    for(int count = 0; count < index;++count)
    {
        this->elementosSGV[count]->setEnabled(true);
    }
}
Elements::~Elements()
{
    delete this->currenTop;
}

void Elements::addElements()
{
    nombresSVG.append("horse");
    nombresSVG.append("bus");
    nombresSVG.append("monster1");
    nombresSVG.append("monster2");
    nombresSVG.append("monster3");
    nombresSVG.append("eleph");
    nombresSVG.append("apple");
    nombresSVG.append("bunny");
    nombresSVG.append("cat");
    nombresSVG.append("dog");
    nombresSVG.append("monster5");
    nombresSVG.append("sneaker");
    nombresSVG.append("monster4");
    nombresSVG.append("girl");
    nombresSVG.append("house");

}
