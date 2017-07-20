#ifndef TUBE_H
#define TUBE_H

#include "Elements.h"
#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QString>
#include <QPropertyAnimation>


/*! class Object that inherits QGraphicsSvgItem. This class represents an object that is animated to be lanched, touched and hiden during game*/
class Object: public QGraphicsSvgItem
{
    Q_OBJECT
protected:
    QPropertyAnimation *m_animation; /**< Pointer to a QPropertyAnimation that is used to show launching movement from tube*/
    QPropertyAnimation *m_animation2; /**< Pointer to a QPropertyAnimation that is used to show comebacking movement from an avaible point to tube*/
    QString* currentTop; /**< A pointer to a QString object that stores the  current to from class Elements*/
    qreal pastX; /**< A qreal value that stores that latest x point */
    qreal pastY; /**< A qreal value that stores that latest y point */
    friend class Elements;

    /**
        @brief setMeAsCurrentQueueTop void used to change the current top of launching queue

        @details
        @todo This methed change the value pointed for this QString elementId value
        @return no return value for this method
    */
    void setMeAsCurrentQueueTop();

public:
    /**
        @brief Default constructor for class Object

        @details
        @todo This constructs an Object object with the svg name to render
        @param name is a QString object that contains
        @param ElementsCurrentTop a pointer to the class Elements QString pointer
        @return no return value for this method
    */
    Object(QString name, QString *ElementsCurrentTop);
    /**
        @brief Default destructor for class Object
        @details
        @todo This is used to destruct the QPropertyAnimation objects
        @return no return value for this method
    */
    ~Object();
    /**
        @brief setStartPosition method used to move an Object to a specific point of current view
        @details
        @todo This is used to move objects to an inicitial position
        @param x The qreal value of x point
        @param y The qreal value of y point
        @return no return value for this method
    */
    void setStartPosition(const qreal x = 0, const qreal y=0);
    /**
        @brief virtual overread mousePressEvent method used to process the event when a object is mouseclicked
        @details
        @todo This is used to start an animation and move the object to behind the tube
        @param event Pointer to a QGraphicsSceneMouseEvent object that controls this event
        @return no return value for this method
    */
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    /**
        @brief setUpAnimation method used to setUp the behavior of an animation
        @details
        @todo This method setsUp a QPropertyAnimation from the begining point to end point
        @param animationNumber 1 to m_animation or 2 to m_animation2
        @param duration time of animation behavior
        @param finalX final point x of movement
        @param finalY final point y of movement
        @param startX initial point x of movement
        @param startY initial point y of movement
        @return no return value for this method
    */
    void setUpAnimation(const int animationNumber,const int duration, const qreal finalX, const qreal finalY, const qreal startX, const qreal startY);
    /**
        @brief animation function used to return a point to a QPropertyAnimation
        @details
        @todo This function is used to group up sequencial animations in class ReCallController
        @return a pointer to m_animation2
    */
    inline QPropertyAnimation* animation(){return this->m_animation2;}
    /**
        @brief getName function used to return the name of the current svg rendered
        @details
        @return a QString object with the value of fuction elementId()
    */
    inline QString getName() const {return this->elementId();}

};

#endif // TUBE_H
