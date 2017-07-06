#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "Graphic.h"
#include <QGraphicsScene>
#include <QVector>
#include <QString>


class Elements
{

private:
    QVector<QString> nombresSVG;
    QVector<Graphic*> elementosSGV;

public:
    Elements();
    void addElements();
    void loadElements(QSvgRenderer* svgRenderer, QGraphicsScene *scene, qreal xReference, qreal yReference);
};

#endif // ELEMENTS_H
