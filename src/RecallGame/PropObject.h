#ifndef PROPOBJECT_H
#define PROPOBJECT_H

#include <QGraphicsSvgItem>
#include <ReCallController.h>
#include <QStringList>
#include <QTimer>

class ReCallController;
class PropObject: public QGraphicsSvgItem
{
Q_OBJECT
private:
    ReCallController* m_controller;
    QStringList svgs;
public:
    QTimer *staticAnimationTimer;
    int currentSVG;

public:
    bool lauchControl;
    PropObject(QString nombre,ReCallController* controller=Q_NULLPTR);
    ~PropObject();
    void setStartPosition(const qreal x = 0, const qreal y=0);
    void setControllerEvent( ReCallController* controller);
    void mousePressEvent( QGraphicsSceneMouseEvent * event);
    inline void addSvgName(QString frame){this->svgs<<frame;}

private slots:
    void nextSvgName();
};

#endif // PROPOBJECT_H
