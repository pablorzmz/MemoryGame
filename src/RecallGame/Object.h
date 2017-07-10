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
    qreal pastX;
    qreal pastY;
    friend class Elements;
public:
    Object(QString nombre);
    ~Object();
    void setStartPosition(const qreal x = 0, const qreal y=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void setAnimation(int duration, const qreal finalX, const qreal finalY, const qreal startX, const qreal startY);
    void starGame(QApplication *controller);

};

#endif // TUBE_H
