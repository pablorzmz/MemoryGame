#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "Object.h"
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QSvgRenderer>
#include <QVector>
#include <QString>
#include <algorithm>
#include <random>
#include <chrono>

class Object;
class Elements
{

private:
    QVector<QString> nombresSVG;
public:
    QVector<Object*> elementosSGV;

public:
    Elements();
    void addElements();
    void loadElements(QSvgRenderer* svgRenderer, QGraphicsScene *scene, qreal xReference, qreal yReference);
    void startInitialAnimation();
    void shuffleObjects();
    QPropertyAnimation *getObjectAnimation(const int index);
};

#endif // ELEMENTS_H
