#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <algorithm>
#include <chrono>
#include "Object.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <QString>
#include <QSvgRenderer>
#include <QVector>
#include <random>

class Object;
class Elements
{
private:
    QVector<QString> svgNames;
public:
    QVector<Object*> svgElements;
    QString* currenTop;

public:
    /**
        @brief default constructor for class Elements

        @details
        @todo This method initialize the the current top QString pointer.
        @return no return value for this method
    */
    Elements();
    /**
        @brief destructor for class Elements

        @details
        @todo This method destroys the pointer to the current top member
        @return no return value for this method
    */
    ~Elements();
    /**
        @brief addElements.
        This method fills svgNames with the Qstring names of the elements.

        @details
        @todo The name are taken from the svg master asset file pics.svg
        @return no return value for this method
    */
    void addElements();
    /**
        @brief loadElements.
        This method extracts svgs from assets and fills svgElements

        @details
        @todo The svg is taken from assets and setup with a elementId allready extracted from svgNames
        @return no return value for this method
    */
    void loadElements(QSvgRenderer* svgRenderer, QGraphicsScene *scene, qreal xReference, qreal yReference);
    /**
        @brief suffleElements.
        This method suffle svg elements in vector

        @details
        @todo This method allows low percent of repetitions during lauching animations
        @return no return value for this method
    */
    void shuffleElements();
    /**
        @brief getObjectAnimation.
        This method return a pointer to a QPropertyAnimmations from of a specific svg Element

        @details
        @todo This is used to gruop-up animations in a sequencial lanching orden
        @return a no NULL QPpropertyAnimation pointer
    */
    QPropertyAnimation *getObjectAnimation(const int index);
    /**
        @brief setEnableLauchedObject.
        This set enable o disable a specific svg Elements

        @details
        @todo This is used to avoid no controll click action over a svg elements during launching animation
        @return no return value for this method
    */
    void setEnableLauchedObject(const int index);

};

#endif // ELEMENTS_H
