#ifndef RECALLMAINVIEW_H
#define RECALLMAINVIEW_H

#include "ReCallMainView.h"
#include "ReCallController.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include "Object.h"

class ReCallMainView:public QGraphicsView
{
protected:
  QPushButton* m_starButton;
  Object* m_tube;
  Object* m_backGround;
  QSvgRenderer* m_svgRenderer;
  friend class ReCallController;

public:
    ReCallMainView(QGraphicsScene* scene);
    void paintBackGround(QGraphicsScene* scene);
    void initComponents(QGraphicsScene* scene);
    QPushButton* startButton(){return this->m_starButton;}
};

#endif // RECALLMAINVIEW_H
