#ifndef PROPOBJECT_H
#define PROPOBJECT_H

#include <QGraphicsSvgItem>
#include <QStringList>
#include <QTimer>
#include <ReCallController.h>


class ReCallController;

/*! class PropObject that is used to construct object that its animation is statict (do not change its position (x,y)) */
class PropObject: public QGraphicsSvgItem
{
Q_OBJECT
protected:
    ReCallController* m_controller;/**< A pointer to the main instance of class ReCallMainController. It is used to connect several methods*/
    QStringList svgs;/**< A QStringList object that stores the QString names of the PropObject`s svgs */
    QTimer *staticAnimationTimer;/**< A pointer to a QTimer object that controls tha "animation" of changing the current sgv rendered */
    int currentSVG;/**< A qreal value that stores that latest y point */
public:
    bool lauchControl; /**< A bool value that control the enable/disable state of lanching objects */
public:
    /**
        @brief Default constructor of this class

        @details
        @todo This initialize and construct a PropObject
        @param name The QString value of the svg element to render
        @param controller Pointer to the main class ReCallController instance
        @return no return value for this method
    */
    PropObject(QString name,ReCallController* controller=Q_NULLPTR);
    /**
        @brief Default destructor of this class

        @details
        @todo This destructs the QTimer object pointed by staticAnimationTimer
        @return no return value for this method
    */
    ~PropObject();
    /**
        @brief setStartPosition

        @details
        @todo this is used to set the startPosition of PropObjects
        @param x Qreal value of point x
        @param y Qreal value of point y
        @return no return value for this method
    */
    void setStartPosition(const qreal x = 0, const qreal y=0);
    /**
        @brief setControllerEvent

        @details
        @todo this is used store the pointer to the main instance of class ReCallController
        @param controller The pointer to the class ReCallController object
        @return no return value for this method
    */
    void setControllerEvent( ReCallController* controller);
    /**
        @brief virtual method mousePressEvent

        @details
        @todo this is used to execute method from ReCallController (using m_controller) when the PropObjectt is mouseclicked
        @param controller The pointer an QGraphicsSceneMouseEvent object
        @return no return value for this method
    */
    void mousePressEvent( QGraphicsSceneMouseEvent * event);
    /**
        @brief addSvgName

        @details
        @todo this add a QString object with the name of a svg element to render
        @param frame const QString object with the value to be stored
        @return no return value for this method
    */
    inline void addSvgName(const QString frame){this->svgs<<frame;}
    /**
        @brief stopStaticAnimations

        @details
        @todo this stops the timer staticAnimationTimer timeOut ant the changing svgs animations
        @return no return value for this method
    */
    void stopStaticAnimations();
    /**
        @brief startStaticAnimations

        @details
        @todo this starts the timer staticAnimationTimer timeOut ant the changing svgs animations
        @return no return value for this method
    */
    void startStaticAnimations(const int duration);

private slots:
    /**
        @brief nextSvgName

        @details
        @todo this private Qt slot it is used to be connect to signal timeOut of staticAnimationTimer for changing current svg id
        @return no return value for this method slot
    */
    void nextSvgName();
};

#endif // PROPOBJECT_H
