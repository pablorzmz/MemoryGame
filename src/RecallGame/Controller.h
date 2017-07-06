#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Elements.h"

#include <QSvgRenderer>
#include <QtMath>
class Controller
{
public:

    private:
    Elements elements;

    public:
    Controller();
    void loadPics(QSvgRenderer* svgRenderer, QGraphicsScene* scene,qreal xReference,qreal yReference);
};

#endif // CONTROLLER_H
