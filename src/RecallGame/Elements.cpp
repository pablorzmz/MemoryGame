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
   for(int index = 0; index < svgNames.size();++index)
   {
        temp = new Object(svgNames[index],this->currenTop);
        temp->setElementId(svgNames[index]);
        temp->setSharedRenderer(svgRenderer);
        temp->setZValue(-1);
        temp->setStartPosition(xReference,yReference);
        scene->addItem(temp);
        svgElements.append(temp);
       //std::cout<<index<<": Element loaded("<<nombresSVG[index].toStdString()<<")"<<std::endl;
   }
}


void Elements::shuffleElements()
{
    //tomado de cplusplus;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(this->svgElements.begin(),this->svgElements.end(),std::default_random_engine(seed));
}

QPropertyAnimation* Elements::getObjectAnimation(const int index)
{
    return this->svgElements[index]->m_animation;
}


void Elements::setEnableLauchedObject(const int index)
{
    for(int count = 0; count < index;++count)
    {
        this->svgElements[count]->setEnabled(true);
    }
}
Elements::~Elements()
{
    delete this->currenTop;
}

void Elements::addElements()
{
    svgNames.append("horse");
    svgNames.append("bus");
    svgNames.append("monster1");
    svgNames.append("monster2");
    svgNames.append("monster3");
    svgNames.append("eleph");
    svgNames.append("apple");
    svgNames.append("bunny");
    svgNames.append("cat");
    svgNames.append("dog");
    svgNames.append("monster5");
    svgNames.append("sneaker");
    svgNames.append("monster4");
    svgNames.append("girl");
    svgNames.append("house");

}
