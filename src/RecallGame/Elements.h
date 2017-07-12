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
#include <QApplication>

class Object;
class Elements
{

private:
    QVector<QString> nombresSVG;
public:
    QVector<Object*> elementosSGV;
    QString* currenTop;

public:
    Elements();
    ~Elements();
    void addElements();
    void loadElements(QSvgRenderer* svgRenderer, QGraphicsScene *scene, qreal xReference, qreal yReference);
    void shuffleObjects();
    QPropertyAnimation *getObjectAnimation(const int index);
    void setEnableLauchedObject(int index);

};

#endif // ELEMENTS_H
