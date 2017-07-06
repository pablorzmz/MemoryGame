#ifndef TUBE_H
#define TUBE_H

#include <QtMath>
#include <QGraphicsSvgItem>
#include <QGraphicsScene>
#include <QString>

class Graphic: public QGraphicsSvgItem
{
private:
    QString nombre;

public:
    Graphic(QString nombre);
    ~Graphic();
    void setStartPosition(const qreal x = 0, const qreal y=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};

#endif // TUBE_H
