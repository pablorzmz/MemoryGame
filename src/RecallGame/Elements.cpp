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
        temp->setStartPosition(prueba,30);
        scene->addItem(temp);
        elementosSGV.append(temp);
        prueba+=10;
        std::cout<<index<<": Element loaded("<<nombresSVG[index].toStdString()<<")"<<std::endl;
   }
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
