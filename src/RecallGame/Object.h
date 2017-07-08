#ifndef TUBE_H
#define TUBE_H

#include <QtMath>
#include <QGraphicsSvgItem>
#include <QGraphicsScene>
#include <QString>

class Object: public QGraphicsSvgItem
{
private:
    QString nombre;

public:
    Object(QString nombre);
    ~Object();
    void setStartPosition(const qreal x = 0, const qreal y=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};

#endif // TUBE_H
