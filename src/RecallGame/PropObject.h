#ifndef PROPOBJECT_H
#define PROPOBJECT_H

#include <QGraphicsSvgItem>
#include <QStringList>
#include <QTimer>
#include <ReCallController.h>


class ReCallController;
class PropObject: public QGraphicsSvgItem
{
Q_OBJECT
private:
    ReCallController* m_controller;
    QStringList svgs;
    QTimer *staticAnimationTimer;
    int currentSVG;

public:
    PropObject(QString nombre,ReCallController* controller=Q_NULLPTR);
    bool lauchControl;
    ~PropObject();
    void setStartPosition(const qreal x = 0, const qreal y=0);
    void setControllerEvent( ReCallController* controller);
    void mousePressEvent( QGraphicsSceneMouseEvent * event);
    inline void addSvgName(QString frame){this->svgs<<frame;}
    void stopStaticAnimations();
    void startStaticAnimations(const int duration);

private slots:
    void nextSvgName();
};

#endif // PROPOBJECT_H
