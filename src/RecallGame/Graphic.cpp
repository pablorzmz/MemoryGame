#include "Graphic.h"

Graphic::Graphic()
{

}

Graphic::~Graphic()
{
}

void Graphic::setStartPosition()
{
        // Place the player in the middle bottom of the scene
        qreal x = (scene()->width() - boundingRect().width()) * 0.5;
        qreal y = (scene()->height() - boundingRect().height());
        setPos(x, y);
}
