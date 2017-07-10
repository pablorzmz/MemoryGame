#ifndef PROPOBJECT_H
#define PROPOBJECT_H

#include <QGraphicsSvgItem>
#include <ReCallController.h>
class ReCallController;
class PropObject: public QGraphicsSvgItem
{

private:
    ReCallController* m_controller;
public:
    bool lauchControl;
    PropObject(QString nombre,ReCallController* controller=Q_NULLPTR);
    ~PropObject();
    void setStartPosition(const qreal x = 0, const qreal y=0);
    void setControllerEvent(ReCallController* controller);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // PROPOBJECT_H
