#ifndef PROPITEM_H
#define PROPITEM_H


#include <QString>
#include <QStringList>
#include <QTimer>
#include "ReCallController.h"
#include <QObject>

class ReCallController;

class PropItem
{

protected:
    ReCallController* m_controller;/**< A pointer to the main instance of class ReCallMainController. It is used to connect several methods*/
    QStringList svgs;/**< A QStringList object that stores the QString names of the PropObject`s svgs */
    QTimer *staticAnimationTimer;/**< A pointer to a QTimer object that controls tha "animation" of changing the current sgv rendered */
    int currentSVG;/**< A qreal value that stores that latest y point */
public:
    bool lauchControl; /**< A bool value that control the enable/disable state of lanching objects */

public:
    PropItem();
    virtual ~PropItem();
    virtual void setStartPosition(const qreal x = 0, const qreal y=0);
    virtual void setControllerEvent( ReCallController* controller);
    virtual void setUpAnimation(const QStringList parameters);
    virtual inline void addSvgName(const QString frame){this->svgs<<frame;}
    virtual void stopStaticAnimations();

    /*tube
private slots:
    void nextSvgName();
*/
};

#endif // PROPITEM_H
