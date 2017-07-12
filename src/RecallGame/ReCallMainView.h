#ifndef RECALLMAINVIEW_H
#define RECALLMAINVIEW_H

#include "ReCallMainView.h"
#include "ReCallController.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "Object.h"
#include "PropObject.h"


class Object;
class PropObject;
class ReCallMainView:public QGraphicsView
{
Q_OBJECT
protected:
  PropObject* m_tube;
  PropObject* m_backGround;
  QSvgRenderer* m_svgRenderer;
  QGraphicsTextItem* m_playerScore;
  QString scoreLegend;
  friend class ReCallController;


public:
    ReCallMainView(QGraphicsScene* scene);
    ~ReCallMainView();
    void paintBackGround(QGraphicsScene* scene);
    void initComponents(QGraphicsScene* scene);
    void updateScore(int &newScoreText);
};

#endif // RECALLMAINVIEW_H
