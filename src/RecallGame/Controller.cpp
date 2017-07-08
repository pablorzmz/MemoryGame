#include "Controller.h"

Controller::Controller()
{
elements.addElements();
}




#include <iostream>
void Controller::loadPics(QSvgRenderer *svgRenderer, QGraphicsScene *scene, qreal xReference, qreal yReference)
{
    this->elements.loadElements(svgRenderer,scene,xReference,yReference);
    std::cout<<"Playing button pressed"<<std::endl;

}


