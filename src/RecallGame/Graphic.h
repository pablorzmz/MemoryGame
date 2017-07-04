#ifndef TUBE_H
#define TUBE_H

#include <QtMath>
#include <QGraphicsSvgItem>
#include <QGraphicsScene>

class Graphic: public QGraphicsSvgItem
{
public:
    Graphic();
    ~Graphic();
    void setStartPosition();
};

#endif // TUBE_H
