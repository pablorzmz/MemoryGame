#ifndef TUBE_H
#define TUBE_H

#include "Elements.h"
#include <QGraphicsSvgItem>
#include <QGraphicsScene>
#include <QString>
#include <QPropertyAnimation>

class Object: public QGraphicsSvgItem
{



private:
    QPropertyAnimation *m_animation;
    QPropertyAnimation *m_animation2;
    QString* currentTop;
    qreal pastX;
    qreal pastY;
    friend class Elements;
    void setMeAsCurrentQueueTop();
public:
    Object(QString nombre, QString *ElementsCurrentTop);
    ~Object();
    void setStartPosition(const qreal x = 0, const qreal y=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void setAnimation(int animationNumber,int duration, const qreal finalX, const qreal finalY, const qreal startX, const qreal startY);
    void starGame(QApplication *controller);
    inline QPropertyAnimation* animation(){return this->m_animation2;}
    inline QString getName(){return this->elementId();}

};

#endif // TUBE_H
